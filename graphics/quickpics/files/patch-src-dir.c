--- dir.c.orig	Tue Apr  7 03:31:14 1998
+++ dir.c	Fri Aug 23 20:08:24 2002
@@ -479,12 +479,12 @@
 			rmspace(description);
 			if(!description[0])
 			{
-				sprintf(description,"Description of %s goes here.",
+				sprintf(description,"%s",
 					img->name);
 			}
 		}
 		else
-			sprintf(description,"Description of %s goes here.",
+			sprintf(description,"%s",
 				img->name);
 
 		imgrec_setdescription(img,description);
