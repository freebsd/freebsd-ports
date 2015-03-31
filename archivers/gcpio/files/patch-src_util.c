--- src/util.c.orig	2010-03-10 10:22:30 UTC
+++ src/util.c
@@ -206,10 +206,7 @@ tape_fill_input_buffer (int in_des, int 
   if (input_size < 0)
     error (1, errno, _("read error"));
   if (input_size == 0)
-    {
-      error (0, 0, _("premature end of file"));
-      exit (1);
-    }
+    error (PAXEXIT_FAILURE, 0, _("premature end of file"));
   input_bytes += input_size;
 }
 
