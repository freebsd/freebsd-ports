
$FreeBSD$

--- pal/unix/include/pal/palinternal.h	2002/03/28 19:47:01	1.1
+++ pal/unix/include/pal/palinternal.h	2002/03/28 19:53:39
@@ -277,6 +277,7 @@
 #define u_short PAL_u_short
 #define u_int PAL_u_int
 #define u_long PAL_u_long
+#define in_addr PAL_in_addr
 
 #define wchar_t wchar_16
 #define SOCKET PAL_SOCKET
@@ -385,6 +386,7 @@
 #undef u_short
 #undef u_int
 #undef u_long
+#undef in_addr
 
 
 #undef printf
