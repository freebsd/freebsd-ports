--- ScalingScrollView.m.orig	2003-10-28 20:28:47.000000000 +0100
+++ ScalingScrollView.m	2010-05-22 12:31:35.000000000 +0200
@@ -11,7 +11,9 @@
 
 #import "ScalingScrollView.h"
 
+#import <Foundation/NSBundle.h>
 #import <Foundation/NSGeometry.h>
+#import <Foundation/NSValue.h>
 #import <AppKit/NSPopUpButton.h>
 #import <AppKit/NSScroller.h>
 #import <AppKit/NSButtonCell.h>
