diff -u python/dist/src/Objects/weakrefobject.c:1.13.6.1 python/dist/src/Objects/weakrefobject.c:1.13.6.3
--- Objects/weakrefobject.c:1.13.6.1	Thu Nov 20 14:13:51 2003
+++ Objects/weakrefobject.c	Wed Feb  4 15:13:43 2004
@@ -624,20 +624,29 @@
     }
     list = GET_WEAKREFS_LISTPTR(ob);
     get_basic_refs(*list, &ref, &proxy);
-    if (callback == NULL || callback == Py_None)
+    if (callback == Py_None)
+        callback = NULL;
+    if (callback == NULL)
         /* return existing weak reference if it exists */
         result = ref;
     if (result != NULL)
-        Py_XINCREF(result);
+        Py_INCREF(result);
     else {
+        /* Note: new_weakref() can trigger cyclic GC, so the weakref
+           list on ob can be mutated.  This means that the ref and
+           proxy pointers we got back earlier may have been collected,
+           so we need to compute these values again before we use
+           them. */
         result = new_weakref(ob, callback);
         if (result != NULL) {
             if (callback == NULL) {
                 insert_head(result, list);
             }
             else {
-                PyWeakReference *prev = (proxy == NULL) ? ref : proxy;
+                PyWeakReference *prev;
 
+                get_basic_refs(*list, &ref, &proxy);
+                prev = (proxy == NULL) ? ref : proxy;
                 if (prev == NULL)
                     insert_head(result, list);
                 else
@@ -664,12 +673,19 @@
     }
     list = GET_WEAKREFS_LISTPTR(ob);
     get_basic_refs(*list, &ref, &proxy);
+    if (callback == Py_None)
+        callback = NULL;
     if (callback == NULL)
         /* attempt to return an existing weak reference if it exists */
         result = proxy;
     if (result != NULL)
-        Py_XINCREF(result);
+        Py_INCREF(result);
     else {
+        /* Note: new_weakref() can trigger cyclic GC, so the weakref
+           list on ob can be mutated.  This means that the ref and
+           proxy pointers we got back earlier may have been collected,
+           so we need to compute these values again before we use
+           them. */
         result = new_weakref(ob, callback);
         if (result != NULL) {
             PyWeakReference *prev;
@@ -678,6 +694,7 @@
                 result->ob_type = &_PyWeakref_CallableProxyType;
             else
                 result->ob_type = &_PyWeakref_ProxyType;
+            get_basic_refs(*list, &ref, &proxy);
             if (callback == NULL)
                 prev = ref;
             else
