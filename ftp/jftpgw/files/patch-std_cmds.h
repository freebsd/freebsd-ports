--- ./std_cmds.h.orig	2009-07-17 00:00:04.686943825 -0400
+++ ./std_cmds.h	2009-07-17 00:00:25.530073049 -0400
@@ -42,6 +42,7 @@
 	{ "QUIT", std_quit },
 	{ "LIST", std_list },
 	{ "NLST", std_list },
+    { "MLSD", std_list },
 	{ 0, 0 }
 };
 
