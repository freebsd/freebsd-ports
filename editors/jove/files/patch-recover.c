--- recover.c.orig	1996-03-07 17:34:43 UTC
+++ recover.c
@@ -160,7 +160,7 @@ size_t	n;
 private char	*getblock proto((daddr atl));
 
 void
-getline(tl, buf)
+get_line(tl, buf)
 daddr	tl;
 char	*buf;
 {
@@ -561,7 +561,7 @@ FILE	*out;
 	Nchars = Nlines = 0L;
 	while (--nlines >= 0) {
 		addr = getaddr(ptrs_fp);
-		getline(addr, buf);
+		get_line(addr, buf);
 		Nlines += 1;
 		Nchars += 1 + strlen(buf);
 		fputs(buf, out);
