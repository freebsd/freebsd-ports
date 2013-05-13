--- Tcl.cc.orig	2007-02-04 02:46:43.000000000 +0100
+++ Tcl.cc	2013-05-13 09:19:37.000000000 +0200
@@ -213,7 +213,7 @@
 	if (strlen(s) > MAX_CODE_TO_DUMP) {
 		s = "\n[code omitted because of length]\n";
 	};
-	fprintf(stderr, "%s: \"%s\": %s\n", application_, s, tcl_->result);
+	fprintf(stderr, "%s: \"%s\": %s\n", application_, s, Tcl_GetStringResult(tcl_));
 	exit(1);
 }
 
@@ -546,7 +546,7 @@
 			need_parse = 1;
 			continue;
 		};
-		result = Tcl_SplitList(in, argv[i], &ac, (const char ***) &av);
+		result = Tcl_SplitList(in, argv[i], &ac, (CONST84 char ***) &av);
 		if (result != TCL_OK) break;
 		if (ac == 1) {
 			varName = localName = av[0];
