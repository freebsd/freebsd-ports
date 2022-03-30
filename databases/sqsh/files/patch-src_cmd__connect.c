--- src/cmd_connect.c.orig	2014-04-04 08:22:38 UTC
+++ src/cmd_connect.c
@@ -860,8 +860,16 @@ int cmd_connect( argc, argv )
         /* Then we use freetds which uses enum instead of defines */
         else if (strcmp(tds_version, "7.0") == 0)
             version = CS_TDS_70;
+        else if (strcmp(tds_version, "7.1") == 0)
+            version = CS_TDS_71;
+        else if (strcmp(tds_version, "7.2") == 0)
+            version = CS_TDS_72;
+        else if (strcmp(tds_version, "7.3") == 0)
+            version = CS_TDS_73;
+        else if (strcmp(tds_version, "7.4") == 0)
+            version = CS_TDS_74;
         else if (strcmp(tds_version, "8.0") == 0)
             version = CS_TDS_71;
 #endif
         else version = CS_TDS_50; /* default version */
 
@@ -1258,9 +1266,18 @@ int cmd_connect( argc, argv )
                 case CS_TDS_70:
                     env_set( g_env, "tds_version", "7.0" );
                     break;
                 case CS_TDS_71:
                     env_set( g_env, "tds_version", "8.0" );
                     break;
+                case CS_TDS_72:
+                    env_set( g_env, "tds_version", "7.2" );
+                    break;
+                case CS_TDS_73:
+                    env_set( g_env, "tds_version", "7.2" );
+                    break;
+                case CS_TDS_74:
+                    env_set( g_env, "tds_version", "7.2" );
+                    break;
 #endif
                 default:
                     env_set( g_env, "tds_version", "unknown" );
