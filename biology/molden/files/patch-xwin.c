--- xwin.c~   Mon Jul 10 20:46:06 2006
+++ xwin.c    Tue Jan  9 10:43:24 2007
@@ -3177,7 +3177,7 @@
 static int *icopth;
 static int *icoptl;
 static int *icoptm;
-static int linkat = 0;
+static int link_at = 0;
 
 static QBOXSTRU IANZboxes[MAXAT];
 static QBOXSTRU IZboxes[MAXAT][4];
@@ -11622,7 +11622,7 @@
 		if (ioniom == 1) {
 		  int ism, isl;
 
-		  linkat = 0;
+		  link_at = 0;
 
 		  /* Counting the number of Link atoms between H and lower 
 		     levels*/
@@ -11635,10 +11635,10 @@
 		     if (ionij != 0) continue;
 		     nconn = atomptr->iconn[j][0];
 		     for (k=1;k<=nconn;k++) {
-		       if (ityp[atomptr->iconn[j][k]-1]/10000 > 0) linkat++;
+		       if (ityp[atomptr->iconn[j][k]-1]/10000 > 0) link_at++;
 		     }
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  *itotc = *icopth;
 		  *imult = *ispopth;
 		  if (CheckChargeMult()) {
@@ -11659,7 +11659,7 @@
 
 		}  else if (ioniom == 2) {
 
-	          linkat = 0;
+	          link_at = 0;
 
 		  /* Counting the number of Link atoms between H and 
 		       lower levels*/
@@ -11669,10 +11669,10 @@
 			 if(ionij != 0) continue;
 		         nconn = atomptr->iconn[j][0];
 		         for (k=1;k<=nconn;k++) {
-		           if (ityp[atomptr->iconn[j][k]-1]/10000 > 0) linkat++;
+		           if (ityp[atomptr->iconn[j][k]-1]/10000 > 0) link_at++;
 		         }
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  *itotc = *icopth;
 		  *imult = *ispopth;
 		  if (CheckChargeMult()) {
@@ -11684,7 +11684,7 @@
 	               break;
 */
 		  }
-	          linkat = 0;
+	          link_at = 0;
 
 		  /* Counting the number of Link atoms between H+M and 
 		     lower levels*/
@@ -11694,10 +11694,10 @@
 			if (ionij == 2) continue;
 			nconn = atomptr->iconn[j][0];
 			for (k=1;k<=nconn;k++) {
-			   if (ityp[atomptr->iconn[j][k]-1]/10000 == 2) linkat++;
+			   if (ityp[atomptr->iconn[j][k]-1]/10000 == 2) link_at++;
 			}
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  *itotc = *icoptm;
 		  *imult = *ispoptm;
 		  if (CheckChargeMult()) {
@@ -11712,7 +11712,7 @@
 		  icopt = *icoptl+3;
 		  ispopt = *ispoptl-1;
 		}
-		linkat = 0;
+		link_at = 0;
 		*itotc = icopt - 3;
 		*imult = ispopt + 1;
 		*ito = itopt[jmode] + 1;
@@ -11964,10 +11964,10 @@
    ionil = 0;
 
    if (ioniom) {
-     ionil = 3 - (linkat / 10000);
-     linkat -= (linkat / 10000) * 10000;
+     ionil = 3 - (link_at / 10000);
+     link_at -= (link_at / 10000) * 10000;
    } else {
-     linkat = 0;
+     link_at = 0;
    }
 
    if (*zmptr.ihaszm) {
@@ -11990,10 +11990,10 @@
       }
    }
 /*
-   fprintf(stderr,"ionil %d ne %d itotc %d linkat %d mult %d\n",
-                   ionil,ne,*itotc,linkat,*imult);
+   fprintf(stderr,"ionil %d ne %d itotc %d link_at %d mult %d\n",
+                   ionil,ne,*itotc,link_at,*imult);
 */
-   ne = ne - *itotc + linkat;
+   ne = ne - *itotc + link_at;
    if (ne % 2 == *imult % 2) return(1);
    return(0);
 }
