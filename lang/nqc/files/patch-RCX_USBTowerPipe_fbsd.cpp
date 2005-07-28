--- rcxlib/RCX_USBTowerPipe_fbsd.cpp.org	Mon Jun 13 21:36:21 2005
+++ rcxlib/RCX_USBTowerPipe_fbsd.cpp	Sun Jul  3 21:30:09 2005
@@ -224,6 +224,7 @@
 	while(length > 0) {
 		pfd.fd = fdRd;
 		pfd.events = POLLIN;
+		usleep(timeout_ms * 1000 / 8);
 		err = poll(&pfd, 1, timeout_ms);
 		if (err == 0)
 			break;
