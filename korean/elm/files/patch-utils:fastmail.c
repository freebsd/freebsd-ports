--- utils/fastmail.c.orig	Sat Nov 23 21:33:32 2002
+++ utils/fastmail.c	Sat Nov 23 21:35:03 2002
@@ -105,7 +105,7 @@
 static void usage();
 
 int debug = 0;
-FILE *debugfile = stderr;
+FILE *debugfile;
 
 
 main(argc, argv)
@@ -123,6 +123,8 @@
 	char references[SLEN];
 	char *p;
 	int  c, sendmail_available;
+
+	debugfile = stderr;
 
 	elm_msg_cat = catopen("elm2.4", 0);
 
