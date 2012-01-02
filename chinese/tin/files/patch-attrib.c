--- src/attrib.c.orig	2011-09-18 04:55:30.000000000 -0700
+++ src/attrib.c	2012-01-02 03:14:00.000000000 -0800
@@ -548,6 +548,9 @@
 		add_scope("*");
 		snprintf(buf, sizeof(buf), "%s", "~/.tin/headers");
 		set_attrib(OPT_ATTRIB_X_HEADERS, "*", "", buf);
+		num = 25;
+		set_attrib(OPT_ATTRIB_MM_NETWORK_CHARSET, "*", "", (char *) &num);
+		set_attrib(OPT_ATTRIB_UNDECLARED_CHARSET, "*", "", "Big5");
 
 		add_scope("*sources*");
 		num = POST_PROC_SHAR;
