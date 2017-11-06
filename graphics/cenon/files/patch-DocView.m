--- DocView.m.orig	2017-05-26 08:51:18 UTC
+++ DocView.m
@@ -101,6 +101,10 @@
 - (void)joinSelection:(id)change messages:(BOOL)messages;
 @end
 
+@interface Dummy
+- (CGFloat)backingScaleFactor;
+@end
+
 NSString *e2PboardType = @"Cenon Graphic List";
 
 static NSRect   selectionRect = {{0.0, 0.0}, {0.0, 0.0}};   // shared rect for drawing the selection rect in -drawRect:
