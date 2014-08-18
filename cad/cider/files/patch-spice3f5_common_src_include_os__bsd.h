--- spice3f5/common/src/include/os_bsd.h.orig	1994-01-29 19:14:37 UTC
+++ spice3f5/common/src/include/os_bsd.h
@@ -6,20 +6,40 @@ Copyright 1990 Regents of the University
  *	BSD and derivative systems
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "os_unix.h"
 
+#if !(defined(BSD) && (BSD >= 199306))
 #define HAS_NO_ATRIGH_DECL	/* if asinh( ) is not in math.h		*/
-#define HAS_ATRIGH		/* acosh( ), asinh( ), atanh( )         */
 #define HAS_FTIME		/* ftime( ), <times.h>			*/
+#define HAS_INDEX		/* index( ) instead of strchr( )	*/
+#define HAS_STRINGS		/* use <strings.h> instead of <string.h> */
+#endif
+
+#define HAS_ATRIGH		/* acosh( ), asinh( ), atanh( )         */
 #define HAS_TERMCAP		/* tgetxxx( )				*/
 #define HAS_VFORK		/* BSD-ism, should not be necessary	*/
-#define HAS_INDEX		/* index( ) instead of strchr( )	*/
 #define HAS_BCOPY		/* bcopy( ), bzero( )			*/
 #define HAS_BSDRANDOM		/* srandom( ) and random( )		*/
+#ifdef __FreeBSD__
+#define HAS_POSIXTTY		/* <termios.h>				*/
+#else
 #define HAS_BSDTTY		/* <sgtty.h>				*/
+#endif
 #define HAS_BSDDIRS		/* <sys/dir.h>				*/
 #define HAS_BSDRUSAGE		/* getrusage( )				*/
 #define HAS_BSDRLIMIT		/* getrlimit( )				*/
 #define HAS_DUP2
 #define HAS_GETWD		/* getwd(buf)				*/
-#define HAS_STRINGS		/* use <strings.h> instead of <string.h> */
+
+#if (defined(BSD) && (BSD >= 199306))
+#define HAS_BSDSOCKETS		/* <net/inet.h>, socket( ), etc.	*/
+#define HAS_BSDTIME		/* gettimeofday( ) return time		*/
+#define HAS_FLOAT_H		/* float.h				*/
+#define HAS_STRCHR		/* strchr( ) instead of index( )	*/
+#define HAS_INTWAITSTATUS	/* wait(3)  takes an int *, not a union */
+#undef HAS_UNIX_SEGMENT_HACK
+#endif
