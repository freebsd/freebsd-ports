--- Bonnie.c.orig	1996-08-29 01:23:49.000000000 +0900
+++ Bonnie.c	2009-08-21 23:05:39.000000000 +0900
@@ -25,6 +25,9 @@
 
 #include <unistd.h>
 #include <stdio.h>
+#if !defined(SysV)
+#include <stdlib.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <sys/types.h>
@@ -49,7 +52,7 @@
 #define Seeks (4000)
 #define UpdateSeek (10)
 #define SeekProcCount (3)
-#define Chunk (16384)
+#define Chunk (8192)
 
 /* labels for the tests, used as an array index */
 typedef enum
@@ -87,7 +90,7 @@
 static double last_cpustamp = 0.0;       /* for computing delta-t */
 static double last_timestamp = 0.0;      /* for computing delta-t */
 
-main(
+int main(
   int    argc,
   char * argv[])
 {
@@ -146,7 +149,7 @@
   /* size is in meg, rounded down to multiple of Chunk */
   size *= (1024 * 1024);
   size = Chunk * (size / Chunk);
-  fprintf(stderr, "File '%s', size: %ld\n", name, size);
+  fprintf(stderr, "File '%s', size: %lld\n", name, size);
 
   /* Fill up a file, writing it a char at a time with the stdio putc() call */
   fprintf(stderr, "Writing with putc()...");
@@ -167,7 +170,7 @@
 
   /* Now read & rewrite it using block I/O.  Dirty one word in each block */
   newfile(name, &fd, &stream, 0);
-  if (lseek(fd, (off_t) 0, 0) == (off_t) -1)
+  if (lseek(fd, (off_t) 0, SEEK_SET) == (off_t) -1)
     io_error("lseek(2) before rewrite");
   fprintf(stderr, "Rewriting...");
   timestamp();
@@ -179,7 +182,7 @@
     if (bufindex == Chunk / IntSize)
       bufindex = 0;
     buf[bufindex++]++;
-    if (lseek(fd, (off_t) -words, 1) == -1)
+    if (lseek(fd, (off_t) -words, SEEK_CUR) == -1)
       io_error("relative lseek(2)");
     if (write(fd, (char *) buf, words) == -1)
       io_error("re write(2)");
@@ -235,7 +238,7 @@
 
   /* Now suck it in, Chunk at a time, as fast as we can */
   newfile(name, &fd, &stream, 0);
-  if (lseek(fd, (off_t) 0, 0) == -1)
+  if (lseek(fd, (off_t) 0, SEEK_SET) == -1)
     io_error("lseek before read");
   fprintf(stderr, "Reading intelligently...");
   timestamp();
@@ -288,6 +291,7 @@
     { /* child process */
 
       /* set up and wait for the go-ahead */
+      close(0);
       close(seek_feedback[0]);
       close(seek_control[1]);
       newfile(name, &fd, &stream, 0);
@@ -303,7 +307,12 @@
       /* loop until we read a 0 ticket back from our parent */
       while(seek_tickets[0])
       { /* until Mom says stop */
-        doseek((long) (random() % (size / Chunk)), fd,
+        off_t seekto;
+        if (size / Chunk < (1 << 25))
+          seekto = random() % (size / Chunk);
+        else
+          seekto = (((off_t)random() << 31) + random()) % (size / Chunk);
+        doseek(seekto, fd,
 	  ((lseek_count++ % UpdateSeek) == 0));
 	if (read(seek_control[0], seek_tickets, 1) != 1)
 	  io_error("read ticket");
@@ -413,7 +422,7 @@
   printf("K/sec %%CPU K/sec %%CPU K/sec %%CPU K/sec %%CPU K/sec ");
   printf("%%CPU  /sec %%CPU\n");
 
-  printf("%-8.8s %4d ", machine, size / (1024 * 1024));
+  printf("%-8.8s %4lld ", machine, size / (1024 * 1024));
   printf("%5d %4.1f %5d %4.1f %5d %4.1f ",
     (int) (((double) size) / (delta[(int) Putc][Elapsed] * 1024.0)),
     delta[(int) Putc][CPU] / delta[(int) Putc][Elapsed] * 100.0,
@@ -529,7 +538,10 @@
 {
   char buf[Chunk];
 
-  sprintf(buf, "Bonnie: drastic I/O error (%s)", message);
+  if((errno == EOVERFLOW) || (errno == EFBIG))
+    sprintf(buf, "\nBonnie: drastic I/O error (%s): %s", message, strerror(errno));
+  else
+    sprintf(buf, "\nBonnie: drastic I/O error (%s)", message);
   perror(buf);
   exit(1);
 }
@@ -557,7 +569,7 @@
   off_t size;
 
   probe = where * Chunk;
-  if (lseek(fd, probe, 0) != probe)
+  if (lseek(fd, (off_t)probe, SEEK_SET) != probe)
     io_error("lseek in doseek");
   if ((size = read(fd, (char *) buf, Chunk)) == -1)
     io_error("read in doseek");
@@ -568,7 +580,7 @@
 
     /* touch a word */
     buf[((int) random() % (size/IntSize - 2)) + 1]--;
-    if (lseek(fd, (long) probe, 0) != probe)
+    if (lseek(fd, (off_t)probe, SEEK_SET) != probe)
       io_error("lseek in doseek update");
     if (write(fd, (char *) buf, size) == -1)
       io_error("write in doseek");
