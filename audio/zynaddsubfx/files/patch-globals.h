--- globals.h.orig	Mon Mar 19 07:54:57 2007
+++ globals.h	Mon Mar 19 07:55:00 2007
@@ -196,7 +196,7 @@
 
 
 //is like i=(int)(floor(f))
-#ifdef ASM_F2I_YES
+#if defined(ASM_F2I_YES) && defined(__i386__)
 #define F2I(f,i) __asm__ __volatile__ ("fistpl %0" : "=m" (i) : "t" (f-0.49999999) : "st") ;
 #else
 #define F2I(f,i) (i)=((f>0) ? ( (int)(f) ) :( (int)(f-1.0) ));
