--- src/wordbuf.c.orig	2011-08-13 23:52:52.000000000 +0900
+++ src/wordbuf.c	2011-08-13 23:53:22.000000000 +0900
@@ -9,6 +9,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 #include "wordbuf.h"
 
 #define WORDLEN_DEF 64
