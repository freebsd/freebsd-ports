--- mapm/maps.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/maps.c	2008-03-23 15:39:56.000000000 +0000
@@ -592,7 +592,7 @@
  
     clean_map(map);
     
-    fgetln(fp);
+    fgetln_(fp);
     if (!nstoken(&ln,sREQUIRED,name,NAME_LEN+1) || name[0]!='*' ||
 	sscanf(ln,"%d %d %d %d %lf",&num_loci,&unlink,&sex,&errors,&like)!=5)
       baddata("expected *chrom-name # # # #");
@@ -603,31 +603,31 @@
     strcpy(map->map_name,name+1); map->allow_errors= errors;
     map->num_loci=num_loci;       map->log_like=like;
 
-    fgetln(fp);
+    fgetln_(fp);
     for (i=0; i<num_loci; i++) {
-	if (nullstr(ln)) fgetln(fp);
+	if (nullstr(ln)) fgetln_(fp);
 	if (!itoken(&ln,iREQUIRED,&num)) send(CRASH);
 	map->locus[i]=num;
     }
-    fgetln(fp);
+    fgetln_(fp);
     for (i=0; i<num_loci-1; i++) {
-	if (nullstr(ln)) fgetln(fp);
+	if (nullstr(ln)) fgetln_(fp);
 	if (!rtoken(&ln,rREQUIRED,&rnum)) send(CRASH);
 	map->rec_frac[i][MALE]=rnum;
     }
 
     if (raw.data_type==CEPH && sex) {
-	fgetln(fp);
+	fgetln_(fp);
 	for(i=0; i<num_loci-1; i++) {
-	    if (nullstr(ln)) fgetln(fp);
+	    if (nullstr(ln)) fgetln_(fp);
 	    if (!rtoken(&ln,rREQUIRED,&rnum)) send(CRASH);
 	    map->rec_frac[i][FEMALE]=rnum;
 	}
     } else for (i=0; i<num_loci-1; i++) map->rec_frac[i][FEMALE]=0.0;
 
-    fgetln(fp);
+    fgetln_(fp);
     for(i=0; i<num_loci-1; i++) {
-	if (nullstr(ln)) fgetln(fp);
+	if (nullstr(ln)) fgetln_(fp);
 	if (!itoken(&ln,iREQUIRED,&num)) send(CRASH);
 	map->fix_interval[i]=num;
     }   
@@ -637,7 +637,7 @@
 	    matrix(map->error_lod,map->max_loci,raw.data.f2.num_indivs,real);
 	}
 	for (i=0; i<map->num_loci; i++) {
-	    fgetln(fp);
+	    fgetln_(fp);
 	    if (!stoken(&ln,sREQUIRED,str) || !streq(str,"errors")) 
 	      send(CRASH);
 	    if (!rtoken(&ln,rREQUIRED,&rnum)) send(CRASH);
@@ -646,9 +646,9 @@
 		for(j=0; j<raw.data.f2.num_indivs; j++) 
 		  map->error_lod[i][j]= 0.0;
 	    } else {
-		fgetln(fp);
+		fgetln_(fp);
 		for (j=0; j<raw.data.f2.num_indivs; j++) {
-		    if (nullstr(ln)) fgetln(fp);
+		    if (nullstr(ln)) fgetln_(fp);
 		    if (!rtoken(&ln,rREQUIRED,&rnum)) send(CRASH);
 		    map->error_lod[i][j]=rnum;
 		}
