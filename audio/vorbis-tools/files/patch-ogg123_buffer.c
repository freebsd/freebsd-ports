$FreeBSD$
--- ogg123/buffer.c.orig	Sat Jun 30 13:57:20 2001
+++ ogg123/buffer.c	Sat Jun 30 14:01:55 2001
@@ -6,16 +6,16 @@
  */
 
 #include <sys/types.h>
+#if HAVE_SMMAP
+#include <sys/mman.h>
+#else
 #include <sys/ipc.h>
 #include <sys/shm.h>
+#endif
 #include <sys/time.h>
 #include <unistd.h> /* for fork and pipe*/
 #include <fcntl.h>
 
-#ifndef DARWIN
-#include <malloc.h>
-#endif
-
 #include "ogg123.h"
 #include "buffer.h"
 
@@ -72,6 +72,22 @@ buf_t *fork_writer (long size, devices_t
   int childpid;
   buf_t *buf;
 
+#if HAVE_SMMAP
+  int fd;
+
+  if ((fd = open("/dev/zero", O_RDWR)) < 0)
+    {
+      perror ("cannot open /dev/zero");
+      exit (1);
+    }
+  if ((buf = (buf_t *) mmap (0, sizeof(buf_t) + sizeof (chunk_t) * (size - 1),
+                             PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) < 0)
+    {
+      perror("mmap");
+      exit(1);
+    }
+  close(fd);
+#else
   /* Get the shared memory segment. */
   int shmid = shmget (IPC_PRIVATE,
 			  sizeof(buf_t) + sizeof (chunk_t) * (size - 1),
@@ -94,6 +110,7 @@ buf_t *fork_writer (long size, devices_t
 
   /* Remove segment after last process detaches it or terminates. */
   shmctl(shmid, IPC_RMID, 0);
+#endif /* HAVE_SMMAP */
 
   buffer_init (buf, size);
   
