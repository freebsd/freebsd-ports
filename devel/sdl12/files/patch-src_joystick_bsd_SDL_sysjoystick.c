--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 07:30:06.000000000 +0100
+++ src/joystick/bsd/SDL_sysjoystick.c	2012-07-21 10:09:16.000000000 +0200
@@ -82,7 +82,9 @@
 #define MAX_JOYS	(MAX_UHID_JOYS + MAX_JOY_JOYS)
 
 struct report {
-#if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063)
+#if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 900000)
+	void *buf;			/* Buffer */
+#elif defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063)
 	struct	usb_gen_descriptor *buf;	/* Buffer */
 #else
 	struct	usb_ctl_report *buf;	/* Buffer */
@@ -148,8 +150,10 @@
 static int	report_alloc(struct report *, struct report_desc *, int);
 static void	report_free(struct report *);
 
-#if defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
+#if defined(USBHID_UCR_DATA) || (defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version <= 800063)
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
+#elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 900000))
+#define REP_BUF_DATA(rep) ((rep)->buf)
 #elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
 #else
@@ -582,8 +586,12 @@
 	r->size = len;
 
 	if (r->size > 0) {
+#if defined(__FREEBSD__) && (__FreeBSD_kernel_version > 900000)
+		r->buf = SDL_malloc(r->size);
+#else
 		r->buf = SDL_malloc(sizeof(*r->buf) - sizeof(REP_BUF_DATA(r)) +
 		    r->size);
+#endif
 		if (r->buf == NULL) {
 			SDL_OutOfMemory();
 			return (-1);
