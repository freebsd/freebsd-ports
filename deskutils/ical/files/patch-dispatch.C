--- dispatch.C.orig	1994-05-20 05:21:54.000000000 +0200
+++ dispatch.C	2003-04-28 18:14:32.000000000 +0200
@@ -24,7 +24,7 @@ int Dispatch(Dispatch_Entry* table, Clie
 	    if ((entry->max_arg_count >= 0) && (argc > entry->max_arg_count)) {
 		TCL_Error(tcl, "too many arguments");
 	    }
-	    return entry->handler(c, tcl, argc, argv);
+	    return entry->handler(c, tcl, argc, (CONST84 char **)argv);
 	}
     }
 
