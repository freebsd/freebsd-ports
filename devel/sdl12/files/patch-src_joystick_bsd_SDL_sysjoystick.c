--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-28 12:07:18.000000000 +0100
+++ src/joystick/bsd/SDL_sysjoystick.c	2012-01-28 12:08:44.000000000 +0100
@@ -148,7 +148,7 @@
 static int	report_alloc(struct report *, struct report_desc *, int);
 static void	report_free(struct report *);
 
-#if defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
+#if defined(USBHID_UCR_DATA) || (defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version <= 800063)
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
 #elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
