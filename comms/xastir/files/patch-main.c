--- src/main.c~	Sun Jul  9 16:46:31 2006
+++ src/main.c	Sun Jul  9 18:04:42 2006
@@ -10284,7 +10284,7 @@
     // acceptable at 200.
     nexttime = 200;
 #else
-    nexttime = 2;
+    nexttime = 10;
 #endif // __CYGWIN__
 
 
