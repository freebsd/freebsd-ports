--- sdriqpkg/sdriq.c.orig	2018-08-02 14:01:30 UTC
+++ sdriqpkg/sdriq.c
@@ -629,14 +658,14 @@ static void quisk_open_sdriq_dev(const c
 {
     struct termios newtio;
 
-	if (!strncmp(name, "/dev/ttyUSB", 11)) {	// use ftdi_sio driver
-		quisk_sdriq_fd = open(name, O_RDWR | O_NOCTTY);
-		if (quisk_sdriq_fd < 0) {
-			strncpy(buf, "Open SDR-IQ : ", bufsize);
-			strncat(buf, strerror(errno), bufsize - strlen(buf) - 1);
-			quisk_sdriq_fd = INVALID_HANDLE_VALUE;
-			return;
-		}
+	quisk_sdriq_fd = open(name, O_RDWR | O_NOCTTY | O_NONBLOCK);
+	if (quisk_sdriq_fd < 0) {
+		strncpy(buf, "Open SDR-IQ : ", bufsize);
+		strncat(buf, strerror(errno), bufsize - strlen(buf) - 1);
+		quisk_sdriq_fd = INVALID_HANDLE_VALUE;
+		return;
+	}
+	if (isatty(quisk_sdriq_fd)) {
 		bzero(&newtio, sizeof(newtio));
 		newtio.c_cflag = CS8 | CLOCAL | CREAD;
 		newtio.c_iflag = IGNPAR;
@@ -649,15 +678,6 @@ static void quisk_open_sdriq_dev(const c
 		tcflush(quisk_sdriq_fd, TCIFLUSH);
 		tcsetattr(quisk_sdriq_fd, TCSANOW, &newtio);
 	}
-	else {		// use ft245 or similar driver
-		quisk_sdriq_fd = open(name, O_RDWR | O_NONBLOCK); 
-		if (quisk_sdriq_fd < 0) {
-			strncpy(buf, "Open SDR-IQ: ", bufsize);
-			strncat(buf, strerror(errno), bufsize - strlen(buf) - 1);
-			quisk_sdriq_fd = INVALID_HANDLE_VALUE;
-			return;
-		}
-	}
 	return;
 }
 #endif
