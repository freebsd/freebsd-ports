--- misc/magic.h.orig	Sat Sep 22 00:15:45 2001
+++ misc/magic.h	Fri Oct 11 23:38:53 2002
@@ -146,7 +146,7 @@
  *
  */
 
-#ifdef        i386
+#if defined(i386) || (defined(__alpha__) && defined(__FreeBSD__))
 #define       IS_LITTLE_ENDIAN        /* Intel x86 processors. */
 #endif
 
@@ -224,7 +224,7 @@
 #if defined(sun) && !defined(sparc)
 # define NEED_MONCNTL
 #endif  
-#ifdef	ALPHA
+#if defined(ALPHA) || (defined(__alpha__) && defined(__FreeBSD__))
 # define NEED_MONCNTL
 #endif  
 
