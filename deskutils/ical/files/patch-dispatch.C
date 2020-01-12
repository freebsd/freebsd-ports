--- dispatch.C.orig	1994-05-20 03:21:54 UTC
+++ dispatch.C
@@ -24,7 +24,7 @@ int Dispatch(Dispatch_Entry* table, ClientData c, Tcl_
 	    if ((entry->max_arg_count >= 0) && (argc > entry->max_arg_count)) {
 		TCL_Error(tcl, "too many arguments");
 	    }
-	    return entry->handler(c, tcl, argc, argv);
+	    return entry->handler(c, tcl, argc, (const char **)argv);
 	}
     }
 
