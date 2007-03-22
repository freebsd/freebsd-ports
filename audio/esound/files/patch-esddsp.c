--- esddsp.c.orig	Mon Jan  1 18:56:06 2007
+++ esddsp.c	Thu Mar 22 19:49:15 2007
@@ -224,9 +224,12 @@ open_wrapper (int (*func) (const char *,
 
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
@@ -272,9 +275,12 @@ open (const char *pathname, int flags, .
 	}
     }
 
-  va_start (args, flags);
-  mode = va_arg (args, mode_t);
-  va_end (args);
+  if ((flags & O_CREAT) != 0)
+    {
+      va_start (args, flags);
+      mode = va_arg (args, mode_t);
+      va_end (args);
+    }
 
   return open_wrapper(func, pathname, flags, mode);
 }
@@ -299,9 +305,12 @@ open64 (const char *pathname, int flags,
 	}
     }
 
-  va_start (args, flags);
-  mode = va_arg (args, mode_t);
-  va_end (args);
+  if ((flags & O_CREAT) != 0)
+    {
+      va_start (args, flags);
+      mode = va_arg (args, mode_t);
+      va_end (args);
+    }
 
   return open_wrapper(func, pathname, flags, mode);
 }
