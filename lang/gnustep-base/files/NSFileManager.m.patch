--- Source/NSFileManager.m.orig	Fri Mar 18 05:17:39 2005
+++ Source/NSFileManager.m	Fri Apr  1 06:37:16 2005
@@ -757,6 +757,12 @@
 
 #endif /* !MINGW */
 
+  // dont change when we have no attibutes
+  if (attributes == nil)
+    {
+      return YES;
+    }
+
   // change attributes of last directory
   if ([attributes count] == 0)
     {
@@ -785,6 +791,12 @@
   int	len;
   int	written;
 #endif
+
+  if (path == nil) // don't try to do anything when path is nil
+    {
+      ASSIGN(_lastError, @"Could not create directory - name is nil");
+      return NO;
+    }
 
   /* This is consitent with MacOSX - just return NO for an invalid path. */
   if ([path length] == 0)
