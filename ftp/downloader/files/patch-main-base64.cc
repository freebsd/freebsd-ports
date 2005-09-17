--- main/base64.cc.orig	Fri Sep 16 13:32:16 2005
+++ main/base64.cc	Fri Sep 16 23:03:23 2005
@@ -13,6 +13,7 @@
 #include "base64.h"
 #include <string.h>
 #include <stdio.h>
+#include <inttypes.h>
 
 char Table64[64]={  'A','B','C','D','E','F','G','H',
 		    'I','J','K','L','M','N','O','P',
