--- cake/files.h.orig	Sat Jul 17 00:32:30 2004
+++ cake/files.h	Sat Jul 17 00:26:42 2004
@@ -13,6 +13,7 @@
 	#include <io.h>
 #else
 	#include <dirent.h>
+	#include <time.h>
 
 	/**
 	 * Following stuff was taken from io.h
@@ -20,11 +21,6 @@
 	#ifndef _FSIZE_T_DEFINED
 		typedef unsigned long _fsize_t; /**< Could be 64 bits for Win32 */
 		#define _FSIZE_T_DEFINED
-	#endif
-
-	#ifndef _TIME_T_DEFINED
-		typedef long time_t;            /**< time value */
-		#define _TIME_T_DEFINED         /**< avoid multiple def's of time_t */
 	#endif
 
 	struct _finddata_t
