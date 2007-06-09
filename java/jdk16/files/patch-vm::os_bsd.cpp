$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/os_bsd.cpp	Sun Jun  3 18:46:31 2007
+++ ../../hotspot/src/os/bsd/vm/os_bsd.cpp.orig	Sun Jun  3 18:47:28 2007
@@ -499,7 +499,7 @@
 #define getenv(n) ::getenv(n)
 
 #ifndef DEFAULT_LD_LIBRARY_PATH
-#define DEFAULT_LD_LIBRARY_PATH "/usr/lib" /* See ld.so.1(1) */
+#define DEFAULT_LD_LIBRARY_PATH "/usr/lib:%%LOCALBASE%%/lib" /* See ld.so.1(1) */
 #endif
 #define EXTENSIONS_DIR "/lib/ext"
 #define ENDORSED_DIR "/lib/endorsed"
