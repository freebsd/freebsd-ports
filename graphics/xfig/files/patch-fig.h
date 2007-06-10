--- fig.h.orig	Fri Feb 24 12:15:16 2006
+++ fig.h
@@ -383,7 +383,7 @@
 extern	long		random();
 extern	void		srandom(unsigned int);
 
-#elif !defined(__osf__) && !defined(__CYGWIN__) && !defined(linux)
+#elif !defined(__osf__) && !defined(__CYGWIN__) && !defined(linux) && !defined(__FreeBSD__)
 extern	void		srandom(int);
 
 #endif
