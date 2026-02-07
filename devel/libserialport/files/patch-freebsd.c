--- freebsd.c.orig	2017-04-29 08:27:51 UTC
+++ freebsd.c
@@ -326,9 +326,8 @@ SP_PRIV enum sp_return list_ports(struct sp_port ***li
 {
 	DIR *dir;
 	struct dirent *entry;
-	struct termios tios;
 	char name[PATH_MAX];
-	int fd, ret;
+	int ret;
 
 	DEBUG("Enumerating tty devices");
 	if (!(dir = opendir("/dev")))
@@ -352,21 +351,10 @@ SP_PRIV enum sp_return list_ports(struct sp_port ***li
 		DEBUG_FMT("Found device %s", name);
 
 		/* Check that we can open tty/cua device in rw mode - we need that. */
-		if ((fd = open(name, O_RDWR | O_NONBLOCK | O_NOCTTY | O_TTY_INIT | O_CLOEXEC)) < 0) {
-			DEBUG("Open failed, skipping");
+		if (access(name, R_OK | W_OK) != 0) {
+			DEBUG("access(2) check failed, skipping");
 			continue;
 		}
-
-		/* Sanity check if we got a real tty. */
-		if (!isatty(fd)) {
-			close(fd);
-			continue;
-		}
-
-		ret = tcgetattr(fd, &tios);
-		close(fd);
-		if (ret < 0 || cfgetospeed(&tios) <= 0 || cfgetispeed(&tios) <= 0)
-			continue;
 
 		DEBUG_FMT("Found port %s", name);
 		DBG("%s: %s\n", __func__, entry->d_name);
