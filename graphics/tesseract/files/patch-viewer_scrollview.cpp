--- viewer/scrollview.cpp.orig	2009-09-11 08:24:19.000000000 -0400
+++ viewer/scrollview.cpp	2009-09-11 08:32:47.000000000 -0400
@@ -416,6 +416,7 @@
   SVEvent* ret = waiting_for_events[ea].second;
   waiting_for_events.erase(ea);
   mutex_waiting->Unlock();
+  delete sem;
   return ret;
 }
 
@@ -436,6 +437,7 @@
   SVEvent* ret = waiting_for_events[ea].second;
   waiting_for_events.erase(ea);
   mutex_waiting->Unlock();
+  delete sem;
   return ret;
 }
 
@@ -822,4 +824,4 @@
 }
 
 
-#endif  // GRAPHICS_DISABLED
\ No newline at end of file
+#endif  // GRAPHICS_DISABLED
