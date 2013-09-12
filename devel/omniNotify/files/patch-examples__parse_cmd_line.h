--- ./examples/parse_cmd_line.h.orig	2003-10-23 06:39:11.000000000 +0200
+++ ./examples/parse_cmd_line.h	2013-09-12 19:37:33.527063786 +0200
@@ -4,7 +4,8 @@
 #define _PARSE_CMD_LINE_H
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "CosNotifyShorthands.h"
 
