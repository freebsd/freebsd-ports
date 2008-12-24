--- Plugins/Nib/GormNibWrapperLoader.h.orig	2008-06-25 00:09:55.000000000 +0200
+++ Plugins/Nib/GormNibWrapperLoader.h	2008-12-23 16:40:32.000000000 +0100
@@ -26,7 +26,8 @@
 #define GORM_NIBWRAPPERLOADER
 
 #include <GormCore/GormWrapperLoader.h>
-#include <GNUstepGUI/GSNibCompatibility.h>
+#include <GNUstepGUI/GSNibLoading.h>
+#include <GNUstepGUI/GSGormLoading.h>
 
 @interface GormNibWrapperLoader : GormWrapperLoader
 {
