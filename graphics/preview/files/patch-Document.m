--- Document.m.orig	2005-06-28 10:25:25.000000000 +0200
+++ Document.m	2012-06-09 11:09:51.000000000 +0200
@@ -35,6 +35,7 @@
 
 #include <Foundation/NSNotification.h>
 
+#include <AppKit/AppKit.h>
 #include <AppKit/NSApplication.h>
 #include <AppKit/NSAffineTransform.h>
 #include <AppKit/NSClipView.h>
@@ -592,7 +592,7 @@
 {
   SEL action = [menuItem action];
 
-  if ( sel_eq(action,@selector(resize:)) )
+  if ( sel_isEqual(action,@selector(resize:)) )
     {
       if ( [menuItem tag] == [self _currentItem] ) 
        return NO;
