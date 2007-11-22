--- common/LineCmd.cpp.orig	2007-11-13 23:00:05.000000000 +0100
+++ common/LineCmd.cpp	2007-11-13 23:00:24.000000000 +0100
@@ -49,7 +49,7 @@
 #	include "UCvsDialogs.h"
 #endif
 
-char *sDefPrevCvsCmd[] = 
+const char *sDefPrevCvsCmd[] = 
 {
 	"cvs --help-options",
 	"cvs --help-commands",
