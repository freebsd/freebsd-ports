--- src/wzd_types.h.orig	Sat Jul 16 23:12:40 2005
+++ src/wzd_types.h	Sat Jul 16 23:13:32 2005
@@ -359,21 +359,19 @@
 /* definitions for windows 2000 */
 #if defined(_MSC_VER) && defined(WINVER) && (WINVER < 0x0501)
 #define in6_addr in_addr6 /* funny ! */
-
 #define socklen_t	unsigned int
-
-#ifndef IN6_IS_ADDR_V4MAPPED
-#define IN6_IS_ADDR_V4MAPPED(a) \
-	((((const ULONG *)(a))[0] == 0) \
-	&& (((const ULONG *)(a))[1] == 0) \
-	&& (((const ULONG *)(a))[2] == htonl (0xffff)))
-#endif
 #endif /* WINVER */
 
 #ifndef INADDR_NONE
 # define INADDR_NONE ((unsigned long int) 0xffffffff)
 #endif
 
+#ifndef IN6_IS_ADDR_V4MAPPED
+#define IN6_IS_ADDR_V4MAPPED(a) \
+	((((const ULONG *)(a))[0] == 0) \
+	&& (((const ULONG *)(a))[1] == 0) \
+	&& (((const ULONG *)(a))[2] == htonl (0xffff)))
+#endif /* IN6_IS_ADDR_V4MAPPED */
 
 #ifndef MAX
 #define MAX(x,y) ((x) > (y) ? (x) : (y))
