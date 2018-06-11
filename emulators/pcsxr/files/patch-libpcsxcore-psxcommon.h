--- libpcsxcore/psxcommon.h.orig	2018-06-07 22:26:55.136610000 +0200
+++ libpcsxcore/psxcommon.h	2018-06-07 22:27:17.357957000 +0200
@@ -71,7 +71,7 @@
 #include "system.h"
 #include "debug.h"
 
-#if defined (__linux__) || defined (__MACOSX__)
+#if defined (__linux__) || defined (__MACOSX__) || defined (__FreeBSD__)
 #define strnicmp strncasecmp
 #endif
 #define __inline inline
