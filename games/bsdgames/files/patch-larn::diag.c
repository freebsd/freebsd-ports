$FreeBSD$

--- larn/diag.c	17 Jun 2003 04:25:24 -0000	1.2
+++ larn/diag.c	21 Jun 2004 02:28:34 -0000	1.3
@@ -210,7 +210,7 @@
 		if (beenhere[k])
 			lrfill((char*)&cell[k*MAXX*MAXY],sizeof(struct cel)*MAXY*MAXX);
 
-	lrfill((char*)&c[0],100*sizeof(long));	gtime = lrint();
+	lrfill((char*)&c[0],100*sizeof(long));	gtime = lrint_x();
 	level = c[CAVELEVEL] = lgetc();
 	playerx = lgetc();		playery = lgetc();
 	lrfill((char*)iven,26);		lrfill((char*)ivenarg,26*sizeof(short));
@@ -241,7 +241,7 @@
 		}
 
 	time(&zzz);
-	initialtime = zzz-lrint();
+	initialtime = zzz-lrint_x();
 	fstat(fd,&filetimes);	/*	get the creation and modification time of file	*/
 	lrfill((char*)&zzz,sizeof(long));	zzz += 6;
 	if (filetimes.st_ctime > zzz) fsorry();	/*	file create time	*/
@@ -249,7 +249,7 @@
 	if (c[HP]<0) { died(284); return; }	/* died a post mortem death */
 
 	oldx = oldy = 0;
-	i = lrint();  /* inode # */
+	i = lrint_x();  /* inode # */
 	if (i && (filetimes.st_ino!=i)) fsorry();
 	lrclose();
 	if (strcmp(fname,ckpfile) == 0)
