--- Palettes/1Windows/GormNSWindow.m.orig	2008-05-03 19:40:55.000000000 +0200
+++ Palettes/1Windows/GormNSWindow.m	2008-12-23 11:55:25.000000000 +0100
@@ -23,7 +23,8 @@
 */
 
 #include <AppKit/AppKit.h>
-#include <GNUstepGUI/GSNibTemplates.h>
+#include <GNUstepGUI/GSNibLoading.h>
+#include <GNUstepGUI/GSGormLoading.h>
 #include <InterfaceBuilder/InterfaceBuilder.h>
 #include "GormNSWindow.h"
 
