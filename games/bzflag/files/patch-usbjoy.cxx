--- src/platform/usbjoy.cxx.orig	Tue Jun  4 02:39:32 2002
+++ src/platform/usbjoy.cxx	Sun May  4 14:36:38 2003
@@ -46,7 +46,7 @@
 	int data_buf_offset;
 };
 
-usb_joystick *stick;
+usb_joystick *stick=NULL;
 
 usb_joystick::usb_joystick(const char *name)
 {
@@ -58,6 +58,7 @@
 	status = FALSE;
 	hids = NULL;
 	num_axis = 0;
+	report_id = 0;
 
 	if ((fd = open(name, O_RDONLY | O_NONBLOCK))<0)
 		return;
@@ -67,15 +68,27 @@
 		return;
 	}
 
+#if (__FreeBSD_version >= 470000)
+# if (__FreeBSD_version >= 500111)
+	data_buf_size = hid_report_size(rd, hid_input, report_id);
+# else
+	data_buf_size = hid_report_size(rd, report_id, hid_input);
+# endif
+#else
 	data_buf_size = hid_report_size(rd, hid_input, &report_id);
+#endif
 	if ((data_buf = (char *)malloc(data_buf_size)) == NULL) {
 		hid_dispose_report_desc(rd);
 	}
-	data_buf_offset = (report_id != 0);
+	data_buf_offset = 0;
 
 	int is_joystick = 0;
 	int interesting_hid = FALSE;
+#if (__FreeBSD_version >= 500111)
+	for (d = hid_start_parse(rd, 1 << hid_input, report_id); hid_get_item(d, &h); ) {
+#else
 	for (d = hid_start_parse(rd, 1 << hid_input); hid_get_item(d, &h); ) {
+#endif
 		int page = HID_PAGE(h.usage);
 		int usage = HID_USAGE(h.usage);
 		is_joystick = is_joystick ||
