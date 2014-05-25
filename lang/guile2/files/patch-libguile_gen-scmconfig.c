--- libguile/gen-scmconfig.c	2008-02-23 21:38:39.310330888 -0600
+++ libguile/gen-scmconfig.c	2008-02-23 21:39:32.909873567 -0600
@@ -123,6 +123,7 @@
 
 #include "gen-scmconfig.h"
 
+#define _ANSI_SOURCE
 #include <stdio.h>
 #include <string.h>
 
