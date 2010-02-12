--- src/genericgui/GenericGui.cxx.orig	2009-11-24 15:22:50.000000000 +0600
+++ src/genericgui/GenericGui.cxx	2009-11-24 15:23:19.000000000 +0600
@@ -60,6 +60,8 @@
 
 #include <ctime>
 
+#include <sys/wait.h>
+
 //#define _DEVDEBUG_
 #include "YacsTrace.hxx"
 
