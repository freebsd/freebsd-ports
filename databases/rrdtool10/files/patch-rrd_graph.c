--- src/rrd_graph.c.orig	Fri May  7 15:10:16 2004
+++ src/rrd_graph.c	Fri May  7 15:10:34 2004
@@ -2966,7 +2966,7 @@
 
 	
 	opt = getopt_long(argc, argv, 
-			  "s:e:x:y:v:w:h:iu:l:rb:oc:t:f:a:zgjFYAMXL:S:RB:O:U:",
+			  "s:e:x:y:v:w:h:iu:l:rb:oc:t:f:a:zgjFYNAMX:L:S:RB:O:U:",
 			  long_options, &option_index);
 
 	if (opt == EOF)
