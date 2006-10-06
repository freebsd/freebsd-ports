--- pty_termios.c.orig	Fri May  7 17:46:03 2004
+++ pty_termios.c	Fri Oct  6 01:17:48 2006
@@ -166,7 +166,7 @@
 static char	*slave_bank;
 static char	*slave_num;
 #else
-static char	banks[] = "pqrstuvwxyzPQRSTUVWXYZ";
+static char	banks[] = "pqrsPQRS";	/* FreeBSD scheme */
 static char	master_name[] = "/dev/ptyXX";
 static char	slave_name [] = "/dev/ttyXX";
 #endif /* HAVE_PTYM */
@@ -489,7 +489,7 @@
 		*tty_bank = *bank;
 		*tty_num = '0';
 		if (stat(master_name, &stat_buf) < 0) break;
-		for (hex = "0123456789abcdef";*hex;hex++) {
+		for (hex = "0123456789abcdefghijklmnopqrstuv";*hex;hex++) {
 			*tty_num = *hex;
 			strcpy(slave_name,master_name);
 			*tty_type = 't';
