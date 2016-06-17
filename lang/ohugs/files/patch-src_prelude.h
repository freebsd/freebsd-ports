--- src/prelude.h.orig	2016-06-17 23:19:53 UTC
+++ src/prelude.h
@@ -22,7 +22,7 @@
  * update the source.
  *-------------------------------------------------------------------------*/
 
-#define SOLARIS  1	/* For Solaris 2.4				   */
+#define SOLARIS  0	/* For Solaris 2.4				   */
 #define SUNOS    0      /* For Sun 3/Sun 4 running SunOs 4.x		   */
 #define BCWIN16	 0	/* For Windows 3.1, Borland C++ 4.52		   */
 #define BCWIN32  0	/* For Windows 32,  Borland C++ 4.52		   */
@@ -44,7 +44,7 @@
 #define AIX	 0	/* For IBM AIX on RS/6000 using GCC		UN */
 #define ATARI	 0	/* For Atari ST/STE/TT/Falcon w/ Lattice C 5.52 UN */
 #define SGI4	 0	/* For SiliconGraphics Indigo, IRIX v*4*.0.5	UN */
-#define NETBSD	 0	/* For NetBSD-current				UN */
+#define NETBSD	 1	/* For NetBSD-current				UN */
 #define MACWP	 0	/* For Macintosh PPC/68K using CodeWarrior Pro     */
 
 /*---------------------------------------------------------------------------
