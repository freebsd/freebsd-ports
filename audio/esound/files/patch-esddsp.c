--- esddsp.c.orig	2008-11-18 15:35:19.000000000 -0500
+++ esddsp.c	2008-11-20 14:35:02.000000000 -0500
@@ -70,6 +70,7 @@
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__bsdi__)
 typedef unsigned long request_t;
+typedef off_t off64_t;
 #else
 typedef int request_t;
 #endif
@@ -228,16 +229,19 @@ open_wrapper (int (*func) (const char *,
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
@@ -268,7 +272,7 @@ open (const char *pathname, int flags, .
 {
   static int (*func) (const char *, int, mode_t) = NULL;
   va_list args;
-  mode_t mode;
+  mode_t mode = 0;
 
   DPRINTF ("open\n");
 
@@ -283,9 +287,12 @@ open (const char *pathname, int flags, .
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
@@ -295,7 +302,7 @@ open64 (const char *pathname, int flags,
 {
   static int (*func) (const char *, int, mode_t) = NULL;
   va_list args;
-  mode_t mode;
+  mode_t mode = 0;
 
   DPRINTF ("open64\n");
 
@@ -310,9 +317,12 @@ open64 (const char *pathname, int flags,
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
