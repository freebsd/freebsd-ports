--- ./bas8.c.org	Fri Aug 11 03:17:25 1995
+++ ./bas8.c	Mon May 10 15:18:08 1999
@@ -10,12 +10,12 @@
 
 #ifdef	__STDC__
 static	void	clear_prog(void);
-static	int	listl(lpoint), pwrite(filebufp, CHAR *, int), def_fn(int, int);
+static	int	listl(lpoint), mypwrite(filebufp, CHAR *, int), def_fn(int, int);
 static	lpoint  get_end(void);
 static	STR	strpat(STR, STR, STR);
 #else
 static	void	clear_prog();
-static	int	listl(), pwrite(), def_fn();
+static	int	listl(), mypwrite(), def_fn();
 static	lpoint  get_end();
 static	STR	strpat();
 #endif
@@ -495,7 +495,7 @@
  */
 /*ARGSUSED*/
 static	int
-pwrite(filebufp fp, CHAR *buf, int len)
+mypwrite(filebufp fp, CHAR *buf, int len)
 {
 	fp = fp;
 	return((int)write(1, (char *)buf, (unsigned)len));
@@ -517,7 +517,7 @@
  */
 /*ARGSUSED*/
 static	int
-pwrite(fp, buf, len)
+mypwrite(fp, buf, len)
 filebufp fp;
 CHAR	*buf;
 int	len;
@@ -585,7 +585,7 @@
 		Twidth = filedes->bufsiz;
 	}
 	else {
-		outfunc = pwrite;
+		outfunc = mypwrite;
 		curcursor= &cursor;
 		Twidth = ter_width;
 	}
@@ -806,7 +806,7 @@
 		Twidth = filedes->bufsiz;
 	}
 	else {
-		outfunc = pwrite;
+		outfunc = mypwrite;
 		curcursor= &cursor;
 		Twidth = ter_width;
 		point--;
