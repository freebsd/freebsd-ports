--- Source/NSFileManager.m.orig	Thu Oct  9 11:31:35 2003
+++ Source/NSFileManager.m	Sat Apr 24 07:39:43 2004
@@ -589,6 +589,12 @@
   int		len, cur;
   NSDictionary	*needChown = nil;
     
+  if (path == nil) // don't try to do anything when path is nil
+    {
+      ASSIGN(_lastError, @"Could not create directory - name is nil");
+      return NO;
+    }
+
   /*
    * If there is no file owner specified, and we are running setuid to
    * root, then we assume we need to change ownership to correct user.
@@ -682,6 +688,12 @@
   while (cur < len);
 
 #endif /* !MINGW */
+
+  // dont change when we have no attibutes
+  if (attributes == nil)
+    {
+      return YES;
+    }
 
   // change attributes of last directory
   if ([attributes count] == 0)
