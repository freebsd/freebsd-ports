--- display/xshm.c.orig	Sat Feb  4 19:56:31 2006
+++ display/xshm.c	Sat Aug  5 00:51:20 2006
@@ -1,7 +1,6 @@
 #include <Python.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
-#include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/extensions/XShm.h>
@@ -111,10 +110,6 @@
 	
   /* Get memory address to segment: */
   img->m_shminfo.shmaddr = (char *) shmat(img->m_shminfo.shmid, 0, 0);
-
-  /* Mark the segment as destroyable (it will be destroyed when this
-     process terminates) */
-  shmctl(img->m_shminfo.shmid, IPC_RMID, NULL);
 
   /* Tell XServer that it may only read from it and attach to display: */
   img->m_shminfo.readOnly = True;
