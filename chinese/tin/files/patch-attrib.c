--- src/attrib.c.orig	2014-07-16 00:41:51.940655746 +0800
+++ src/attrib.c	2014-07-16 00:43:36.205651630 +0800
@@ -583,6 +583,9 @@
 		add_scope("*");
 		snprintf(buf, sizeof(buf), "%s", "~/.tin/headers");
 		set_attrib(OPT_ATTRIB_X_HEADERS, "*", "", buf);
+		num = 25;
+		set_attrib(OPT_ATTRIB_MM_NETWORK_CHARSET, "*", "", (char *) &num);
+		set_attrib(OPT_ATTRIB_UNDECLARED_CHARSET, "*", "", "Big5");
 
 		add_scope("*sources*");
 		num = POST_PROC_SHAR;
