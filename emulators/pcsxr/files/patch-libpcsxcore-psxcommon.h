--- libpcsxcore/psxcommon.h.orig	2020-09-07 22:26:22 UTC
+++ libpcsxcore/psxcommon.h
@@ -71,7 +71,7 @@ typedef uint8_t boolean;
 #include "system.h"
 #include "debug.h"
 
-#if defined (__linux__) || defined (__MACOSX__)
+#if defined (__linux__) || defined (__MACOSX__) || defined (__FreeBSD__)
 #define strnicmp strncasecmp
 #endif
 #define __inline inline
