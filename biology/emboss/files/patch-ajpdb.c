--- ajax/ajpdb.c.orig	Mon Jan 23 12:19:22 2006
+++ ajax/ajpdb.c	Fri Aug 19 13:49:12 2005
@@ -1198,7 +1198,7 @@
     osstr = ajStrNew();
     xstr  = ajStrNew();
 
-    /* Start of main application loop */
+    /* Start of main loop */
     while(ajFileReadLine(inf,&line))
     {
 	if(ajStrPrefixC(line,"XX"))
@@ -1313,6 +1313,8 @@
 	    
 	    (ret)->Nchn = ncha;
 	    (ret)->Ngp  = ngrp;
+
+	    continue;
 	}
 	
 
@@ -1382,7 +1384,11 @@
 	    ajStrToken(&token,&handle,NULL);
 	    ajStrToInt(token,&mod);
 	    if((mode == 0) && (mod!=1))
-		break;
+	      {
+		/* break; */
+		/* Discard remaining AT lines */
+		while(ajFileReadLine(inf,&line) && ajStrPrefixC(line,"AT"));
+	      }
 
 	    /* Chain number */
 	    ajStrToken(&token,&handle,NULL);
@@ -1463,7 +1469,10 @@
 			    "jison@hgmp.mrc.ac.uk");
 	    }
 	    else
+	      {
 		ajListPushApp((ret)->Chains[chn-1]->Atoms,(void *)atom);
+	      }
+	    continue;
 	}
 	
 	/* Parse residue line */
@@ -1479,8 +1488,11 @@
 	    ajStrToken(&token,&handle,NULL);
 	    ajStrToInt(token,&mod);
 	    if((mode == 0) && (mod!=1))
-		break;
-
+	      {
+		/* break;*/
+		/* Discard remaining RE lines */
+		while(ajFileReadLine(inf,&line) && ajStrPrefixC(line,"RE"));
+	      }
 	    /* Chain number */
 	    ajStrToken(&token,&handle,NULL);
 	    ajStrToInt(token,&chn);
@@ -1585,6 +1597,8 @@
             ajStrToFloat(token,&residue->pol_rel);
 
 	    ajListPushApp((ret)->Chains[chn-1]->Residues,(void *)residue);  
+
+	    continue;
 	}
     }
     /* End of main application loop */
