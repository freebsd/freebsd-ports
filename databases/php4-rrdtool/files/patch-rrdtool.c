--- rrdtool.c.orig	Thu Jun 12 03:27:51 2003
+++ rrdtool.c	Tue May 10 12:39:24 2005
@@ -331,6 +331,7 @@
 	HashTable	*args_arr;
 	int			i, xsize, ysize, argc;
 	char		**argv, **calcpr;
+	double		ymin, ymax;
     
 
 	if ( rrd_test_error() )
@@ -377,7 +378,8 @@
 		}
    
 		optind = 0; opterr = 0; 
-		if ( rrd_graph(argc-1, &argv[1], &calcpr, &xsize, &ysize) != -1 )
+		if ( rrd_graph(argc-1, &argv[1], &calcpr, &xsize, &ysize,
+			NULL, &ymin, &ymax) != -1 )
 		{
 			array_init(return_value);
 			add_assoc_long(return_value, "xsize", xsize);
