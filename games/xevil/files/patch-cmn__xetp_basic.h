--- cmn/xetp_basic.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/xetp_basic.h	2012-05-27 06:53:11.000000000 +0900
@@ -52,7 +52,7 @@
   // All values are big-endian
   enum {HEADER_LENGTH = 3};  // 8
   enum {VERSION_LENGTH = 8};  // streams.h depends on this value.
-  static char *versionStr;
+  static const char *versionStr;
 
   // The ':' syntax gives the size in bytes of each component.  :String means
   // use Utils::string_read(), Utils::string_write(), etc.
