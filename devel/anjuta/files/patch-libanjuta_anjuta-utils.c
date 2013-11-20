--- libanjuta/anjuta-utils.c.orig	2012-06-16 20:02:59.000000000 +0200
+++ libanjuta/anjuta-utils.c	2012-06-16 20:04:17.000000000 +0200
@@ -1060,8 +1060,8 @@
 	const gchar shells [][14] = {
 		/* Note that on some systems shells can also
 		 * be installed in /usr/bin */
-		"/bin/bash", "/usr/bin/bash",
-		"/bin/zsh", "/usr/bin/zsh",
+		"/bin/bash", "/usr/bin/bash", "%%LOCALBASE%%/bin/bash",
+		"/bin/zsh", "/usr/bin/zsh", "%%LOCALBASE%%/bin/zsh",
 		"/bin/tcsh", "/usr/bin/tcsh",
 		"/bin/ksh", "/usr/bin/ksh",
 		"/bin/csh", "/bin/sh"
