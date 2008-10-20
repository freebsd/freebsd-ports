--- b.c.orig	2007-03-31 15:56:18.000000000 -0500
+++ b.c	2008-07-07 08:44:50.000000000 -0500
@@ -84,8 +84,8 @@
 
 	if (setvec == 0) {	/* first time through any RE */
 		maxsetvec = MAXLIN;
-		setvec = (int *) malloc(maxsetvec * sizeof(int));
-		tmpset = (int *) malloc(maxsetvec * sizeof(int));
+		setvec = (int *) calloc(maxsetvec, sizeof(int));
+		tmpset = (int *) calloc(maxsetvec, sizeof(int));
 		if (setvec == 0 || tmpset == 0)
 			overflo("out of space initializing makedfa");
 	}
@@ -137,7 +137,7 @@
 	f->accept = poscnt-1;	/* penter has computed number of positions in re */
 	cfoll(f, p1);	/* set up follow sets */
 	freetr(p1);
-	if ((f->posns[0] = (int *) calloc(1, *(f->re[0].lfollow)*sizeof(int))) == NULL)
+	if ((f->posns[0] = (int *) calloc(*(f->re[0].lfollow), sizeof(int))) == NULL)
 			overflo("out of space in makedfa");
 	if ((f->posns[1] = (int *) calloc(1, sizeof(int))) == NULL)
 		overflo("out of space in makedfa");
@@ -157,7 +157,7 @@
 	f->reset = 0;
 	k = *(f->re[0].lfollow);
 	xfree(f->posns[2]);			
-	if ((f->posns[2] = (int *) calloc(1, (k+1)*sizeof(int))) == NULL)
+	if ((f->posns[2] = (int *) calloc(k+1, sizeof(int))) == NULL)
 		overflo("out of space in makeinit");
 	for (i=0; i <= k; i++) {
 		(f->posns[2])[i] = (f->re[0].lfollow)[i];
@@ -357,7 +357,7 @@
 			setvec[i] = 0;
 		setcnt = 0;
 		follow(v);	/* computes setvec and setcnt */
-		if ((p = (int *) calloc(1, (setcnt+1)*sizeof(int))) == NULL)
+		if ((p = (int *) calloc(setcnt+1, sizeof(int))) == NULL)
 			overflo("out of space building follow set");
 		f->re[info(v)].lfollow = p;
 		*p = setcnt;
@@ -531,7 +531,7 @@
 			for (i = 2; i <= f->curstat; i++)
 				xfree(f->posns[i]);
 			k = *f->posns[0];			
-			if ((f->posns[2] = (int *) calloc(1, (k+1)*sizeof(int))) == NULL)
+			if ((f->posns[2] = (int *) calloc(k+1, sizeof(int))) == NULL)
 				overflo("out of space in pmatch");
 			for (i = 0; i <= k; i++)
 				(f->posns[2])[i] = (f->posns[0])[i];
@@ -588,7 +588,7 @@
 			for (i = 2; i <= f->curstat; i++)
 				xfree(f->posns[i]);
 			k = *f->posns[0];			
-			if ((f->posns[2] = (int *) calloc(1, (k+1)*sizeof(int))) == NULL)
+			if ((f->posns[2] = (int *) calloc(k+1, sizeof(int))) == NULL)
 				overflo("out of state space");
 			for (i = 0; i <= k; i++)
 				(f->posns[2])[i] = (f->posns[0])[i];
@@ -920,7 +920,7 @@
 	for (i = 0; i < NCHARS; i++)
 		f->gototab[f->curstat][i] = 0;
 	xfree(f->posns[f->curstat]);
-	if ((p = (int *) calloc(1, (setcnt+1)*sizeof(int))) == NULL)
+	if ((p = (int *) calloc(setcnt+1, sizeof(int))) == NULL)
 		overflo("out of space in cgoto");
 
 	f->posns[f->curstat] = p;
