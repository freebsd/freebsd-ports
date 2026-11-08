Obtained from:	https://lists.libreplanet.org/archive/html/qemu-devel/2026-10/msg04558.html

--- qga/channel-posix.c.orig
+++ qga/channel-posix.c
@@ -156,9 +156,10 @@ static gboolean ga_channel_open(GAChannel *c, const gchar *path,
 #endif
 #ifdef __FreeBSD__
         /*
-         * In the default state channel sends echo of every command to a
-         * client. The client program doesn't expect this and raises an
-         * error. Suppress echo by resetting ECHO terminal flag.
+         * FreeBSD's virtio-console port is a tty (unlike Linux's
+         * /dev/virtio-ports, which is a character device) and defaults to
+         * canonical mode with echo and software flow control enabled.
+         * QGA uses a raw stream protocol, so put the port in raw mode.
          */
         struct termios tio;
         if (tcgetattr(fd, &tio) < 0) {
@@ -166,8 +167,19 @@ static gboolean ga_channel_open(GAChannel *c, const gchar *path,
             close(fd);
             return false;
         }
-        tio.c_lflag &= ~ECHO;
-        if (tcsetattr(fd, TCSAFLUSH, &tio) < 0) {
+        tio.c_iflag &= ~(IGNBRK | BRKINT | IGNPAR | PARMRK | INPCK | ISTRIP |
+                         INLCR | IGNCR | ICRNL | IXON | IXOFF | IXANY |
+                         IMAXBEL);
+        tio.c_oflag = 0;
+        tio.c_lflag = 0;
+        tio.c_cflag |= CLOCAL | CREAD;
+        tio.c_cc[VMIN] = 1;
+        tio.c_cc[VTIME] = 0;
+        /*
+         * Use TCSANOW rather than TCSAFLUSH: the host may already have sent
+         * the initial handshake between open() and tcsetattr().
+         */
+        if (tcsetattr(fd, TCSANOW, &tio) < 0) {
             error_setg_errno(errp, errno, "error setting channel termios attrs");
             close(fd);
             return false;
