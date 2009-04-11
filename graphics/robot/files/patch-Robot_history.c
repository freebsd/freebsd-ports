--- Robot/history.c.orig	2009-04-11 22:11:08.000000000 +0200
+++ Robot/history.c	2009-04-11 22:11:30.000000000 +0200
@@ -248,7 +248,7 @@
 			if (text[i] == '^') {
 				index = i;
 				strncpy(htext1, text + 1, index - 1);
-				htext1[index - 1] = (char) NULL;
+				htext1[index - 1] = 0;
 				break;
 			}
 		}
@@ -258,7 +258,7 @@
 		}
 		strcpy(htext2, text + index + 1);
 		if (htext2[strlen(htext2) - 1] == '^') {
-			htext2[strlen(htext2) - 1] = (char) NULL;
+			htext2[strlen(htext2) - 1] = 0;
 		}
 		/* now try to find it in the previous string */
 		sprintf(htext3, "%s",
@@ -271,7 +271,7 @@
 				/* think we found the string */
 				if (i > 0) {
 					strncpy(htext4, htext3, i);
-					htext4[i] = (char) NULL;
+					htext4[i] = 0;
 				}
 				else{
 					strcpy(htext4, "");
