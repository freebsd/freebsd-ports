--- client/components/resource/resource-component.c.orig	Fri Nov 29 15:56:45 2002
+++ client/components/resource/resource-component.c	Fri Nov 29 15:57:50 2002
@@ -1067,6 +1067,7 @@
 	subject = g_strdup ("");
 	
 	GNOME_Evolution_Composer_setHeaders (composer, 
+					     "",                 /* From */
 					     list,               /* To  */
 					     empty_list,         /* Cc  */
 					     empty_list,         /* Bcc */
