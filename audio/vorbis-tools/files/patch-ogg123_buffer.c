$FreeBSD$
--- ogg123/buffer.c.orig	Tue Jan 30 11:42:48 2001
+++ ogg123/buffer.c	Sat Mar 17 17:12:02 2001
@@ -6,17 +6,16 @@
  */
 
 #include <sys/types.h>
+#if HAVE_SMMAP
+#include <sys/mman.h>
+#else
 #include <sys/ipc.h>
 #include <sys/shm.h>
-#include <sys/stat.h>
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
 
@@ -73,10 +72,26 @@ buf_t *fork_writer (long size, devices_t
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
-			  IPC_CREAT|S_IREAD|S_IWRITE);
+			  IPC_CREAT|SHM_R|SHM_W);
 
   if (shmid == -1)
     {
@@ -92,7 +107,11 @@ buf_t *fork_writer (long size, devices_t
       perror ("shmat");
       exit (1);
     }
-  
+
+  /* Remove segment after last process detaches it or terminates. */
+  shmctl(shmid, IPC_RMID, 0);
+#endif /* HAVE_SMMAP */
+
   buffer_init (buf, size);
   
   /* Create a pipe for communication between the two processes. Unlike
