--- libevdev/libevdev-uinput.c.orig	2017-05-04 00:37:30 UTC
+++ libevdev/libevdev-uinput.c
@@ -182,6 +182,7 @@ libevdev_uinput_get_fd(const struct libevdev_uinput *u
 	return uinput_dev->fd;
 }
 
+#if defined(linux)
 static int is_event_device(const struct dirent *dent) {
 	return strncmp("event", dent->d_name, 5) == 0;
 }
@@ -213,10 +214,12 @@ fetch_device_node(const char *path)
 static int is_input_device(const struct dirent *dent) {
 	return strncmp("input", dent->d_name, 5) == 0;
 }
+#endif
 
 static int
 fetch_syspath_and_devnode(struct libevdev_uinput *uinput_dev)
 {
+#if defined(linux)
 	struct dirent **namelist;
 	int ndev, i;
 	int rc;
@@ -290,6 +293,16 @@ fetch_syspath_and_devnode(struct libevdev_uinput *uinp
 	free(namelist);
 
 	return uinput_dev->devnode ? 0 : -1;
+#elif defined(__FreeBSD__)
+	char devnode[80];
+	if (ioctl(uinput_dev->fd, UI_GET_SYSNAME(sizeof(devnode)), devnode) < 0)
+		return -1;
+	asprintf(&uinput_dev->devnode, "/dev/input/%s", devnode);
+	uinput_dev->syspath = strdup(uinput_dev->devnode);
+	return 0;
+#else
+	return -1;
+#endif
 }
 
 static int
