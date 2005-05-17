--- config.h.orig	Wed Sep  3 08:50:18 2003
+++ config.h	Mon May 16 14:16:20 2005
@@ -2,19 +2,19 @@
  * Configuration for SKKFEP
  */
 
-#include "configs/linux.h"
+#include "configs/freebsd.h"
 
 #if makefile_parameter
-CC=gcc
+#CC=gcc
 DEFINE=-DUSE_LOCALE
-OPTIMIZE=-g
+#OPTIMIZE=-g
 EXTRALIBS=
 #endif
 
 #define DEFAULT_KANAKEY "^j"
 
 /* By Y. Kaneko */
-/*#define KUTOUTEN        /* "."->maru, ","->ten */
+#define KUTOUTEN        /* "."->maru, ","->ten */
 
 #define KANJIBS			/* do/don't shuft-out BS code in JIS mode */
 #define KANJIBS_DEFAULT	0	/* 0 -> shift out / 1 -> don't shift out  */
@@ -28,4 +28,4 @@
 
 #define NATIVECODE	euc	/* EUC Kanji code */
 
-#define SKK_SERVER_HOST	"ei5nazha"	/* SKK server host */
+#define SKK_SERVER_HOST	"localhost"	/* SKK server host */
