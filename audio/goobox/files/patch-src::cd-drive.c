--- src/cd-drive.c.orig	Tue Nov  9 22:28:01 2004
+++ src/cd-drive.c	Wed Nov 10 23:02:08 2004
@@ -578,7 +578,49 @@
 
 #if defined(__linux__) || defined(__FreeBSD__)
 
+#if !defined(__linux__)
+static int
+get_device_max_read_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
+
+	max_speed = -1;
+
+	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+
+	get_read_write_speed (fd, &read_speed, &write_speed);
+	close (fd);
+	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
+
+	return max_speed;
+}
+#endif
 
+static int
+get_device_max_write_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
+
+	max_speed = -1;
+
+	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+
+	get_read_write_speed (fd, &read_speed, &write_speed);
+	close (fd);
+	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
+
+	return max_speed;
+}
 
 #endif /* __linux__ || __FreeBSD__ */
 
@@ -780,50 +822,6 @@
 		}
 	}
 	return NULL;
-}
-
-#if !defined(__linux)
-static int
-get_device_max_read_speed (char *device)
-{
-	int fd;
-	int max_speed;
-	int read_speed, write_speed;
-
-	max_speed = -1;
-
-	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
-
-	return max_speed;
-}
-#endif
-
-static int
-get_device_max_write_speed (char *device)
-{
-	int fd;
-	int max_speed;
-	int read_speed, write_speed;
-
-	max_speed = -1;
-
-	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
-
-	return max_speed;
 }
 
 static char *
