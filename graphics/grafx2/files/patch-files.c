--- ./files.c.orig	2009-02-23 14:20:42.000000000 +0100
+++ ./files.c	2009-02-23 14:21:14.000000000 +0100
@@ -318,11 +318,10 @@
   // This should be made dynamic because in the multitask world, user can mount new drives, 
   // connect to network ones, and so on, while Grafx2 is running.
   #else
-    #warning "Your platform is missing some specific code here ! please check and correct ! :)"
     for (Indice=0; Indice<Nb_drives; Indice++)
     {
       // Add the drive's name ("c:\\", "/" etc.) to the list
-      Ajouter_element_a_la_liste(Drive[Indice].Chemin, 2);
+      Ajouter_element_a_la_liste("/", 2);
       Liste_Nb_repertoires++;
     }
   #endif
