--- src/SMESH_I/SMESH_Mesh_i.cxx.orig	2009-06-08 14:48:05.000000000 +0700
+++ src/SMESH_I/SMESH_Mesh_i.cxx	2009-06-08 14:49:45.000000000 +0700
@@ -73,6 +73,10 @@
 #include <sstream>
 #include <sys/stat.h>
 
+#ifdef __freebsd__
+#define stat64 stat
+#endif
+
 #ifdef _DEBUG_
 static int MYDEBUG = 0;
 #else
