--- src/stream.c.orig	2001-08-18 18:46:34 UTC
+++ src/stream.c
@@ -213,36 +213,36 @@ read_stream (FILE *file)
 void
 print_stream_inf(stream_t *stream, char *name)
 {
-  sprintf (log.buf, "%s: Info on file %s:\n", me, name);
+  sprintf (mp3asm_log.buf, "%s: Info on file %s:\n", me, name);
   print_all (1);
-  sprintf (log.buf, "        MPEG %d layer %d", stream->maj_version, stream->layer);
+  sprintf (mp3asm_log.buf, "        MPEG %d layer %d", stream->maj_version, stream->layer);
   print_all (1);
 
   if (!stream->cbr)
-    sprintf (log.buf, " VBR [avg. %.0f kbps], ", stream->avkbps);
+    sprintf (mp3asm_log.buf, " VBR [avg. %.0f kbps], ", stream->avkbps);
   else 
-    sprintf (log.buf, " at %.0f kbps, ", stream->avkbps);
+    sprintf (mp3asm_log.buf, " at %.0f kbps, ", stream->avkbps);
 
   print_all (1);
-  sprintf (log.buf, "sampled at %d.\n", stream->freq);
+  sprintf (mp3asm_log.buf, "sampled at %d.\n", stream->freq);
   print_all (1);
   
-  sprintf(log.buf, "        ");
+  sprintf(mp3asm_log.buf, "        ");
   print_all (1);
 
   switch (stream->mode)
     {
     case 0:
-      sprintf(log.buf, "Stereo, ");
+      sprintf(mp3asm_log.buf, "Stereo, ");
       break;
     case 1:
-      sprintf(log.buf, "Joint Stereo, ");
+      sprintf(mp3asm_log.buf, "Joint Stereo, ");
       break;
     case 2:
-      sprintf(log.buf, "Dual Channel, ");
+      sprintf(mp3asm_log.buf, "Dual Channel, ");
       break;
     case 3:
-      sprintf(log.buf, "Mono, ");
+      sprintf(mp3asm_log.buf, "Mono, ");
       break;
     }
   print_all (1);
@@ -250,36 +250,36 @@ print_stream_inf(stream_t *stream, char *name)
   switch (stream->crc)
     {
     case 0:
-      sprintf(log.buf, "not protected by CRC.\n");
+      sprintf(mp3asm_log.buf, "not protected by CRC.\n");
       break;
     case 1:
-      sprintf(log.buf, "protected by CRC.\n");
+      sprintf(mp3asm_log.buf, "protected by CRC.\n");
       break;
     }
   print_all (1);
 
-  sprintf(log.buf, "        ");
+  sprintf(mp3asm_log.buf, "        ");
   print_all (1);
 
   if (stream->private) 
-    sprintf(log.buf, "private, ");
+    sprintf(mp3asm_log.buf, "private, ");
   else
-    sprintf(log.buf, "not private, ");
+    sprintf(mp3asm_log.buf, "not private, ");
   print_all (1);
   
   if (stream->copyright) 
-    sprintf(log.buf, "copyrighted, ");
+    sprintf(mp3asm_log.buf, "copyrighted, ");
   else
-    sprintf(log.buf, "not copyrighted, ");
+    sprintf(mp3asm_log.buf, "not copyrighted, ");
   print_all (1);
 
   if (stream->original) 
-    sprintf(log.buf, "original.\n");
+    sprintf(mp3asm_log.buf, "original.\n");
   else
-    sprintf(log.buf, "not original.\n");
+    sprintf(mp3asm_log.buf, "not original.\n");
   print_all (1);
 
-  sprintf(log.buf, "        %ld frames at %d samples per frame, infosize = %d.\n", stream->count, stream->samples, stream->isize);
+  sprintf(mp3asm_log.buf, "        %ld frames at %d samples per frame, infosize = %d.\n", stream->count, stream->samples, stream->isize);
   print_all (1);
 }
 
@@ -292,13 +292,13 @@ process_input (stream_t *stream, long startframe, long
 {
   if (startframe >= stream->count)
     {
-      sprintf (log.buf, "Cannot skip %ld frames... No frames left to write.\n", startframe);
+      sprintf (mp3asm_log.buf, "Cannot skip %ld frames... No frames left to write.\n", startframe);
       print_all (0);
       exit(EX_USAGE);
     }
   if (endframe > stream->count)
     {
-      sprintf (log.buf, "File has less frames (%ld) than specified (%ld)... Reading till end.\n", stream->count, endframe);
+      sprintf (mp3asm_log.buf, "File has less frames (%ld) than specified (%ld)... Reading till end.\n", stream->count, endframe);
       print_all (0);
     }
   
@@ -345,31 +345,31 @@ merge_streams (stream_t *streama, stream_t *streamb)
 {
   if (streama->maj_version != streamb->maj_version)
     {
-      sprintf (log.buf, "Incompatible streams: Cannot combine streams with different major versions.\n");
+      sprintf (mp3asm_log.buf, "Incompatible streams: Cannot combine streams with different major versions.\n");
       print_all (-1);
       exit (EX_USAGE);
     }
   else if (streama->min_version != streamb->min_version)
     {
-      sprintf (log.buf, "Incompatible streams: Cannot combine streams with different minor versions.\n");
+      sprintf (mp3asm_log.buf, "Incompatible streams: Cannot combine streams with different minor versions.\n");
       print_all (-1);
       exit (EX_USAGE);
     }
   else if (streama->layer != streamb->layer)
     {
-      sprintf (log.buf, "Incompatible streams: Cannot combine streams that are not the same layer.\n");
+      sprintf (mp3asm_log.buf, "Incompatible streams: Cannot combine streams that are not the same layer.\n");
       print_all (-1);
       exit (EX_USAGE);
     }
   else if (streama->freq != streamb->freq)
      {
-      sprintf (log.buf, "Incompatible streams: Cannot combine streams with different frequencies.\n");
+      sprintf (mp3asm_log.buf, "Incompatible streams: Cannot combine streams with different frequencies.\n");
       print_all (-1);
       exit (EX_USAGE);
     }
   else if (streama->mode != streamb->mode)
     {
-      sprintf (log.buf, "Incompatible streams: Cannot combine streams with different modes.\n");
+      sprintf (mp3asm_log.buf, "Incompatible streams: Cannot combine streams with different modes.\n");
       print_all (-1);
       exit (EX_USAGE);
     }
