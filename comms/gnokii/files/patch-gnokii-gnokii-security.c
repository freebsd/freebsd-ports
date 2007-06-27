--- gnokii/gnokii-security.c.orig	Thu May 10 20:50:16 2007
+++ gnokii/gnokii-security.c	Thu Jun 21 11:56:13 2007
@@ -131,12 +131,14 @@
 
 	if (isatty(fd)) {
 		strncpy(pass, getpass(prompt), length - 1);
+/*		FreeBSD uses standard C library, no getline, sorry.
 	} else {
 		err = getline(&s, &s_len, stdin);
 		if (err > 0 && s) {
 			strncpy(pass, s, length - 1);
 			free(s);
 		}
+*/
 	}
 	pass[length - 1] = 0;
 #endif
