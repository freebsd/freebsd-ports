--- lib/include/guest_os.h.orig	2017-07-28 21:59:15 UTC
+++ lib/include/guest_os.h
@@ -493,7 +493,8 @@ Bool Gos_InSetArray(uint32 gos, const uint32 *set);
 #define STR_OS_WIN_64_BIT_EXTENSION ", 64-bit"
 
 /* FreeBSD */
-#define STR_OS_FREEBSD "freeBSD"
+#define STR_OS_FREEBSD   "freeBSD"
+#define STR_OS_FREEBSD11 "freeBSD11"
 
 /* Solaris */
 #define STR_OS_SOLARIS "solaris"
