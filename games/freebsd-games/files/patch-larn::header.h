$FreeBSD$

--- larn/header.h	17 Jun 2003 02:49:28 -0000	1.1
+++ larn/header.h	21 Jun 2004 02:28:34 -0000	1.2
@@ -359,7 +359,7 @@
 
 char *fortune(),*lgetw(),*lgetl();
 char *tmcapcnv();
-long paytaxes(),lgetc(),lrint();
+long paytaxes(),lgetc(),lrint_x();
 unsigned long readnum();
 
 	/* macro to create scroll #'s with probability of occurrence */
