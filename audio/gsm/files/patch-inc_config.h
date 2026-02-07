--- inc/config.h.orig	2006-04-26 19:14:26 UTC
+++ inc/config.h
@@ -28,8 +28,8 @@
 /*efine	HAS_STRINGS_H	1		/* /usr/include/strings.h 	*/
 
 #define	HAS_UNISTD_H	1		/* /usr/include/unistd.h	*/
-#define	HAS_UTIME	1		/* POSIX utime(path, times)	*/
-/*efine	HAS_UTIMES	1		/* use utimes()	syscall instead	*/
+/*efine HAS_UTIME       1               /* POSIX utime(path, times)     */
+#define	HAS_UTIMES	1		/* use utimes()	syscall instead	*/
 #define	HAS_UTIME_H	1		/* UTIME header file		*/
 #define	HAS_UTIMBUF	1		/* struct utimbuf		*/
 /*efine	HAS_UTIMEUSEC   1		/* microseconds in utimbuf?	*/
