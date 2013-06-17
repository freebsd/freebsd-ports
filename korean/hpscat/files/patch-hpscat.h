--- hpscat.h.orig	1995-11-23 05:16:11.000000000 -0500
+++ hpscat.h	2013-06-12 18:37:53.000000000 -0400
@@ -49,9 +49,11 @@
 \*------------------------------*/
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <sys/time.h>
+#include <sys/wait.h>
 
 #ifdef __GNUC__
 # define  PROT(x)  x
@@ -186,4 +188,12 @@
 extern FILE   *fp;         /*  file pointer to input file  */
 extern FILE   *ofp;        /*  file pointer to output file  */
 
+void	endfile(void);
+void	fatal(char *);
+int	fillpagebuf(void);
+int	find_f(int, int, int);
+int	find_l(int, int, int);
+int	find_m(int, int, int);
+int	find_set(int);
+
 /***  EOF  ***/
