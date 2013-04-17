--- src/libjasper/jpc/jpc_t2enc.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_t2enc.c	2013-04-17 22:32:23.000000000 +0200
@@ -565,7 +565,7 @@
 	}
 	pi->pktno = -1;
 	pi->numcomps = cp->numcmpts;
-	if (!(pi->picomps = jas_malloc(pi->numcomps * sizeof(jpc_picomp_t)))) {
+	if (!(pi->picomps = jas_malloc2(pi->numcomps, sizeof(jpc_picomp_t)))) {
 		jpc_pi_destroy(pi);
 		return 0;
 	}
@@ -577,7 +577,7 @@
 	for (compno = 0, tcomp = tile->tcmpts, picomp = pi->picomps;
 	  compno < pi->numcomps; ++compno, ++tcomp, ++picomp) {
 		picomp->numrlvls = tcomp->numrlvls;
-		if (!(picomp->pirlvls = jas_malloc(picomp->numrlvls *
+		if (!(picomp->pirlvls = jas_malloc2(picomp->numrlvls,
 		  sizeof(jpc_pirlvl_t)))) {
 			jpc_pi_destroy(pi);
 			return 0;
@@ -591,7 +591,7 @@
 /* XXX sizeof(long) should be sizeof different type */
 			pirlvl->numprcs = rlvl->numprcs;
 			if (rlvl->numprcs) {
-				if (!(pirlvl->prclyrnos = jas_malloc(pirlvl->numprcs *
+				if (!(pirlvl->prclyrnos = jas_malloc2(pirlvl->numprcs,
 				  sizeof(long)))) {
 					jpc_pi_destroy(pi);
 					return 0;
