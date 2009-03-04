--- ./main.c.orig	2009-01-14 17:33:21.000000000 +0100
+++ ./main.c	2009-02-27 18:18:23.000000000 +0100
@@ -290,7 +290,8 @@
   // Determine the executable directory
   Set_Program_Directory(argv[0],Repertoire_du_programme);
   // Choose directory for data (read only)
-  Set_Data_Directory(Repertoire_du_programme,Repertoire_des_donnees);
+  //Set_Data_Directory(Repertoire_du_programme,Repertoire_des_donnees);
+  Set_Data_Directory("/usr/local/share/grafx2/",Repertoire_des_donnees);
   // Choose directory for settings (read/write)
   Set_Config_Directory(Repertoire_du_programme,Repertoire_de_configuration);
 
