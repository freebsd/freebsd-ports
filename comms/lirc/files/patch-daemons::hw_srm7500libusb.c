--- daemons/hw_srm7500libusb.c.orig
+++ daemons/hw_srm7500libusb.c
@@ -54,6 +54,23 @@
 #define USB_TIMEOUT (1000*10)
 #define CONTROL_BUFFERSIZE 128
 
+#ifndef HAVE_STRNLEN
+size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t ret = strlen(s);
+	return ret > maxlen ? maxlen : ret;
+}
+#endif
+
+#ifndef HAVE_STRCHRNUL
+char *strchrnul(const char *s, int ch)
+{
+	char *ret = strchr(s, ch);
+	return ret == NULL ? ((char *)s) + strlen(s) : ret;
+}
+#endif
+
 static int srm7500_init();
 static int srm7500_deinit();
 static char *srm7500_rec(struct ir_remote *remotes);
