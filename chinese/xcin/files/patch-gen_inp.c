--- src/Cinput/gen_inp/gen_inp.c.orig	Tue Nov 27 10:19:04 2001
+++ src/Cinput/gen_inp/gen_inp.c	Tue Apr  9 19:15:32 2002
@@ -1285,16 +1285,20 @@
 	    inpinfo->mcch_grouping = NULL;
 
 	    if ((keyinfo->keystate & Mod1Mask) &&	/* alt-Num/space */
-		(('1'<=keystr[0] && keystr[0]<='9') || 
+		(('0'<=keystr[0] && keystr[0]<='9') ||
 		 ((cf->mode & INP_MODE_SPACEAUTOUP) && keysym==XK_space))) {
 		int choice=-1;
 
 		if (keysym == XK_space)
 		    choice = 1;
-		else if (keystr[0] >= '1' && keystr[0] <= '9')
-		    choice = (int)(keystr[0] - '0');
-		if (cf->mode & INP_MODE_SELKEYSHIFT)
-		    choice ++;
+		else {
+		    if (keystr[0] >= '1' && keystr[0] <= '9')
+			choice = (int)(keystr[0] - '0');
+		    else if (keystr[0] == '0')
+			choice = 10;
+		    if (cf->mode & INP_MODE_SELKEYSHIFT)
+			choice ++;
+		}
 		if (choice >= 1 && choice <= iccf->nreltsi) {
 		    strncpy(cch_s, iccf->reltsi+iccf->tsiindex[choice-1], 
 			    iccf->tsigroup[choice]*2);
@@ -1304,11 +1308,15 @@
 		}
 		hint_processing = 1;
 	    }
-	    else if (keysym==XK_Escape || keysym==XK_BackSpace ||
-		     keysym==XK_Delete ||
+	    else if (keysym==XK_Escape || 
 		     keysym==XK_Shift_L || keysym==XK_Shift_R ||
 		     keysym==XK_Control_L || keysym==XK_Control_R) {
 		hint_processing = 1;
+	    }
+	    else if (keysym==XK_BackSpace || keysym==XK_Delete) {
+		hint_processing = 1;
+		iccf->showtsiflag = 0;
+		ret |= IMKEY_IGNORE;
 	    }
 	}
     }
