--- src/rrd_graph.c.orig	Sun Aug  8 14:58:13 2004
+++ src/rrd_graph.c	Sun Aug  8 18:19:06 2004
@@ -2966,7 +2966,7 @@
 
 	
 	opt = getopt_long(argc, argv, 
-			  "s:e:x:y:v:w:h:iu:l:rb:oc:t:f:a:zgjFYAMX:L:S:RB:O:U:",
+			  "s:e:x:y:v:w:h:iu:l:rb:oc:t:f:a:zgjFYAMNX:L:S:RB:O:U:",
 			  long_options, &option_index);
 
 	if (opt == EOF)
