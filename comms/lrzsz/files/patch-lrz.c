--- src/lrz.c.orig	1998-12-30 07:49:24 UTC
+++ src/lrz.c
@@ -494,6 +494,8 @@ main(int argc, char *argv[])
 		usage(2,_("garbage on commandline"));
 	if (protocol!=ZM_XMODEM && npats)
 		usage(2, _("garbage on commandline"));
+	if (protocol==ZM_XMODEM && !npats)
+		usage(2, _("need a file name to receive"));
 	if (Restricted && allow_remote_commands) {
 		allow_remote_commands=FALSE;
 	}
@@ -1159,9 +1161,9 @@ procheader(char *name, struct zm_fileinf
 
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
