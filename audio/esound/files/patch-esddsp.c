--- esddsp.c.orig	2008-07-15 11:47:20.000000000 -0400
+++ esddsp.c	2008-07-17 13:58:09.000000000 -0400
@@ -220,16 +220,19 @@ open_wrapper (int (*func) (const char *,
 	      const char *pathname, int flags, ...)
 {
   va_list args;
-  mode_t mode;
+  mode_t mode = 0;
 
   dsp_init ();
 
-  va_start (args, flags);
-  if (sizeof (mode_t) < sizeof (int))
+  if ((flags & O_CREAT) != 0)
+    {
+      va_start (args, flags);
+      if (sizeof (mode_t) < sizeof (int))
 	  mode = va_arg (args, int);
-  else
+      else
 	  mode = va_arg (args, mode_t);
-  va_end (args);
+      va_end (args);
+    }
 
   if (!strcmp (pathname, "/dev/dsp"))
     {
@@ -260,7 +263,7 @@ open (const char *pathname, int flags, .
 {
   static int (*func) (const char *, int, mode_t) = NULL;
   va_list args;
-  mode_t mode;
+  mode_t mode = 0;
 
   DPRINTF ("open\n");
 
@@ -275,9 +278,12 @@ open (const char *pathname, int flags, .
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
@@ -287,7 +293,7 @@ open64 (const char *pathname, int flags,
 {
   static int (*func) (const char *, int, mode_t) = NULL;
   va_list args;
-  mode_t mode;
+  mode_t mode = 0;
 
   DPRINTF ("open64\n");
 
@@ -302,9 +308,12 @@ open64 (const char *pathname, int flags,
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
