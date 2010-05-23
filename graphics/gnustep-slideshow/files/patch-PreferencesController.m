--- PreferencesController.m.orig	2004-12-17 10:10:22.000000000 +0100
+++ PreferencesController.m	2010-05-23 05:22:03.000000000 +0200
@@ -32,7 +32,9 @@
 
 #include "InputView.h"
 
+#include <Foundation/NSArchiver.h>
 #include <Foundation/NSNotification.h>
+#include <Foundation/NSUserDefaults.h>
 
 #include <AppKit/NSBrowser.h>
 #include <AppKit/NSBrowserCell.h>
