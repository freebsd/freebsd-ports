--- src/cmd_connect.c.orig	2012-03-14 09:17:51 UTC
+++ src/cmd_connect.c
@@ -805,9 +805,11 @@ int cmd_connect( argc, argv )
 	/* Then we use freetds */
         else if (strcmp(tds_version, "7.0") == 0)
             version = CS_TDS_70;
+#if defined(CS_TDS_80)
         else if (strcmp(tds_version, "8.0") == 0)
             version = CS_TDS_80;
 #endif
+#endif
         else version = CS_TDS_50; /* default version */
 
 
@@ -1061,10 +1063,12 @@ int cmd_connect( argc, argv )
 			case CS_TDS_70:
                         	env_set( g_env, "tds_version", "7.0" );
 				break;
+#if defined(CS_TDS_80)
 			case CS_TDS_80:
                         	env_set( g_env, "tds_version", "8.0" );
 				break;
 #endif
+#endif
 			default:
                         	env_set( g_env, "tds_version", "unknown" );
 		}
