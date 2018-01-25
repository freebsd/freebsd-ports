--- exjdxgen.c.orig	1998-05-24 15:43:37 UTC
+++ exjdxgen.c
@@ -22,7 +22,7 @@
 #include <sys/stat.h>
 
 #include <stdio.h>
-/*#include <stdlib.h>*/
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include "xjdic.h"
@@ -229,6 +229,7 @@ unsigned char **argv;
   jindex[0] = diclen+jiver;
   fwrite(jindex,sizeof(long),indptr+2,fp);
   fclose(fp);
+  return (0);
 }
 /*======function to sort jindex table====================*/
 
