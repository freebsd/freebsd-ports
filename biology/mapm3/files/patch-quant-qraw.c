--- quant/qraw.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ quant/qraw.c	2008-03-27 21:30:39.000000000 +0000
@@ -124,7 +124,7 @@
 
 void getdataln(fp) /* get next nonblank/noncomment data file line */
 FILE *fp;
-{ do { fgetln(fp); BADDATA_line_num++; } while(nullstr(ln) || ln[0]=='#'); 
+{ do { fgetln_(fp); BADDATA_line_num++; } while(nullstr(ln) || ln[0]=='#'); 
   BADDATA_ln= ln; }
 real read_map_distance();
 void read_map_locus();
@@ -426,13 +426,13 @@
 
 	    for(j=0;j<raw.n_indivs;j++) {
 		if(j % 5 == 0 && j != 0)
-		  fprint(fp,"\n          ");
+		  fprint(fp,WRS("\n          "));
 		sf(ps,"%12.3lf ", raw.trait[j][i]);fpr(fp);
 	    }
 	    fnl(fp);
 	}
 
-	fprint(fp,"#QTL only variables:\n");
+	fprint(fp,WRS("#QTL only variables:\n"));
 	sf(ps,"*Print mapm loci: %d\n", print_mapm_loci);fpr(fp);
 	sf(ps,"*Like tolerance: %lf\n",like_tolerance);fpr(fp);
 	sf(ps,"*Brute force: %d\n",brute_force);fpr(fp);
@@ -452,21 +452,21 @@
 	    sf(ps, "chr%d %d\n", i+1, raw.chrom_n_loci[i]); fpr(fp);
 	    for(j=0;j<raw.chrom_n_loci[i];j++) {
 		if(j % 18 == 0 && j != 0)
-		  fprint(fp,"\n");
+		  fprint(fp,WRS("\n"));
 		sf(ps, "%d ",order[loci_tot]);fpr(fp);
 		loci_tot++;
 	    }
 	    fnl(fp);
 	    for(j=0;j<raw.chrom_n_loci[i]-1;j++) {
 		if(j % 12 == 0 && j != 0)
-		  fprint(fp,"\n");
+		  fprint(fp,WRS("\n"));
 		sf(ps, "%.4lf ",map_space[map_tot]);fpr(fp);
 		map_tot++;
 	    }
 	    fnl(fp);
 	    map_tot++;
-	    fprint(fp,"0\n");
-	    fprint(fp,"0\n");
+	    fprint(fp,WRS("0\n"));
+	    fprint(fp,WRS("0\n"));
 	}
 	sf(ps,"*Number of contexts: %d\n",num_contexts);
 	fpr(fp);
