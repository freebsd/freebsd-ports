--- src/other/inet2sim/inet2sim.c.orig	Sun Oct  8 13:27:47 2006
+++ src/other/inet2sim/inet2sim.c	Sun Oct  8 13:28:02 2006
@@ -22,6 +22,7 @@
 private	char	*inet_file = NULL;
 private	void	sort_node_names();
 
+private Usage();
 
 main( argc, argv )
   int   argc;
