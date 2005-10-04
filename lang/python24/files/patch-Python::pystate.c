===================================================================
RCS file: /cvsroot/python/python/dist/src/Python/pystate.c,v
retrieving revision 2.38.2.3
retrieving revision 2.38.2.4
diff -u -r2.38.2.3 -r2.38.2.4
--- Python/pystate.c	2005/09/23 08:14:40	2.38.2.3
+++ Python/pystate.c	2005/09/30 08:17:40	2.38.2.4
@@ -53,7 +53,9 @@
 PyThreadState *_PyThreadState_Current = NULL;
 PyThreadFrameGetter _PyThreadState_GetFrame = NULL;
 
+#ifdef WITH_THREAD
 static void _PyGILState_NoteThreadState(PyThreadState* tstate);
+#endif
 
 
 PyInterpreterState *
@@ -188,7 +190,9 @@
 		tstate->c_profileobj = NULL;
 		tstate->c_traceobj = NULL;
 
+#ifdef WITH_THREAD
 		_PyGILState_NoteThreadState(tstate);
+#endif
 
 		HEAD_LOCK();
 		tstate->next = interp->tstate_head;
