--- interface/interface.c.orig	2008-09-11 10:43:52 UTC
+++ interface/interface.c
@@ -35,10 +35,17 @@ int cdda_close(cdrom_drive *d){
 
     _clean_messages(d);
     if(d->cdda_device_name)free(d->cdda_device_name);
+#ifdef Linux
     if(d->ioctl_device_name)free(d->ioctl_device_name);
     if(d->drive_model)free(d->drive_model);
     if(d->cdda_fd!=-1)close(d->cdda_fd);
     if(d->ioctl_fd!=-1 && d->ioctl_fd!=d->cdda_fd)close(d->ioctl_fd);
+#elif defined(__FreeBSD__)
+    if(d->drive_model)free(d->drive_model);
+    if(d->ccb)cam_freeccb(d->ccb);
+    if(d->dev)cam_close_device(d->dev);
+    if(d->ioctl_fd != -1)close(d->ioctl_fd);
+#endif
     if(d->private){
       if(d->private->sg_hd)free(d->private->sg_hd);
       free(d->private);
@@ -127,7 +134,12 @@ long cdda_read_timed(cdrom_drive *d, void *buffer, lon
 	}
       }	
     }
+#ifdef Linux
     if(ms)*ms=d->private->last_milliseconds;
+#elif defined(__FreeBSD__)
+    if(ms)
+      *ms = (d->private == NULL) ? 0 : d->private->last_milliseconds;
+#endif
     return(sectors);
   }
   
