--- src/backend/postmaster/postmaster.c.orig.1	Mon Feb 23 15:33:29 2004
+++ src/backend/postmaster/postmaster.c	Mon Feb 23 15:34:53 2004
@@ -610,7 +610,7 @@
 	 */
 	checkDataDir(potential_DataDir);	/* issues error messages */
 	SetDataDir(potential_DataDir);
-
+	ProcessConfigFile(PGC_POSTMASTER);
 #ifdef USE_REPLICATION
 	PGR_Get_Conf_Data( potential_DataDir, CLUSTER_CONF_FILE );
 	PGR_Init_Replicate_Server_Data();
@@ -627,7 +627,6 @@
 		}
 	}
 #endif /* USE_REPLICATION */
-	ProcessConfigFile(PGC_POSTMASTER);
 
 	/*
 	 * Check for invalid combinations of GUC settings.
