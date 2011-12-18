--- source/mupen64plus-core/src/main/zip/ioapi.h	2011-12-17 21:07:15.000000000 -0500
+++ source/mupen64plus-core/src/main/zip/ioapi.h	2011-12-17 21:08:43.000000000 -0500
@@ -61,6 +61,12 @@
 #endif
 #endif
 
+#if defined(__FreeBSD__)
+#define fopen64 fopen
+#define ftello64 ftello
+#define fseeko64 fseeko
+#endif
+
 /*
 #ifndef ZPOS64_T
   #ifdef _WIN32
