--- Modules/gcmodule.c.orig	Fri Apr 18 02:29:21 2003
+++ Modules/gcmodule.c	Fri Nov 21 11:39:52 2003
@@ -377,13 +377,17 @@
 		return 0;
 }
 
-/* Move the objects in unreachable with __del__ methods into finalizers.
- * The objects remaining in unreachable do not have __del__ methods, and
- * gc_refs remains GC_TENTATIVELY_UNREACHABLE for them.  The objects
- * moved into finalizers have gc_refs changed to GC_REACHABLE.
+/* Move the objects in unreachable with __del__ methods into finalizers,
+ * and weakrefs with callbacks into wr_callbacks.
+ * The objects remaining in unreachable do not have __del__ methods, and are
+ * not weakrefs with callbacks.
+ * The objects moved have gc_refs changed to GC_REACHABLE; the objects
+ * remaining in unreachable are left at GC_TENTATIVELY_UNREACHABLE.
  */
 static void
-move_finalizers(PyGC_Head *unreachable, PyGC_Head *finalizers)
+move_troublemakers(PyGC_Head *unreachable,
+		   PyGC_Head *finalizers,
+		   PyGC_Head *wr_callbacks)
 {
 	PyGC_Head *gc = unreachable->gc.gc_next;
 
@@ -398,6 +402,12 @@
 			gc_list_append(gc, finalizers);
 			gc->gc.gc_refs = GC_REACHABLE;
 		}
+		else if (PyWeakref_Check(op) &&
+			 ((PyWeakReference *)op)->wr_callback) {
+			gc_list_remove(gc);
+			gc_list_append(gc, wr_callbacks);
+			gc->gc.gc_refs = GC_REACHABLE;
+		}
 		gc = next;
 	}
 }
@@ -434,6 +444,93 @@
 	}
 }
 
+/* Clear all trash weakrefs with callbacks.  This clears weakrefs first,
+ * which has the happy result of disabling the callbacks without executing
+ * them.  A nasty technical complication:  a weakref callback can itself be
+ * the target of a weakref, in which case decrefing the callback can cause
+ * another callback to trigger.  But we can't allow arbitrary Python code to
+ * get executed at this point (the callback on the callback may try to muck
+ * with other cyclic trash we're trying to collect, even resurrecting it
+ * while we're in the middle of doing tp_clear() on the trash).
+ *
+ * The private _PyWeakref_ClearRef() function exists so that we can clear
+ * the reference in a weakref without triggering a callback on the callback.
+ *
+ * We have to save the callback objects and decref them later.  But we can't
+ * allocate new memory to save them (if we can't get new memory, we're dead).
+ * So we grab a new reference on the clear'ed weakref, which prevents the
+ * rest of gc from reclaiming it.  _PyWeakref_ClearRef() leaves the
+ * weakref's wr_callback member intact.
+ *
+ * In the end, then, wr_callbacks consists of cleared weakrefs that are
+ * immune from collection.  Near the end of gc, after collecting all the
+ * cyclic trash, we call release_weakrefs().  That releases our references
+ * to the cleared weakrefs, which in turn may trigger callbacks on their
+ * callbacks.
+ */
+static void
+clear_weakrefs(PyGC_Head *wr_callbacks)
+{
+	PyGC_Head *gc = wr_callbacks->gc.gc_next;
+
+	for (; gc != wr_callbacks; gc = gc->gc.gc_next) {
+		PyObject *op = FROM_GC(gc);
+		PyWeakReference *wr;
+
+		assert(IS_REACHABLE(op));
+		assert(PyWeakref_Check(op));
+		wr = (PyWeakReference *)op;
+		assert(wr->wr_callback != NULL);
+		Py_INCREF(op);
+		_PyWeakref_ClearRef(wr);
+	}
+}
+
+/* Called near the end of gc.  This gives up the references we own to
+ * cleared weakrefs, allowing them to get collected, and in turn decref'ing
+ * their callbacks.
+ *
+ * If a callback object is itself the target of a weakref callback,
+ * decref'ing the callback object may trigger that other callback.  If
+ * that other callback was part of the cyclic trash in this generation,
+ * that won't happen, since we cleared *all* trash-weakref callbacks near
+ * the start of gc.  If that other callback was not part of the cyclic trash
+ * in this generation, then it acted like an external root to this round
+ * of gc, so all the objects reachable from that callback are still alive.
+ *
+ * Giving up the references to the weakref objects will probably make
+ * them go away too.  However, if a weakref is reachable from finalizers,
+ * it won't go away.  We move it to the old generation then.  Since a
+ * weakref object doesn't have a finalizer, that's the right thing to do (it
+ * doesn't belong in gc.garbage).
+ *
+ * We return the number of weakref objects freed (those not appended to old).
+ */
+static int
+release_weakrefs(PyGC_Head *wr_callbacks, PyGC_Head *old)
+{
+	int num_freed = 0;
+
+	while (! gc_list_is_empty(wr_callbacks)) {
+		PyGC_Head *gc = wr_callbacks->gc.gc_next;
+		PyObject *op = FROM_GC(gc);
+		PyWeakReference *wr = (PyWeakReference *)op;
+
+		assert(IS_REACHABLE(op));
+		assert(PyWeakref_Check(op));
+		assert(wr->wr_callback != NULL);
+		Py_DECREF(op);
+		if (wr_callbacks->gc.gc_next == gc) {
+			/* object is still alive -- move it */
+			gc_list_remove(gc);
+			gc_list_append(gc, old);
+		}
+		else
+			++num_freed;
+	}
+	return num_freed;
+}
+
 static void
 debug_instance(char *msg, PyInstanceObject *inst)
 {
@@ -535,8 +632,9 @@
 	long n = 0;	/* # unreachable objects that couldn't be collected */
 	PyGC_Head *young; /* the generation we are examining */
 	PyGC_Head *old; /* next older generation */
-	PyGC_Head unreachable;
-	PyGC_Head finalizers;
+	PyGC_Head unreachable; /* non-problematic unreachable trash */
+	PyGC_Head finalizers;  /* objects with, & reachable from, __del__ */
+	PyGC_Head wr_callbacks;  /* weakrefs with callbacks */
 	PyGC_Head *gc;
 
 	if (delstr == NULL) {
@@ -597,20 +695,33 @@
 	/* All objects in unreachable are trash, but objects reachable from
 	 * finalizers can't safely be deleted.  Python programmers should take
 	 * care not to create such things.  For Python, finalizers means
-	 * instance objects with __del__ methods.
+	 * instance objects with __del__ methods.  Weakrefs with callbacks
+	 * can call arbitrary Python code, so those are special-cased too.
 	 *
-	 * Move unreachable objects with finalizers into a different list.
+	 * Move unreachable objects with finalizers, and weakrefs with
+	 * callbacks, into different lists.
  	 */
 	gc_list_init(&finalizers);
-	move_finalizers(&unreachable, &finalizers);
+	gc_list_init(&wr_callbacks);
+	move_troublemakers(&unreachable, &finalizers, &wr_callbacks);
+	/* Clear the trash weakrefs with callbacks.  This prevents their
+	 * callbacks from getting invoked (when a weakref goes away, so does
+	 * its callback).
+	 * We do this even if the weakrefs are reachable from finalizers.
+	 * If we didn't, breaking cycles in unreachable later could trigger
+	 * deallocation of objects in finalizers, which could in turn
+	 * cause callbacks to trigger.  This may not be ideal behavior.
+	 */
+	clear_weakrefs(&wr_callbacks);
 	/* finalizers contains the unreachable objects with a finalizer;
-	 * unreachable objects reachable only *from* those are also
-	 * uncollectable, and we move those into the finalizers list too.
+	 * unreachable objects reachable *from* those are also uncollectable,
+	 * and we move those into the finalizers list too.
 	 */
 	move_finalizer_reachable(&finalizers);
 
 	/* Collect statistics on collectable objects found and print
-	 * debugging information. */
+	 * debugging information.
+	 */
 	for (gc = unreachable.gc.gc_next; gc != &unreachable;
 			gc = gc->gc.gc_next) {
 		m++;
@@ -623,6 +734,11 @@
 	 * in finalizers to be freed.
 	 */
 	delete_garbage(&unreachable, old);
+
+        /* Now that we're done analyzing stuff and breaking cycles, let
+         * delayed weakref callbacks run.
+         */
+	m += release_weakrefs(&wr_callbacks, old);
 
 	/* Collect statistics on uncollectable objects found and print
 	 * debugging information. */
