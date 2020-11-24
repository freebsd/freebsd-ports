--- src/utils.c.orig	2001-08-17 20:44:09 UTC
+++ src/utils.c
@@ -25,6 +25,7 @@
 #include "utils.h"
 #include <unistd.h>
 #include <stdio.h>
+#include <errno.h>
 
 /*
  * tmalloc: mallocs cleanly
@@ -77,31 +77,31 @@ trealloc (void *ptr, size_t size)
 }
 
 /*
- * print_std: prints log.buf to stderr
+ * print_std: prints mp3asm_log.buf to stderr
  *               takes min verbosity needed to show
  */
 void
 print_std (int verb)
 {
   if ((verb < 0) || ((verb <= verbosity) && !quiet))
-    fprintf (stderr, "%s", log.buf);
+    fprintf (stderr, "%s", mp3asm_log.buf);
   return;
 }
 
 /*
- * print_log: prints log.buf to stderr
+ * print_log: prints mp3asm_log.buf to stderr
  *             takes min verbosity needed to show
  */
 void
 print_log (int verb)
 {
-  if ((verb <= verbosity) && log.file && log.file)
-    fprintf (log.file, "%s", log.buf);
+  if ((verb <= verbosity) && mp3asm_log.file && mp3asm_log.file)
+    fprintf (mp3asm_log.file, "%s", mp3asm_log.buf);
   return;
 }
 
 /*
- * print_all: prints log.buf to stderr & file
+ * print_all: prints mp3asm_log.buf to stderr & file
  *            takes min verbosity needed to show
  */
 void
@@ -123,7 +123,7 @@ mp3ropen(char *name) /* infile */
 
   if (!file)
     {
-      sprintf(log.buf, "%s: Unable to read from %s.\n", me, name);
+      sprintf(mp3asm_log.buf, "%s: Unable to read from %s.\n", me, name);
       print_all (-1);
       exit (EX_NOINPUT);
     }
@@ -145,7 +145,7 @@ mp3wopen(char **name, int layer)
 
   while (!access (name2, F_OK))
     {
-      sprintf (log.buf, "File %s already exists.\n", name2);
+      sprintf (mp3asm_log.buf, "File %s already exists.\n", name2);
       print_all (0);
       
       if (!basename)
@@ -153,7 +153,7 @@ mp3wopen(char **name, int layer)
 	  char *po = name2 + strlen (*name) - 4;
 	  if (strncasecmp (po, ".mp", 3))
 	    {
-	      sprintf (log.buf, "%s: Unable to write to %s, this is not an mp1/2/3 file\n", me, name2);
+	      sprintf (mp3asm_log.buf, "%s: Unable to write to %s, this is not an mp1/2/3 file\n", me, name2);
 	      print_all (-1);
 	      exit (EX_CANTCREAT);
 	    }
@@ -183,14 +183,14 @@ mp3wopen(char **name, int layer)
   file = fopen (name2, "wx");
   if (!file)
     {
-      sprintf (log.buf, "%s: Unable to write to %s\n", me, name2);
+      sprintf (mp3asm_log.buf, "%s: Unable to write to %s\n", me, name2);
       print_all (-1);
       exit (EX_CANTCREAT);
     }
   free (*name);  /* change filename, we wont want it printin the wrong inf */
   name = &name2;
 
-  sprintf (log.buf, "Writing to %s\n", *name);
+  sprintf (mp3asm_log.buf, "Writing to %s\n", *name);
   print_all (0);
 
   return (file);
@@ -204,15 +204,15 @@ mp3wopen(char **name, int layer)
 int
 logopen(void) /* for appending only, logfile... */
 {
-  if(!log.name)
+  if(!mp3asm_log.name)
     return (1);       /* other functions will not use it either then */
 
-  log.file = fopen(log.name, "w");
-  if (!log.file)
+  mp3asm_log.file = fopen(mp3asm_log.name, "w");
+  if (!mp3asm_log.file)
     {
-      sprintf(log.buf, "Unable to write to %s, not logging output\n", log.name);
+      sprintf(mp3asm_log.buf, "Unable to write to %s, not logging output\n", mp3asm_log.name);
       print_std (-1);
-      log.name = NULL;
+      mp3asm_log.name = NULL;
       return (0);
     }
   return(1);
@@ -247,7 +247,7 @@ init_buf (int size)
   buffer->end = 0;
   buffer->eof = 0;
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: initialised buffer\nBUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
+  sprintf(mp3asm_log.buf, "BUFFER: initialised buffer\nBUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
 
@@ -264,7 +264,7 @@ free_buf(buffer_t *buffer)
 {
   if (buffer->used)
     {
-      sprintf(log.buf, "Warning: Emptying a not completely empty buffer (%p,%d/%d)\n", buffer, buffer->used, buffer->size);
+      sprintf(mp3asm_log.buf, "Warning: Emptying a not completely empty buffer (%p,%d/%d)\n", buffer, buffer->used, buffer->size);
       print_all (0);
     }
   free(buffer->data);
@@ -303,14 +303,14 @@ fill_buf_from_file (buffer_t *buffer, FILE *file)
 		continue;
 	      else
 		{
-		  sprintf (log.buf, "%s: Error reading from file to buffer.\n", me);
+		  sprintf (mp3asm_log.buf, "%s: Error reading from file to buffer.\n", me);
 		  print_all (-1);
 		  perror ("read()");
 		  return (-1);
 		}
 	    }
 #ifdef DEBUG_BUFFER
-	  sprintf (log.buf, "BUFFER: Reading from file to buffer: %d \n", readb);
+	  sprintf (mp3asm_log.buf, "BUFFER: Reading from file to buffer: %d \n", readb);
 	  print_log (10);
 #endif /* DEBUG_BUFFER */
 
@@ -325,7 +325,7 @@ fill_buf_from_file (buffer_t *buffer, FILE *file)
     }
 
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
+  sprintf(mp3asm_log.buf, "BUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
   
@@ -345,7 +345,7 @@ read_buf (buffer_t *buffer, unsigned char *data, int o
 
   if ((offset + count) > (buffer->used))
     {
-      sprintf(log.buf, "%s: Request for more bytes (%d + %d) than there are in buffer (%d/%d).\n", me, count, offset, buffer->used, buffer->size);
+      sprintf(mp3asm_log.buf, "%s: Request for more bytes (%d + %d) than there are in buffer (%d/%d).\n", me, count, offset, buffer->used, buffer->size);
       print_log (10);
       return (0);
     }
@@ -359,13 +359,13 @@ read_buf (buffer_t *buffer, unsigned char *data, int o
       ptr =(unsigned char *)(buffer->data + location);
       
 #ifdef DEBUG_BUFFER
-      sprintf (log.buf, "BUFFER: Reading %d from buffer (@%d from %d/%d)\n", count1, location, buffer->used, buffer->size);
+      sprintf (mp3asm_log.buf, "BUFFER: Reading %d from buffer (@%d from %d/%d)\n", count1, location, buffer->used, buffer->size);
       print_log (10);
 #endif /* DEBUG_BUFFER */  
       
       if (data != memcpy(data , ptr, count1 * sizeof(unsigned char)))
 	{
-	  sprintf (log.buf, "%s: Error reading from buffer.\n", me);
+	  sprintf (mp3asm_log.buf, "%s: Error reading from buffer.\n", me);
 	  print_all (-1);
 	  return (-1);
 	}
@@ -378,7 +378,7 @@ read_buf (buffer_t *buffer, unsigned char *data, int o
     }    
 
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
+  sprintf(mp3asm_log.buf, "BUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
   return (1);
@@ -397,7 +397,7 @@ rem_buf (buffer_t *buffer, int count)
       if (count > buffer->used)
 	{
 #ifdef DEBUG_BUFFER
-	  sprintf(log.buf, "%s: Cant free bytes that rnt in the buffer.\n", me);
+	  sprintf(mp3asm_log.buf, "%s: Cant free bytes that rnt in the buffer.\n", me);
 	  print_log (10);
 #endif /* DEBUG_BUFFER */
 	  return (0);
@@ -411,7 +411,7 @@ rem_buf (buffer_t *buffer, int count)
       buffer->used -= count;
     }
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: freed %d from buffer (%d)\nBUFFER: begin: %d end: %d used: %d size: %d\n", count, buffer->size, buffer->begin, buffer->end, buffer->used, buffer->size);
+  sprintf(mp3asm_log.buf, "BUFFER: freed %d from buffer (%d)\nBUFFER: begin: %d end: %d used: %d size: %d\n", count, buffer->size, buffer->begin, buffer->end, buffer->used, buffer->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
   
@@ -431,14 +431,14 @@ cut_buf (buffer_t *buffera, buffer_t *bufferb, int cou
   if (count > buffera->used)
     {
 #ifdef DEBUG_BUFFER
-      sprintf(log.buf, "%s: Request for more bytes (%d) than there are in buffer A (%d/%d).\n", me, count, buffera->used, buffera->size);
+      sprintf(mp3asm_log.buf, "%s: Request for more bytes (%d) than there are in buffer A (%d/%d).\n", me, count, buffera->used, buffera->size);
       print_log (10);
 #endif /* DEBUG_BUFFER */
       return (0);
     }    
   if (count > (bufferb->size - bufferb->used))
     {
-      sprintf(log.buf, "%s: Request for buffer overload received (%d + %d > %d\n", me, count, bufferb->used, bufferb->size);
+      sprintf(mp3asm_log.buf, "%s: Request for buffer overload received (%d + %d > %d\n", me, count, bufferb->used, bufferb->size);
       print_all (-1);
       return (-1);
     }
@@ -454,7 +454,7 @@ cut_buf (buffer_t *buffera, buffer_t *bufferb, int cou
 	count1 = bufferb->size - bufferb->end;
 
 #ifdef DEBUG_BUFFER      
-      sprintf (log.buf, "BUFFER: Reading %d from buffer (@%d from %d/%d) to buffer (@%d from %d/%d) \n", count1, buffera->begin, buffera->used, buffera->size, bufferb->end, bufferb->used, bufferb->size);
+      sprintf (mp3asm_log.buf, "BUFFER: Reading %d from buffer (@%d from %d/%d) to buffer (@%d from %d/%d) \n", count1, buffera->begin, buffera->used, buffera->size, bufferb->end, bufferb->used, bufferb->size);
       print_log (10);
 #endif /* DEBUG_BUFFER */      
       
@@ -474,9 +474,9 @@ cut_buf (buffer_t *buffera, buffer_t *bufferb, int cou
     }    
   
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: 1) begin: %d end: %d used: %d size: %d\n", buffera->begin, buffera->end, buffera->used, buffera->size);
+  sprintf(mp3asm_log.buf, "BUFFER: 1) begin: %d end: %d used: %d size: %d\n", buffera->begin, buffera->end, buffera->used, buffera->size);
   print_log (10);
-  sprintf(log.buf, "BUFFER: 2) begin: %d end: %d used: %d size: %d\n", bufferb->begin, bufferb->end, bufferb->used, bufferb->size);
+  sprintf(mp3asm_log.buf, "BUFFER: 2) begin: %d end: %d used: %d size: %d\n", bufferb->begin, bufferb->end, bufferb->used, bufferb->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
   
@@ -494,7 +494,7 @@ write_buf (unsigned char *data, buffer_t *buffer, int 
 
   if (count > (buffer->size - buffer->used))
     {
-      sprintf(log.buf, "%s: Request for buffer overload received (%d + %d > %d\n", me, count, buffer->used, buffer->size);
+      sprintf(mp3asm_log.buf, "%s: Request for buffer overload received (%d + %d > %d\n", me, count, buffer->used, buffer->size);
       print_all (-1);
       return (-1);
     }
@@ -507,7 +507,7 @@ write_buf (unsigned char *data, buffer_t *buffer, int 
 	count1 = buffer->size - buffer->end;
 
 #ifdef DEBUG_BUFFER      
-      sprintf (log.buf, "BUFFER: Reading %d from data (%p) to buffer (@%d from %d/%d) \n", count1, data, buffer->end, buffer->used, buffer->size);
+      sprintf (mp3asm_log.buf, "BUFFER: Reading %d from data (%p) to buffer (@%d from %d/%d) \n", count1, data, buffer->end, buffer->used, buffer->size);
       print_log (10);
 #endif /* DEBUG_BUFFER */      
       
@@ -522,7 +522,7 @@ write_buf (unsigned char *data, buffer_t *buffer, int 
     }    
   
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: 2) begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
+  sprintf(mp3asm_log.buf, "BUFFER: 2) begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
 
@@ -548,7 +548,7 @@ print_buf (buffer_t *buffer, int count)
     {
       while (count1)
 	{
-	  fprintf (log.file, "%x", *ptr);
+	  fprintf (mp3asm_log.file, "%x", *ptr);
 	  count1 --;
 	  count --;
 	  ptr ++;
@@ -557,7 +557,7 @@ print_buf (buffer_t *buffer, int count)
 	  ptr = buffer->data;
       count1 = count;
     }
-  fprintf (log.file, "\n");
+  fprintf (mp3asm_log.file, "\n");
   
   return (1);
 }
@@ -587,14 +587,14 @@ write_file_from_buf (buffer_t *buffer, FILE *file, int
 		continue;
 	      else
 		{
-		  sprintf (log.buf, "%s: Error writing from buffer to file.\n", me);
+		  sprintf (mp3asm_log.buf, "%s: Error writing from buffer to file.\n", me);
 		  print_all (-1);
 		  perror ("fwrite");
 		  return (-1);
 		}
 	    }
 #ifdef DEBUG_BUFFER
-	  sprintf (log.buf, "BUFFER: writing to file from buffer: %d \n", writeb);
+	  sprintf (mp3asm_log.buf, "BUFFER: writing to file from buffer: %d \n", writeb);
 	  print_log (10);
 #endif /* DEBUG_BUFFER */
 
@@ -609,7 +609,7 @@ write_file_from_buf (buffer_t *buffer, FILE *file, int
     }
 
 #ifdef DEBUG_BUFFER
-  sprintf(log.buf, "BUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
+  sprintf(mp3asm_log.buf, "BUFFER: begin: %d end: %d used: %d size: %d\n", buffer->begin, buffer->end, buffer->used, buffer->size);
   print_log (10);
 #endif /* DEBUG_BUFFER */
   
@@ -630,11 +630,11 @@ print_data (unsigned char *data, int count)
 
   while (count)
     {
-      fprintf (log.file, "%x", *ptr);
+      fprintf (mp3asm_log.file, "%x", *ptr);
       count --;
       ptr ++;
     }
-  fprintf (log.file, "\n");
+  fprintf (mp3asm_log.file, "\n");
   
   return (1);
 }
