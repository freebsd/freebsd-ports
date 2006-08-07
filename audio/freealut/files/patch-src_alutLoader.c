--- src/alutLoader.c.orig	Sun Aug  6 19:00:08 2006
+++ src/alutLoader.c	Sun Aug  6 19:01:10 2006
@@ -474,7 +474,7 @@
 
   /* ToDo: Can we do something less insane than passing 0x7FFFFFFF? */
   stream = _alutInputStreamConstructFromMemory (buffer, 0x7FFFFFFF);
-  _alutLoadMemoryFromInputStream (stream, format, size, &freq);
+  *data = _alutLoadMemoryFromInputStream (stream, format, size, &freq);
   if (*data == NULL)
     {
       return;
