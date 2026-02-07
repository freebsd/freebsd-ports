--- Clock.h.orig	2005-09-16 00:49:12.000000000 +0200
+++ Clock.h	2010-05-23 07:03:45.000000000 +0200
@@ -24,7 +24,7 @@
 
 	NSFont *font;
 
-	NSDate *_date;
+	NSCalendarDate *_date;
 
 	NSTimeZone *_timeZone;
 	NSTimeInterval _tzv;
@@ -47,8 +47,8 @@
 
 - (void) setTimeZone:(NSTimeZone *)tz;
 - (NSTimeZone *) timeZone;
-- (void) setDate:(NSDate *)date;
-- (NSDate *) date;
+- (void) setDate:(NSCalendarDate *)date;
+- (NSCalendarDate *) date;
 
 /* move a clock to CSClockView and put these theming method into subclass */
 
