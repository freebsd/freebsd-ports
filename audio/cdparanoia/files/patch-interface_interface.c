--- interface/interface.c.orig	2000-04-19 22:41:04 UTC
+++ interface/interface.c
@@ -30,11 +30,24 @@ int cdda_close(cdrom_drive *d){
 
     _clean_messages(d);
     if(d->cdda_device_name)free(d->cdda_device_name);
+#ifdef Linux
     if(d->ioctl_device_name)free(d->ioctl_device_name);
     if(d->drive_model)free(d->drive_model);
     if(d->cdda_fd!=-1)close(d->cdda_fd);
     if(d->ioctl_fd!=-1 && d->ioctl_fd!=d->cdda_fd)close(d->ioctl_fd);
     if(d->sg)free(d->sg);
+#elif defined(__FreeBSD__)
+    if (d->drive_model)
+	    free(d->drive_model);
+    if (d->ccb)
+	    cam_freeccb(d->ccb);
+    if (d->dev)
+	    cam_close_device(d->dev);
+    if (d->sg_buffer)
+	    free(d->sg_buffer);
+    if (d->ioctl_fd != -1)
+	    close(d->ioctl_fd);
+#endif
     
     free(d);
   }
