--- utils/acc/token.c.orig
+++ utils/acc/token.c
@@ -10,7 +10,7 @@
 #ifdef __NeXT__
 #include <libc.h>
 #else
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 #include <io.h>
 #endif
 #include <fcntl.h>
