--- ../../src/main.c.orig	2010-05-15 12:15:25.000000000 +0200
+++ ../../src/main.c	2010-05-15 12:16:53.000000000 +0200
@@ -500,7 +500,7 @@
 
 /* we have to have it here, before we junp back because of missing config file */
 
-    strcpy(options.metaserver, "damn.informatik.uni-bremen.de");
+    strcpy(options.metaserver, "www.daimonin.com");
     options.metaserver_port = DEFAULT_METASERVER_PORT;
 
     txtwin_start_size = txtwin[TW_MIX].size;
