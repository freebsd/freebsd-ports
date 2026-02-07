--- ./src/Attack.cxx.orig	2013-10-30 16:09:58.000000000 -0200
+++ ./src/Attack.cxx	2013-10-30 16:10:20.000000000 -0200
@@ -84,6 +84,7 @@
   
   player_name[0] = '\0';
   parseCommandLine(argc, argv, mode, port, host_name, player_name, height, width);
+  glutInit(&argc, argv);
   run_crack_attack(mode, port, host_name, player_name, height, width);
 
   return 0;
