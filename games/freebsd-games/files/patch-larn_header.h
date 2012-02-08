Index: larn/header.h
@@ -326,7 +326,6 @@
 #define DEMONLORD 57
 #define DEMONPRINCE 64
 
-#define NULL 0
 #define BUFBIG	4096			/* size of the output buffer */
 #define MAXIBUF	4096			/* size of the input buffer */
 #define LOGNAMESIZE 40			/* max size of the players name */
@@ -359,7 +359,7 @@
 
 char *fortune(),*lgetw(),*lgetl();
 char *tmcapcnv();
-long paytaxes(),lgetc(),lrint();
+long paytaxes(),lgetc(),lrint_x();
 unsigned long readnum();
 
 	/* macro to create scroll #'s with probability of occurrence */
