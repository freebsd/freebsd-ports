--- plugins/examples/file.cpp.orig	Fri Mar 26 10:13:48 2004
+++ plugins/examples/file.cpp	Fri Mar 26 10:13:52 2004
@@ -73,7 +73,7 @@
 
 
 #ifdef OLDGCCVARMACRO
-#define fprintf(x,args...) {message(##args);erefresh();}
+#define fprintf(x,args...) {message(args);erefresh();}
 #else
 #define fprintf(x,...) {message(__VA_ARGS__);erefresh();}
 #endif
