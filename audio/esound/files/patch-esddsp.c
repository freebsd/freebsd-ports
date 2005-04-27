--- esddsp.c.orig	Tue Apr 26 22:41:23 2005
+++ esddsp.c	Tue Apr 26 22:42:04 2005
@@ -223,9 +223,12 @@ open (const char *pathname, int flags, .
 
   dsp_init ();
 
-  va_start (args, flags);
-  mode = va_arg (args, mode_t);
-  va_end (args);
+  if ((flags & O_CREAT) != 0)
+    {
+      va_start (args, flags);
+      mode = va_arg (args, int);
+      va_end (args);
+    }
 
   if (!strcmp (pathname, "/dev/dsp"))
     {
