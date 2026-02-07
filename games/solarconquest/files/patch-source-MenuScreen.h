--- source/MenuScreen.h.orig	Thu Apr  6 03:11:27 2006
+++ source/MenuScreen.h	Thu Apr  6 03:11:27 2006
@@ -646,10 +646,7 @@
 	if (text)
 	{
 		char txt[MAX_STRING_SIZE];
-		char num[MAX_STRING_SIZE];
-		gcvt(g_gameSpeed,2,num);
-		strcpy(txt,"Speed: ");
-		strncat(txt,num,3);
+		sprintf(txt, "Speed: %.2f", g_gameSpeed);
 		text->SetText(txt);
 	}
 }
@@ -751,10 +748,7 @@
 				g_gameSpeed = 0.1;
 
 			char txt[MAX_STRING_SIZE];
-			char num[MAX_STRING_SIZE];
-			gcvt(g_gameSpeed,2,num);
-			strcpy(txt,"Speed: ");
-			strncat(txt,num,3);
+			sprintf(txt, "Speed: %.2f", g_gameSpeed);
 
 			CTextItem* text = (CTextItem*)g_optionsMenuScreen->FindItem(103);
 			if (text)
@@ -768,10 +762,7 @@
 				g_gameSpeed = 2.0;
 
 			char txt[MAX_STRING_SIZE];
-			char num[MAX_STRING_SIZE];
-			gcvt(g_gameSpeed,2,num);
-			strcpy(txt,"Speed: ");
-			strncat(txt,num,3);
+			sprintf(txt, "Speed: %.2f", g_gameSpeed);
 
 			CTextItem* text = (CTextItem*)g_optionsMenuScreen->FindItem(103);
 			if (text)
