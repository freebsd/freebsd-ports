--- fowsr.c.orig	2016-07-26 12:57:00 UTC
+++ fowsr.c
@@ -110,13 +110,17 @@ int CUSB_Open(int vendor, int product)
 
 	signal(SIGTERM, release_usb_device);
 
+#ifdef LIBUSB_HAS_GET_DRIVER_NP
 	ret = usb_get_driver_np(devh, 0, buf, sizeof(buf));
 	printf("usb_get_driver_np returned %d\n", ret);
 	if (ret == 0) {
 		printf("interface 0 already claimed by driver \\'%s\\', attempting to detach it\n", buf);
+#ifdef LIBUSB_HAS_DETACH_KERNEL_DRIVER_NP
 		ret = usb_detach_kernel_driver_np(devh, 0);
 		printf("usb_detach_kernel_driver_np returned %d\n", ret);
+#endif
 	}
+#endif
 	ret = usb_claim_interface(devh, 0);
 	if (ret != 0) {
 		printf("claim failed with error %d\n", ret);
@@ -159,12 +163,14 @@ void CWS_Cache(char isStoring)
 	FILE* f;
 	if (isStoring == ISREADING) {
 		if (f=fopen(fname,"rb")) {
+			printf("using cache file %s\n", fname);
 			n=fread(&m_previous_timestamp,sizeof(m_previous_timestamp),1,f);
 			n=fread(m_buf,sizeof(m_buf[0]),WS_BUFFER_SIZE,f);
 		}
 		print_bytes((char *)&m_previous_timestamp, sizeof(time_t));
 	} else {	// ISWRITING
 		if (f=fopen(fname,"wb")) {
+			printf("updating cache file %s\n", fname);
 			n=fwrite(&m_timestamp,sizeof(m_timestamp),1,f);
 			n=fwrite(m_buf,sizeof(m_buf[0]),WS_BUFFER_SIZE,f);
 		}
@@ -566,6 +572,7 @@ int CWF_Write(char arg,char* fname)
 
 	FILE* f;
 	if (f=fopen(fname,"a+s")) {
+		printf("writing to %s\n", fname);
 
 		// Header
 		switch (arg) {
