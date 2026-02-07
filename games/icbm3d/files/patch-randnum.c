--- ./randnum.c.orig	1998-07-29 23:25:59.000000000 +0200
+++ ./randnum.c	2013-12-24 08:33:46.000000000 +0100
@@ -11,6 +11,7 @@
 #include <stdio.h>
 #include <sys/time.h>
 #include "randnum.h"
+#include <stdlib.h>
 
 void randinit()
 {
