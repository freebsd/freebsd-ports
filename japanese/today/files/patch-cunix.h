--- cunix.h.orig	2015-11-23 17:47:06.000000000 +0900
+++ cunix.h	2015-11-23 17:49:27.000000000 +0900
@@ -29,6 +29,10 @@
 #include <termcap.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
+
 #define _T_EUC	/* EUC 漢字コード */
 
 #define _T_MAXROWS			24				/* 画面行数 */
@@ -40,7 +44,9 @@
 #define _T_TMPENV			"TEMP"			/* temporary 環境変数名 */
 #define _T_TMPENV2			"TMPDIR"		/* temporary 環境変数名 */
 #define _T_TMPDIR			"/tmp"			/* temporary directory */
+#if 0
 #define _T_SEARCH_DEFPATHS	"/usr/local/lib/today:/opt/local/lib/today:/usr/local/share/today:/opt/local/share/today:/usr/lib/today:/opt/lib/today:/usr/share/today:/opt/share/today:/usr/local/lib:/opt/local/lib:/usr/lib:/opt/lib"
+#endif
 											/* default search path list */
 #define _T_HOMEENV			"HOME"			/* home 環境変数 */
 #define _T_PATHENV			"PATH"			/* path 環境変数名 */
@@ -50,6 +56,15 @@
 											/* path name of executed command */
 #define _T_EXECCMDPATH		"ExecCmdPath"	/* $ExecCmdPath => search_cmdpath */
 #define _T_OPENFLAG			(O_RDONLY)
+#if defined(__FreeBSD__)
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#define _T_LITTLE_ENDIAN
+#define _T_LITTLE_ENDIAN_BITFIELD
+#else
+#define _T_BIG_ENDIAN
+#define _T_BIG_ENDIAN_BITFIELD
+#endif
+#else
 #if defined(i386)
 #define _T_LITTLE_ENDIAN
 #define _T_LITTLE_ENDIAN_BITFIELD
@@ -57,10 +72,11 @@
 #define _T_BIG_ENDIAN
 #define _T_BIG_ENDIAN_BITFIELD
 #endif
+#endif
 #define _T_OUTFILE_DEFAULT	"%c%y%m%d.today"
 #define _T_OUTFILE_TMPNAME	"%p.today"
 
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #define _T_ACCESS_ROK		R_OK
 #define _T_HAVE_STRTOK_R
 #define stricmp(a,b)		strcasecmp(a,b)
