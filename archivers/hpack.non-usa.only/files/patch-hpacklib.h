--- hpacklib.h.orig	Thu Aug  5 04:10:40 1993
+++ hpacklib.h	Tue Dec 28 20:01:38 1999
@@ -26,12 +26,12 @@
 
 #include <stdio.h>					/* Prototypes for generic functions */
 #if defined( __UNIX__ ) && !( defined( BSD386 ) || defined( CONVEX ) || \
-							  defined( NEXT ) || defined( ULTRIX_OLD ) )
+							  defined( NEXT ) || defined( ULTRIX_OLD ) || defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ ))
   #include <malloc.h>				/* Needed for mem.functions on some systems */
 #endif /* __UNIX__ && !( BSD386 || CONVEX || NEXT || ULTRIX_OLD ) */
 #if defined( AIX386 ) || ( defined( __AMIGA__ ) && !defined( LATTICE ) ) || \
 	defined( __ARC__ ) || defined( __ATARI__ ) || defined( __MSDOS16__ ) || \
-	defined( __MSDOS32__ )
+	defined( __MSDOS32__ ) || defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
   #include <stdlib.h>				/* Needed for mem.functions */
 #endif /* AIX386 || ( __AMIGA__ && !LATTICE ) || __ARC__ || __ATARI__ || __MSDOS16__ || __MSDOS32__ */
 #if defined( __ATARI__ ) || ( defined( __OS2__ ) && !defined( __GCC__ ) )
