--- delta/newFrontend/xdrawsub.c.orig	Fri May 17 14:12:26 2002
+++ delta/newFrontend/xdrawsub.c	Tue May 28 18:50:06 2002
@@ -3,7 +3,12 @@
  * グラフィックコンテキストのロード・解放処理
  * テキスト文字サイズ取得処理
  */
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <errno.h>
 #include <ctype.h>
 #include <string.h>
@@ -770,6 +775,7 @@
 int FXDefaultIOError( display )
     Display	*display;
 {
+#ifndef __FreeBSD__
 #ifdef linux
 #if MKLINUX || LIBC6
     extern const char *const sys_errlist[];
@@ -784,6 +790,7 @@
 #endif
 #endif
     extern int sys_nerr;
+#endif
     char *SysErrorMsg;
     SysErrorMsg = (errno >= 0 && errno < sys_nerr) ?
 			(char *)sys_errlist[errno] : (char *)"unknown error";
