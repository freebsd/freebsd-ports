--- sope-core/NGExtensions/FdExt.subproj/NSObject+Values.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/FdExt.subproj/NSObject+Values.m
@@ -82,7 +82,7 @@
 
 + (NSString *) stringWithUnsignedLongLong: (unsigned long long)value
 {
-  return [NSString stringWithFormat: @"0x%.16"PRIx64, value];
+  return [NSString stringWithFormat: @"0x%.16llx", value];
 }
 
 - (BOOL)boolValue {
