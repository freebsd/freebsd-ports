--- src/joystick/bsd/SDL_sysjoystick.c.orig	2010-02-05 11:17:18.000000000 +0100
+++ src/joystick/bsd/SDL_sysjoystick.c	2010-02-05 11:18:15.000000000 +0100
@@ -303,11 +303,12 @@
 		    strerror(errno));
 		goto usberr;
 	}
+
+	rep = &hw->inreport;
 #if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063)
        rep->rid = hid_get_report_id(fd);
        if (rep->rid < 0) {
 #else
-	rep = &hw->inreport;
 	if (ioctl(fd, USB_GET_REPORT_ID, &rep->rid) < 0) {
 #endif
 		rep->rid = -1; /* XXX */
