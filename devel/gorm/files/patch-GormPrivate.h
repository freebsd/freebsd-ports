--- GormCore/GormPrivate.h.orig	2007-11-06 00:44:36.000000000 +0100
+++ GormCore/GormPrivate.h	2008-12-23 09:27:03.000000000 +0100
@@ -36,8 +36,8 @@
 #include <GormCore/GormPalettesManager.h>
 #include <GormCore/GormProtocol.h>
 #include <GormCore/GormClassEditor.h>
-#include <GNUstepGUI/GSNibTemplates.h>
-#include <GNUstepGUI/GSNibCompatibility.h>
+#include <GNUstepGUI/GSNibLoading.h>
+#include <GNUstepGUI/GSGormLoading.h>
 
 extern NSString *GormLinkPboardType;
 extern NSString *GormToggleGuidelineNotification;
