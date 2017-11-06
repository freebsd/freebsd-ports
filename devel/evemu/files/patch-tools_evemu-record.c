--- tools/evemu-record.c.orig	2016-03-01 14:10:40 UTC
+++ tools/evemu-record.c
@@ -209,6 +209,9 @@ out:
 	return rc;
 }
 
+/* Fix broken linux/input.h ioctl define found in multimedia/v4l_compat as of 2017-04-02 */
+#undef	EVIOCGRAB
+#define	EVIOCGRAB	_IOWINT('E', 0x90)
 static inline bool test_grab_device(int fd)
 {
 	if (ioctl(fd, EVIOCGRAB, (void*)1) < 0) {
