--- src/support/dialogs.cxx.orig	2023-10-11 20:05:33 UTC
+++ src/support/dialogs.cxx
@@ -179,7 +179,7 @@ void init_port_combos()
 			add_combos(gbuf.gl_pathv[j]);
 	}
 	globfree(&gbuf);
-
+#ifndef __FreeBSD__
 	glob("/dev/serial/by-id/*", 0, NULL, &gbuf);
 	for (size_t j = 0; j < gbuf.gl_pathc; j++) {
 		if ( !(stat(gbuf.gl_pathv[j], &st) == 0 && S_ISCHR(st.st_mode)) ||
@@ -189,7 +189,7 @@ void init_port_combos()
 			add_combos(gbuf.gl_pathv[j]);
 	}
 	globfree(&gbuf);
-
+#endif
 	glob("/dev/tty*", 0, NULL, &gbuf);
 	for (size_t j = 0; j < gbuf.gl_pathc; j++) {
 		if ( !(stat(gbuf.gl_pathv[j], &st) == 0 && S_ISCHR(st.st_mode)) ||
@@ -296,9 +296,15 @@ out:
 	}
 
 	const char* tty_fmt[] = {
-		"/dev/ttyS%u",
+#ifndef __FreeBSD__
 		"/dev/ttyUSB%u",
+		"/dev/ttyS%u",
 		"/dev/usb/ttyUSB%u"
+#endif
+#ifdef __FreeBSD__
+		"/dev/cuau%u",
+		"/dev/cuaU%u",
+#endif
 	};
 	LOG_QUIET("%s", "Serial port discovery via 'stat'");
 	for (size_t i = 0; i < sizeof(tty_fmt)/sizeof(*tty_fmt); i++) {
