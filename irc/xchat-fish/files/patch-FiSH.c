--- FiSH.c.orig	2006-03-15 22:17:58.000000000 +0100
+++ FiSH.c	2008-03-29 17:27:33.000000000 +0100
@@ -4,6 +4,7 @@
 
 
 #include "xchat-plugin.h"
+#include <ctype.h>
 #include "FiSH.h"
 
 static xchat_plugin *ph=0;   // plugin handle
