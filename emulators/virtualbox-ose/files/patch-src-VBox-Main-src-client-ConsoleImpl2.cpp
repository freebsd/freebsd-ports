--- src/VBox/Main/src-client/ConsoleImpl2.cpp.orig	2013-09-06 08:30:10.000000000 -0400
+++ src/VBox/Main/src-client/ConsoleImpl2.cpp	2013-09-12 13:03:34.000000000 -0400
@@ -4031,12 +4031,13 @@
                     }
                 }
 
-                Assert((int)maTapFD[uInstance] >= 0);
-                if ((int)maTapFD[uInstance] >= 0)
+                const int fd = (int)(uintptr_t)maTapFD[uInstance];
+                Assert(fd >= 0);
+                if (fd >= 0)
                 {
                     InsertConfigString(pLunL0, "Driver", "HostInterface");
                     InsertConfigNode(pLunL0, "Config", &pCfg);
-                    InsertConfigInteger(pCfg, "FileHandle", maTapFD[uInstance]);
+                    InsertConfigInteger(pCfg, "FileHandle", fd);
                 }
 
 #elif defined(VBOX_WITH_NETFLT)
@@ -4230,12 +4231,13 @@
                         }
                     }
 
-                    Assert((int)maTapFD[uInstance] >= 0);
-                    if ((int)maTapFD[uInstance] >= 0)
+                    const int fd = (int)(uintptr_t)maTapFD[uInstance];
+                    Assert(fd >= 0);
+                    if (fd >= 0)
                     {
                         InsertConfigString(pLunL0, "Driver", "HostInterface");
                         InsertConfigNode(pLunL0, "Config", &pCfg);
-                        InsertConfigInteger(pCfg, "FileHandle", maTapFD[uInstance]);
+                        InsertConfigInteger(pCfg, "FileHandle", fd);
                     }
                     break;
                 }
