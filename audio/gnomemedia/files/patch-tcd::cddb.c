
$FreeBSD$

--- tcd/cddb.c	2001/07/13 07:50:57	1.1
+++ tcd/cddb.c	2001/07/13 07:55:41
@@ -199,16 +199,16 @@
 	{
 		int min, sec;
 		
-		min = cd->trk[trk].toc.cdte_addr.msf.minute;
-		sec = cd->trk[trk].toc.cdte_addr.msf.second;
+		min = TOC_MINUTE(cd->trk[trk]);
+		sec = TOC_SECOND(cd->trk[trk]);
 	
 		n = (min*60)+sec;
-		fprintf( fp, "# %u\n", (n*75)+cd->trk[trk].toc.cdte_addr.msf.frame );
+		fprintf( fp, "# %u\n", (n*75)+TOC_FRAME(cd->trk[trk]) );
 	}
 	/* Print the number of seconds */
 	fprintf( fp, "#\n# Disc length: %i seconds\n", 
-		(cd->trk[cd->last_t+1].toc.cdte_addr.msf.minute*60)
-                +(cd->trk[cd->last_t+1].toc.cdte_addr.msf.second) );
+		(TOC_MINUTE(cd->trk[cd->last_t+1])*60)
+		+(TOC_SECOND(cd->trk[cd->last_t+1])) );
 
 	fprintf( fp, "#\n# Revision: %lu\n", cd->cddb_rev );
 	fprintf( fp, "# Submitted via: tcd 2.0b\n" );
@@ -245,10 +245,10 @@
     {
 	int min, sec;
 	
-	min = cd->trk[i].toc.cdte_addr.msf.minute;
-	sec = cd->trk[i].toc.cdte_addr.msf.second;
+	min = TOC_MINUTE(cd->trk[i]);
+	sec = TOC_SECOND(cd->trk[i]);
         
-	l=sprintf( tmp, "%u ", calc_offset(min,sec,cd->trk[i].toc.cdte_addr.msf.frame));
+	l=sprintf( tmp, "%u ", calc_offset(min,sec,TOC_FRAME(cd->trk[i])));
 	
 	if(blen>l)
 	{
@@ -257,8 +257,8 @@
 	}
     }
     l=sprintf( tmp, "%i\n",
-	       (cd->trk[cd->last_t+1].toc.cdte_addr.msf.minute*60)
-	       +(cd->trk[cd->last_t+1].toc.cdte_addr.msf.second) );
+	       (TOC_MINUTE(cd->trk[cd->last_t+1])*60)
+	       +(TOC_SECOND(cd->trk[cd->last_t+1])) );
     if(blen>l)
 	strcat( buf,tmp );
 
@@ -298,9 +298,9 @@
 
 	for( i=0; i <= cd->last_t+1; i++ )
 	{
- 		cdtoc[i].frame = cd->trk[i+1].toc.cdte_addr.msf.frame;
- 		cdtoc[i].min = cd->trk[i+1].toc.cdte_addr.msf.minute;
- 		cdtoc[i].sec = cd->trk[i+1].toc.cdte_addr.msf.second;
+ 		cdtoc[i].frame = TOC_FRAME(cd->trk[i+1]);
+ 		cdtoc[i].min = TOC_MINUTE(cd->trk[i+1]);
+ 		cdtoc[i].sec = TOC_SECOND(cd->trk[i+1]);
  	}
  	
 
