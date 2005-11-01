--- main/base64.cc.orig	Sun Oct 30 22:02:27 2005
+++ main/base64.cc	Mon Oct 31 04:14:40 2005
@@ -13,7 +13,7 @@
 #include "base64.h"
 #include <string.h>
 #include <stdio.h>
-#include <stdint.h>
+#include <inttypes.h>
 
 char Table64[64]={  'A','B','C','D','E','F','G','H',
 		    'I','J','K','L','M','N','O','P',
