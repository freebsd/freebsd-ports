--- src/alutLoader.c.orig	2006-05-08 09:28:07 UTC
+++ src/alutLoader.c
@@ -474,7 +474,7 @@ alutLoadWAVMemory (ALbyte *buffer, ALenu
 
   /* ToDo: Can we do something less insane than passing 0x7FFFFFFF? */
   stream = _alutInputStreamConstructFromMemory (buffer, 0x7FFFFFFF);
-  _alutLoadMemoryFromInputStream (stream, format, size, &freq);
+  *data = _alutLoadMemoryFromInputStream (stream, format, size, &freq);
   if (*data == NULL)
     {
       return;
