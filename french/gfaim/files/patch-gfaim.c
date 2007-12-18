--- gfaim.c.orig	2000-11-21 20:58:42.000000000 +0100
+++ gfaim.c	2007-12-17 22:37:41.000000000 +0100
@@ -1142,7 +1142,7 @@
       champs=g_strsplit(buf,":",0);
 
 /*le numero de la recette*/
-      plist[i].numero=atoi(champs[0]);
+      plist[i].numero= atoi(champs[0]);
 
 /*le nom de la recette*/
       strcpy(buffer,champs[1]);
@@ -1188,7 +1188,7 @@
     
 /*recherche de rlibelle dans buf*/
     
-     (int *) loc = strcasestr(buf,rlibelle);
+     loc = strcasestr(buf,rlibelle);
     
 /* si c'est zero je passe*/
        if (loc != NULL) 
@@ -1203,7 +1203,7 @@
 
               gtk_clist_append( (GtkCList *) data,texte[0]);
 /*accroche numero au titre de la recette comme index*/	      
-	      gtk_clist_set_row_data(GTK_CLIST(liste),ligne,(int *) plist[k].numero);
+	      gtk_clist_set_row_data(GTK_CLIST(liste),ligne, &plist[k].numero);
 	      ligne++;
               g_free(label);
 
@@ -1242,12 +1242,12 @@
 {
     gchar *text = NULL;
 
-   int position;
+   int *position;
         
 /* renseigne les variables de la position de la recette */
-    (int *) position=gtk_clist_get_row_data(GTK_CLIST(liste),row);
-    vdebut=plist[position].rdebut;
-    vfin=plist[position].rfin;
+    position=gtk_clist_get_row_data(GTK_CLIST(liste),row);
+    vdebut=plist[*position].rdebut;
+    vfin=plist[*position].rfin;
 
 /*affiche la recette*/
     charge_recette(vdebut,vfin);
