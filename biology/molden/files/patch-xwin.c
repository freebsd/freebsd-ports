--- xwin.c.orig	2008-11-03 09:37:45.707629185 -0500
+++ xwin.c	2008-11-03 09:37:55.118628907 -0500
@@ -3747,7 +3747,7 @@
 static int ibopth = 0;
 static int iboptl = 0;
 static int iboptm = 0;
-static int linkat = 0;
+static int link_at = 0;
 
 static QBOXSTRU IANZboxes[MAXAT];
 static QBOXSTRU IZboxes[MAXAT][4];
@@ -19086,7 +19086,7 @@
 		if (ioniom == 1) {
 		  int ism, isl;
 
-		  linkat = 0;
+		  link_at = 0;
 
 		  /* Counting the number of Link atoms between H and lower 
 		     levels*/
@@ -19099,10 +19099,10 @@
 		     if (ionij != 0) continue;
 		     nconn = xyzp->iconn[j*(MXCON+1)];
 		     for (k=1;k<=nconn;k++) {
-		       if (xyzp->ityp[xyzp->iconn[j*(MXCON+1)+k]-1]/10000 > 0) linkat++;
+		       if (xyzp->ityp[xyzp->iconn[j*(MXCON+1)+k]-1]/10000 > 0) link_at++;
 		     }
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  jobcom->itotc = jobcom->icopth;
 		  jobcom->imult = jobcom->ispopth;
 		  if (CheckChargeMult()) {
@@ -19123,7 +19123,7 @@
 
 		}  else if (ioniom == 2) {
 
-	          linkat = 0;
+	          link_at = 0;
 
 		  /* Counting the number of Link atoms between H and 
 		       lower levels*/
@@ -19133,10 +19133,10 @@
 			 if(ionij != 0) continue;
 		         nconn = xyzp->iconn[j*(MXCON+1)];
 		         for (k=1;k<=nconn;k++) {
-		           if (xyzp->ityp[xyzp->iconn[j*(MXCON+1)+k]-1]/10000 > 0) linkat++;
+		           if (xyzp->ityp[xyzp->iconn[j*(MXCON+1)+k]-1]/10000 > 0) link_at++;
 		         }
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  jobcom->itotc = jobcom->icopth;
 		  jobcom->imult = jobcom->ispopth;
 		  if (CheckChargeMult()) {
@@ -19148,7 +19148,7 @@
 	               break;
 */
 		  }
-	          linkat = 0;
+	          link_at = 0;
 
 		  /* Counting the number of Link atoms between H+M and 
 		     lower levels*/
@@ -19158,10 +19158,10 @@
 			if (ionij == 2) continue;
 			nconn = xyzp->iconn[j*(MXCON+1)];
 			for (k=1;k<=nconn;k++) {
-			   if (xyzp->ityp[xyzp->iconn[j*(MXCON+1)+k]-1]/10000 == 2) linkat++;
+			   if (xyzp->ityp[xyzp->iconn[j*(MXCON+1)+k]-1]/10000 == 2) link_at++;
 			}
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  jobcom->itotc = jobcom->icoptm;
 		  jobcom->imult = jobcom->ispoptm;
 		  if (CheckChargeMult()) {
@@ -19176,7 +19176,7 @@
 		  icopt = jobcom->icoptl+3;
 		  ispopt = jobcom->ispoptl-1;
 		}
-		linkat = 0;
+		link_at = 0;
 		jobcom->itotc = icopt - 3;
 		jobcom->imult = ispopt + 1;
 		jobcom->ito = itopt[jmode] + 1;
@@ -19428,10 +19428,10 @@
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
 
    if (*zmptrp->ihaszm) {
@@ -19454,10 +19454,10 @@
       }
    }
 /*
-   fprintf(stderr,"ionil %d ne %d itotc %d linkat %d mult %d\n",
-                   ionil,ne,jobcom->itotc,linkat,jobcom->imult);
+   fprintf(stderr,"ionil %d ne %d itotc %d link_at %d mult %d\n",
+                   ionil,ne,jobcom->itotc,link_at,jobcom->imult);
 */
-   ne = ne - jobcom->itotc + linkat;
+   ne = ne - jobcom->itotc + link_at;
    if (ne % 2 == jobcom->imult % 2) return(1);
    return(0);
 }
