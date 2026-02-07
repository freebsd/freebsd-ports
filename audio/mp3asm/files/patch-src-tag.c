--- src/tag.c.orig	2001-04-12 03:34:39 UTC
+++ src/tag.c
@@ -74,7 +74,7 @@ write_tag_v1 (stream_t *stream, FILE *file)
     {
       if (fwrite(stream->tag, sizeof(unsigned char), 128, file) < 0)
 	{
-	  sprintf (log.buf, "%s: Error writing tag to file.\n", me);
+	  sprintf (mp3asm_log.buf, "%s: Error writing tag to file.\n", me);
 	  print_all (-1);
 	  perror ("fwrite");
 	  return (-1);
