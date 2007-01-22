$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/os_bsd.cpp.orig	Tue Jan 27 17:54:28 2004
+++ ../../hotspot/src/os/bsd/vm/os_bsd.cpp	Tue Jan 27 17:55:21 2004
@@ -333,7 +333,7 @@
 #define malloc(n) (char*)NEW_C_HEAP_ARRAY(char, (n))
 #define getenv(n) ::getenv(n)
 
-#define DEFAULT_LD_LIBRARY_PATH "/usr/lib" /* See ld.so.1(1) */
+#define DEFAULT_LD_LIBRARY_PATH "/usr/lib:%%LOCALBASE%%/lib" /* See ld.so.1(1) */
 #define EXTENSIONS_DIR "/lib/ext"
 #define ENDORSED_DIR "/lib/endorsed"
 
