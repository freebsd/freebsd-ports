--- Document.m.orig	2005-05-23 21:30:29.000000000 +0200
+++ Document.m	2010-05-23 08:46:40.000000000 +0200
@@ -7,9 +7,12 @@
 #include <math.h>
 #include <time.h>
 
+#include <Foundation/NSCharacterSet.h>
 #include <Foundation/NSFileManager.h>
+#include <Foundation/NSValue.h>
 #include <AppKit/NSBezierPath.h>
 #include <AppKit/NSFontManager.h>
+#include <AppKit/NSGraphics.h>
 #include <AppKit/NSScrollView.h>
 #include <AppKit/NSWindow.h>
 #include <AppKit/DPSOperators.h>
