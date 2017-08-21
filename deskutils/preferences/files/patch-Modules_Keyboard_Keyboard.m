--- Modules/Keyboard/Keyboard.m.orig	2017-08-13 12:40:14 UTC
+++ Modules/Keyboard/Keyboard.m
@@ -34,9 +34,7 @@ static const char rcsid[] = 
 # include "Config.h"
 #endif
 
-#import <AppKit/NSButton.h>
-#import <AppKit/NSNibLoading.h>
-#import <AppKit/NSOpenPanel.h>
+#import <Cocoa/Cocoa.h>
 
 #import "Keyboard.h"
 #import "KeyboardView.h"
