--- aqsis/aqsis.cpp.orig	Mon Apr 12 13:45:33 2004
+++ aqsis/aqsis.cpp	Mon Apr 12 13:46:02 2004
@@ -113,8 +113,8 @@
         return ;
     }
 
-    static long tick = 0;
-    long now;
+    static time_t tick = 0;
+    time_t now;
 
     if ( tick == 0 )
         time( &tick );
