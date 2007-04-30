--- Tcl.cc.orig	Sun Apr 29 16:21:14 2007
+++ Tcl.cc	Sun Apr 29 16:21:26 2007
@@ -546,7 +546,7 @@
 			need_parse = 1;
 			continue;
 		};
-		result = Tcl_SplitList(in, argv[i], &ac, (const char ***) &av);
+		result = Tcl_SplitList(in, argv[i], &ac, (CONST84 char ***) &av);
 		if (result != TCL_OK) break;
 		if (ac == 1) {
 			varName = localName = av[0];
