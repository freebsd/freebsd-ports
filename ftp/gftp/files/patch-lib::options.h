--- lib/options.h.orig	Wed Apr 23 22:50:37 2003
+++ lib/options.h	Wed Apr 23 22:51:13 2003
@@ -26,9 +26,13 @@
   {"FTP", 	rfc959_init, 	"ftp",		1},
   {"HTTP", 	rfc2068_init, 	"http",		1},
   {"Local", 	local_init, 	"file",		1},
+#ifdef WITH_SSH
   {"SSH2",	sshv2_init,	"ssh2", 	1},
+#endif
   {"Bookmark", 	bookmark_init, 	"bookmark", 	0},
+#ifdef WITH_SSH
   {"SSH", 	ssh_init, 	"ssh", 		1},
+#endif
   {NULL, 	NULL, 		NULL,		0}
 };
 
