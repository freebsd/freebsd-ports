--- sope-core/NGExtensions/FdExt.subproj/NSException+misc.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/FdExt.subproj/NSException+misc.m
@@ -85,7 +85,7 @@
 
 - (id)copyWithZone:(NSZone *)_zone {
   // TODO: should make a real copy?
-  return [self retain];
+  return (id)[self retain];
 }
 
 @end /* NSException(NGMiscellaneous) */
