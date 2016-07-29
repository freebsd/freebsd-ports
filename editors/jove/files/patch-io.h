--- io.h.orig	1996-03-07 17:34:42 UTC
+++ io.h
@@ -37,7 +37,7 @@ extern void
 	close_file proto((File *fp)),
 	d_cache_init proto((void)),
 	file_write proto((char *fname, bool app)),
-	getline proto((daddr addr,char *buf)),
+	get_line proto((daddr addr,char *buf)),
 	lsave proto((void)),
 	putreg proto((File *fp,LinePtr line1,int char1,LinePtr line2,int char2,bool makesure)),
 	read_file proto((char *file, bool is_insert)),
