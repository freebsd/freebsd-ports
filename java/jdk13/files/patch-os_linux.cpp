$FreeBSD$

--- ../../hotspot1.3.1/src/os/linux/vm/os_linux.cpp.orig	Tue Jan 20 10:49:50 2004
+++ ../../hotspot1.3.1/src/os/linux/vm/os_linux.cpp	Tue Jan 20 10:50:14 2004
@@ -319,7 +319,7 @@
 #define SUNRSASIGN_JAR "/lib/sunrsasign.jar"
 #define CLASSES_DIR    "/classes"
 #define EXTENSIONS_DIR "/lib/ext"
-#define DEFAULT_LD_LIBRARY_PATH "/usr/lib" /* See ld.so.1(1) */
+#define DEFAULT_LD_LIBRARY_PATH "/usr/lib:%%LOCALBASE%%/lib" /* See ld.so.1(1) */
 
   char *v; /* tmp var */
   {
