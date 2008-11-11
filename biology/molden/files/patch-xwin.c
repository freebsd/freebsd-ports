--- ./xwin.c.orig	2008-11-10 12:27:25.647441620 -0500
+++ ./xwin.c	2008-11-10 12:29:25.515496080 -0500
@@ -22,7 +22,7 @@
 #endif
 #if defined(DARWIN) || defined(FREEBSD)
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #endif
 
@@ -3360,7 +3360,7 @@
 static int *icopth;
 static int *icoptl;
 static int *icoptm;
-static int linkat = 0;
+static int link_at = 0;
 
 static QBOXSTRU IANZboxes[MAXAT];
 static QBOXSTRU IZboxes[MAXAT][4];
@@ -17466,7 +17466,7 @@
 		if (ioniom == 1) {
 		  int ism, isl;
 
-		  linkat = 0;
+		  link_at = 0;
 
 		  /* Counting the number of Link atoms between H and lower 
 		     levels*/
@@ -17479,10 +17479,10 @@
 		     if (ionij != 0) continue;
 		     nconn = xyz.iconn[j*(MXCON+1)];
 		     for (k=1;k<=nconn;k++) {
-		       if (xyz.ityp[xyz.iconn[j*(MXCON+1)+k]-1]/10000 > 0) linkat++;
+		       if (xyz.ityp[xyz.iconn[j*(MXCON+1)+k]-1]/10000 > 0) link_at++;
 		     }
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  *itotc = *icopth;
 		  *imult = *ispopth;
 		  if (CheckChargeMult()) {
@@ -17503,7 +17503,7 @@
 
 		}  else if (ioniom == 2) {
 
-	          linkat = 0;
+	          link_at = 0;
 
 		  /* Counting the number of Link atoms between H and 
 		       lower levels*/
@@ -17513,10 +17513,10 @@
 			 if(ionij != 0) continue;
 		         nconn = xyz.iconn[j*(MXCON+1)];
 		         for (k=1;k<=nconn;k++) {
-		           if (xyz.ityp[xyz.iconn[j*(MXCON+1)+k]-1]/10000 > 0) linkat++;
+		           if (xyz.ityp[xyz.iconn[j*(MXCON+1)+k]-1]/10000 > 0) link_at++;
 		         }
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  *itotc = *icopth;
 		  *imult = *ispopth;
 		  if (CheckChargeMult()) {
@@ -17528,7 +17528,7 @@
 	               break;
 */
 		  }
-	          linkat = 0;
+	          link_at = 0;
 
 		  /* Counting the number of Link atoms between H+M and 
 		     lower levels*/
@@ -17538,10 +17538,10 @@
 			if (ionij == 2) continue;
 			nconn = xyz.iconn[j*(MXCON+1)];
 			for (k=1;k<=nconn;k++) {
-			   if (xyz.ityp[xyz.iconn[j*(MXCON+1)+k]-1]/10000 == 2) linkat++;
+			   if (xyz.ityp[xyz.iconn[j*(MXCON+1)+k]-1]/10000 == 2) link_at++;
 			}
 		  }
-		  linkat += 20000;
+		  link_at += 20000;
 		  *itotc = *icoptm;
 		  *imult = *ispoptm;
 		  if (CheckChargeMult()) {
@@ -17556,7 +17556,7 @@
 		  icopt = *icoptl+3;
 		  ispopt = *ispoptl-1;
 		}
-		linkat = 0;
+		link_at = 0;
 		*itotc = icopt - 3;
 		*imult = ispopt + 1;
 		*ito = itopt[jmode] + 1;
@@ -17808,10 +17808,10 @@
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
@@ -17834,10 +17834,10 @@
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
