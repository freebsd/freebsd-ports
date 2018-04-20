--- src/cmd_connect.c	2014-04-04 08:22:38
+++ src/cmd_connect.c	2018-04-20 18:26:38
@@ -861,6 +861,14 @@
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
-            version = CS_TDS_80;
+            version = CS_TDS_71; /* https://sourceforge.net/p/sqsh/discussion/365924/thread/29ae1664/#7f59/707f */
 #endif
         else version = CS_TDS_50; /* default version */
@@ -1259,7 +1267,16 @@
                     env_set( g_env, "tds_version", "7.0" );
                     break;
-                case CS_TDS_80:
+                case CS_TDS_71:
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
