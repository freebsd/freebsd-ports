--- ini/ini_parse_ut.c.orig	2014-05-09 20:57:53 UTC
+++ ini/ini_parse_ut.c
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <limits.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include "ini_defines.h"
 #include "ini_configobj.h"
 #include "ini_config_priv.h"
