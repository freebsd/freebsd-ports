Index: interface/interface.c
===================================================================
RCS file: /home/cvs/cdparanoia/interface/interface.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -r1.1.1.1 -r1.3
--- interface/interface.c	2003/01/05 09:46:26	1.1.1.1
+++ interface/interface.c	2003/01/06 21:26:23	1.3
@@ -29,12 +29,25 @@
       d->enable_cdda(d,0);
 
     _clean_messages(d);
+#ifdef Linux
     if(d->cdda_device_name)free(d->cdda_device_name);
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
