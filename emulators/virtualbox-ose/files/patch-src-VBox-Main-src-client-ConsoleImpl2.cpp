--- src/VBox/Main/src-client/ConsoleImpl2.cpp.orig	2015-03-02 10:09:53.000000000 -0500
+++ src/VBox/Main/src-client/ConsoleImpl2.cpp	2015-03-13 12:49:53.780376000 -0400
@@ -4447,12 +4447,12 @@
                     }
                 }
 
-                Assert((int)maTapFD[uInstance] >= 0);
-                if ((int)maTapFD[uInstance] >= 0)
+                Assert((intptr_t)maTapFD[uInstance] >= 0);
+                if ((intptr_t)maTapFD[uInstance] >= 0)
                 {
                     InsertConfigString(pLunL0, "Driver", "HostInterface");
                     InsertConfigNode(pLunL0, "Config", &pCfg);
-                    InsertConfigInteger(pCfg, "FileHandle", maTapFD[uInstance]);
+                    InsertConfigInteger(pCfg, "FileHandle", (intptr_t)maTapFD[uInstance]);
                 }
 
 #elif defined(VBOX_WITH_NETFLT)
@@ -4646,12 +4646,12 @@
                         }
                     }
 
-                    Assert((int)maTapFD[uInstance] >= 0);
-                    if ((int)maTapFD[uInstance] >= 0)
+                    Assert((intptr_t)maTapFD[uInstance] >= 0);
+                    if ((intptr_t)maTapFD[uInstance] >= 0)
                     {
                         InsertConfigString(pLunL0, "Driver", "HostInterface");
                         InsertConfigNode(pLunL0, "Config", &pCfg);
-                        InsertConfigInteger(pCfg, "FileHandle", maTapFD[uInstance]);
+                        InsertConfigInteger(pCfg, "FileHandle", (intptr_t)maTapFD[uInstance]);
                     }
                     break;
                 }
