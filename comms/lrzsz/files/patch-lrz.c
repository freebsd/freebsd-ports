--- src/lrz.c.orig	1998-12-30 08:49:24.000000000 +0100
+++ src/lrz.c	2010-01-14 09:33:32.000000000 +0100
@@ -494,6 +494,8 @@
 		usage(2,_("garbage on commandline"));
 	if (protocol!=ZM_XMODEM && npats)
 		usage(2, _("garbage on commandline"));
+	if (protocol==ZM_XMODEM && !npats)
+		usage(2, _("need a file name to receive"));
 	if (Restricted && allow_remote_commands) {
 		allow_remote_commands=FALSE;
 	}
@@ -1159,9 +1161,9 @@
 
 	nameend = name + 1 + strlen(name);
 	if (*nameend) {	/* file coming from Unix or DOS system */
-		long modtime;
-		long bytes_total;
-		int mode;
+		long modtime=0;
+		long bytes_total=DEFBYTL;
+		int mode=0;
 		sscanf(nameend, "%ld%lo%o", &bytes_total, &modtime, &mode);
 		zi->modtime=modtime;
 		zi->bytes_total=bytes_total;
