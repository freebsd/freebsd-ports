--- src/attrib.c.orig	2015-11-22 01:14:29.000000000 +0100
+++ src/attrib.c	2016-02-21 20:49:48.322143000 +0100
@@ -593,6 +593,9 @@
 		add_scope("*");
 		snprintf(buf, sizeof(buf), "%s", "~/.tin/headers");
 		set_attrib(OPT_ATTRIB_X_HEADERS, "*", "", buf);
+		num = 25;
+		set_attrib(OPT_ATTRIB_MM_NETWORK_CHARSET, "*", "", (char *) &num);
+		set_attrib(OPT_ATTRIB_UNDECLARED_CHARSET, "*", "", "Big5");
 
 		add_scope("*sources*");
 		num = POST_PROC_SHAR;
