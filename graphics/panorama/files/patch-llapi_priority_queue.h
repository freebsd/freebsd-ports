--- llapi/priority_queue.h.orig	Sat Aug 21 19:37:55 1999
+++ llapi/priority_queue.h	Tue Feb  1 17:49:59 2005
@@ -194,17 +194,18 @@
 void TPriorityQueue<TItem>::printDebug (void) const
 {
 
-  cerr << TDebug::indent() << "[_TPriorityQueue_]" << endl;
+  cerr << TDebug::_indent() << "[_TPriorityQueue_]" << endl;
                  
-  TDebug::push();
+  TDebug::_push();
 
   for (size_t J = 1; ( J <= zSize ) ;J++)
   {
+    string tString;
     tString << atData[J] + ", " << afPriority[J];
-    cerr << TDebug::indent() << tString << endl;
+    cerr << TDebug::_indent() << tString << endl;
   }
 
-  TDebug::pop();
+  TDebug::_pop();
   
 }  /* printDebug() */
 
