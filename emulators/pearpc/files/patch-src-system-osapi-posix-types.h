--- src/system/osapi/posix/types.h.orig	2011-04-25 13:24:02.000000000 +0400
+++ src/system/osapi/posix/types.h	2011-04-25 13:24:05.000000000 +0400
@@ -46,13 +46,13 @@
 /* FreeBSD versions after importing gcc34 has broken offsetof() */
 #ifdef __FreeBSD__
 #include <sys/param.h>
-#if __FreeBSD_version >= 502126
+#if (__FreeBSD_version >= 502126) && (__FreeBSD_version < 700042)
 #undef offsetof
 #define offsetof(TYPE, MEMBER)					\
 	(__offsetof__ (reinterpret_cast <size_t>		\
 		(&reinterpret_cast <const volatile char &>     	\
 		(static_cast<TYPE *> (0)->MEMBER))))
-#endif /* __FreeBSD_version >= 502126 */
+#endif /* (__FreeBSD_version >= 502126) && (__FreeBSD_version < 700042) */
 #endif /* __FreeBSD__ */
 
 #endif
