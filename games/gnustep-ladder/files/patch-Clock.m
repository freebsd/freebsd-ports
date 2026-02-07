--- Clock.m.orig	2005-09-16 00:49:12.000000000 +0200
+++ Clock.m	2010-05-23 07:03:08.000000000 +0200
@@ -834,7 +834,7 @@
 	return _timeZone;
 }
 
-- (void) setDate:(NSDate *)date
+- (void) setDate:(NSCalendarDate *)date
 {
 	ASSIGN(_date, date);
 	handsTime = [date timeIntervalSinceReferenceDate] + _tzv;
@@ -842,7 +842,7 @@
 	[self setNeedsDisplay: YES];
 }
 
-- (NSDate *) date
+- (NSCalendarDate *) date
 {
 	return _date;
 }
