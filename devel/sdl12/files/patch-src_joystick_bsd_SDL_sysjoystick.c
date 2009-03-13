--- src/joystick/bsd/SDL_sysjoystick.c.orig	2009-03-12 22:54:57.000000000 +0100
+++ src/joystick/bsd/SDL_sysjoystick.c	2009-03-12 23:04:53.000000000 +0100
@@ -74,6 +74,13 @@
 #define MAX_JOY_JOYS	2
 #define MAX_JOYS	(MAX_UHID_JOYS + MAX_JOY_JOYS)
 
+#if defined(__FREEBSD__) && (__FreeBSD_version > 800063)
+struct usb_ctl_report {
+	int	ucr_report;
+	u_char	ucr_data[1024]; /* filled data size will vary */
+};
+#endif
+
 struct report {
 	struct	usb_ctl_report *buf;	/* Buffer */
 	size_t	size;			/* Buffer size */
@@ -137,7 +144,7 @@
 static int	report_alloc(struct report *, struct report_desc *, int);
 static void	report_free(struct report *);
 
-#ifdef USBHID_UCR_DATA
+#if defined(USBHID_UCR_DATA) || (defined(__FREEBSD__) && (__FreeBSD_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
 #else
 #define REP_BUF_DATA(rep) ((rep)->buf->data)
@@ -292,9 +299,13 @@
 		    strerror(errno));
 		goto usberr;
 	}
-
+#if defined(__FREEBSD__) && (__FreeBSD_version > 800063)
+       rep->rid = hid_get_report_id(fd);
+       if (rep->rid < 0) {
+#else
 	rep = &hw->inreport;
 	if (ioctl(fd, USB_GET_REPORT_ID, &rep->rid) < 0) {
+#endif
 		rep->rid = -1; /* XXX */
 	}
 	if (report_alloc(rep, hw->repdesc, REPORT_INPUT) < 0) {
