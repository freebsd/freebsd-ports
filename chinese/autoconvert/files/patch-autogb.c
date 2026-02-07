--- autogb.c.orig	2013-09-27 20:12:01.000000000 +0800
+++ autogb.c	2013-09-27 20:13:53.000000000 +0800
@@ -26,9 +26,13 @@ Boston, MA  02111-1307, USA.
 //$Header: /home/prog/autoconvert/autogb.c,v 1.7 2001/04/23 14:18:06 ygh Exp $
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <string.h>
 #include <getopt.h>
 #include "hz.h"
 
+extern int conv_str(char *);
 
 /* Print help and exit */
 void print_help(char* filename){
