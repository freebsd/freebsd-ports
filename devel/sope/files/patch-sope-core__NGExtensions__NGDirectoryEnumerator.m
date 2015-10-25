--- sope-core/NGExtensions/NGDirectoryEnumerator.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/NGDirectoryEnumerator.m
@@ -54,7 +54,7 @@
 {
   self->fileManager = _fm
     ? [_fm retain]
-    : [[NSFileManager defaultManager] retain];
+    : (id)[[NSFileManager defaultManager] retain];
 
   self->pathStack = [[NSMutableArray alloc] init];
   self->enumStack = [[NSMutableArray alloc] init];
