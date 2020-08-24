--- cmake/Modules/InstallConfig.cmake.orig	2019-04-07 09:22:21 UTC
+++ cmake/Modules/InstallConfig.cmake
@@ -17,8 +17,8 @@
 #============================================================================
 
 # Subdirectories to package JK2 and JKA into
-set(JKAInstallDir "JediAcademy")
-set(JK2InstallDir "JediOutcast")
+set(JKAInstallDir "share/JediAcademy")
+set(JK2InstallDir "share/JediOutcast")
 
 # Install components
 set(JKAMPCoreComponent "JKAMPCore")
