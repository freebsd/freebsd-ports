--- libmdnsd/1035.c.orig	2017-11-22 13:47:51 UTC
+++ libmdnsd/1035.c
@@ -1,6 +1,7 @@
+
+#include <stdio.h>
 #include "1035.h"
 #include <string.h>
-#include <stdio.h>
 
 #if defined(_MSC_VER) && _MSC_VER < 1900
 
