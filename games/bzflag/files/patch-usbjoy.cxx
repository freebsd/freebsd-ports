--- src/platform/usbjoy.cxx	Wed Sep 18 22:28:34 2002
+++ src/platform/usbjoy.cxx.new	Wed Sep 18 22:28:22 2002
@@ -46,14 +46,14 @@
 	int data_buf_offset;
 };
 
-usb_joystick *stick;
+usb_joystick *stick=NULL;
 
 usb_joystick::usb_joystick(const char *name)
 {
 	report_desc_t rd;
 	hid_data *d;
 	hid_item h;
-	int report_id;
+	hid_kind_t k;
 
 	status = FALSE;
 	hids = NULL;
@@ -67,11 +67,12 @@
 		return;
 	}
 
-	data_buf_size = hid_report_size(rd, hid_input, &report_id);
+	k = hid_input;
+	data_buf_size = hid_report_size(rd, hid_input, k);
 	if ((data_buf = (char *)malloc(data_buf_size)) == NULL) {
 		hid_dispose_report_desc(rd);
 	}
-	data_buf_offset = (report_id != 0);
+	data_buf_offset = 0;
 
 	int is_joystick = 0;
 	int interesting_hid = FALSE;
