--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2014-10-06 17:10:00.000000000 -0400
+++ hotspot/src/os/bsd/vm/os_bsd.cpp	2014-10-08 10:23:14.000000000 -0400
@@ -458,7 +458,7 @@
  *        7: The default directories, normally /lib and /usr/lib.
  */
 #ifndef DEFAULT_LIBPATH
-#define DEFAULT_LIBPATH "/lib:/usr/lib:/usr/local/lib"
+#define DEFAULT_LIBPATH "/lib:/usr/lib:%%LOCALBASE%%/lib"
 #endif
 
 #define EXTENSIONS_DIR  "/lib/ext"
