--- src/include/global.h.orig	2004-07-16 01:59:53 UTC
+++ src/include/global.h
@@ -204,7 +204,7 @@
 #define INTSML            short				/* at least 16 bits */
 #define UINTSML  unsigned short
 #define INTHUGE    int64_t					/* at least 64 bits */
-#define UINTHUGE u_int64_t
+#define UINTHUGE uint64_t
 #define SIZEOFCHAR    (sizeof (CHAR))		/* bytes per character */
 #define SIZEOFINTSML  (sizeof (INTSML))		/* bytes per short integer */
 #define SIZEOFINTBIG  (sizeof (INTBIG))		/* bytes per long integer */
