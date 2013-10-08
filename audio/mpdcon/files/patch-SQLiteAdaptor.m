--- ./SQLiteAdaptor.m.orig	2013-10-07 00:51:38.000000000 +0100
+++ ./SQLiteAdaptor.m	2013-10-07 00:51:54.000000000 +0100
@@ -24,8 +24,8 @@
 
 #import "SQLiteAdaptor.h"
 
-@interface SQLiteAdaptor(Private)
 static NSString* SongRatingStorageDirectory = nil;
+@interface SQLiteAdaptor(Private)
 -(NSString *)_getMPDConDBName;
 @end
 
