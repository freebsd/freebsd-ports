--- hfterm/src/main.c.orig	Mon Jul 31 15:52:06 2006
+++ hfterm/src/main.c	Mon Jul 31 15:52:49 2006
@@ -533,7 +533,12 @@
 	struct hfapp_msg msg;
 
 	system("cd");
+#ifdef __linux__
 	system("if ! [ -d hf ] ; then mkdir hf; cp -ruv /usr/share/hf/hf-examplefiles/* hf; fi");
+#endif
+#ifdef __FreeBSD__
+	system("if ! [ -d hf ] ; then mkdir hf; cp -v /usr/local/share/hf/hf-examplefiles/* hf; fi");
+#endif
 	sprintf(versioninfo,  "hfterm %s by Tom Sailer, Axel Krause, "
 	    "Günther Montag, Pawel Jalocha et al. ", VERSION);
 	display_status(versioninfo);
