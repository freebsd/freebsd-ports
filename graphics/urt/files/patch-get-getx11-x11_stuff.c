--- get/getx11/x11_stuff.c.orig	Fri May 13 20:05:44 1994
+++ get/getx11/x11_stuff.c	Thu Nov 29 22:48:26 2007
@@ -40,7 +40,7 @@
  */
 #include "getx11.h"
 #ifdef X_SHARED_MEMORY
-#include <sys/errno.h>
+#include <errno.h>
 #endif
 
 #include "circle.bitmap"
@@ -155,7 +155,6 @@
 			IPC_CREAT|0777 );
 	    if ( img->shm_img.shmid < 0 )
 	    {
-		extern int errno;
 		if ( errno == ENOSPC )
 		{
 		    if ( !no_shared_space )
@@ -333,7 +332,7 @@
     
     if (( img->pixmap != NULL && reallocate ) ||
 	( img->pixmap != NULL && (img->pix_w < iw || img->pix_h < ih ))){
-	free_X_pixmap( dpy, img->pixmap );
+	free_X_pixmap( img, img->pixmap );
 	img->pixmap = NULL;
     }
     
@@ -361,7 +360,6 @@
 	    XDestroyImage( image );
 	    if ( img->shm_pix.shmid < 0 )
 	    {
-		extern int errno;
 		if ( errno == ENOSPC )
 		{
 		    if ( !no_shared_space )
