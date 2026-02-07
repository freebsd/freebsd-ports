--- hpscat.h.orig	1995-11-23 10:16:11 UTC
+++ hpscat.h
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
@@ -185,5 +187,13 @@ extern bool    cheat;      /*  true if cheating */
 extern bool    narrow;     /*  false if normal courier is used */
 extern FILE   *fp;         /*  file pointer to input file  */
 extern FILE   *ofp;        /*  file pointer to output file  */
+
+void	endfile(void);
+void	fatal(char *);
+int	fillpagebuf(void);
+int	find_f(int, int, int);
+int	find_l(int, int, int);
+int	find_m(int, int, int);
+int	find_set(int);
 
 /***  EOF  ***/
