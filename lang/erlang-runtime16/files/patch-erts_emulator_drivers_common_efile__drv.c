--- erts/emulator/drivers/common/efile_drv.c.orig
+++ erts/emulator/drivers/common/efile_drv.c
@@ -1938,6 +1938,8 @@
 	d->result_ok = 1;
 	if (d->c.sendfile.nbytes != 0)
 	  d->c.sendfile.nbytes -= nbytes;
+      } else if (nbytes == 0 && d->c.sendfile.nbytes == 0) {
+	d->result_ok = 1;
       } else
 	d->result_ok = 0;
     } else {
