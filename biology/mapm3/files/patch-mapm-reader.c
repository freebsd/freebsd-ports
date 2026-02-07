--- mapm/reader.c.orig	1993-02-09 16:35:05 UTC
+++ mapm/reader.c
@@ -81,7 +81,7 @@ void data_init()
 
 void getdataln(fp) /* get next nonblank,noncomment data file line */
 FILE *fp;
-{ do { fgetln(fp); data_line++; } while (nullstr(ln)||ln[0]=='#'); }
+{ do { fgetln_(fp); data_line++; } while (nullstr(ln)||ln[0]=='#'); }
 
   
 void baddata(reason) /* send data reading error message */
@@ -135,7 +135,7 @@ bool *exists;
     char tmpname[PATH_LENGTH+1];
 
     make_filename(name,FORCE_EXTENSION,ext);
-    strcpy(tmpname,name); make_filename(tmpname,FORCE_EXTENSION,TEMP_EXT);
+    strcpy(tmpname,name); make_filename(tmpname,FORCE_EXTENSION,WRS(TEMP_EXT));
    
     fp=NULL; *exists=FALSE;
     run {
@@ -162,7 +162,7 @@ char *name, *oldext;
 bool exists;
 {
     char tmpname[PATH_LENGTH+1], oldname[PATH_LENGTH+1];
-    strcpy(tmpname,name); make_filename(tmpname,FORCE_EXTENSION,TEMP_EXT);
+    strcpy(tmpname,name); make_filename(tmpname,FORCE_EXTENSION,WRS(TEMP_EXT));
     strcpy(oldname,name); make_filename(oldname,FORCE_EXTENSION,oldext);
 
     if (exists) { rename_file(name,oldname); }
@@ -214,7 +214,7 @@ bool israw;
 		raw.data.f2.cross_type);
     print(" ok\n");
 
-    make_filename(name,FORCE_EXTENSION,MAPS_EXT); strcpy(type,"map");
+    make_filename(name,FORCE_EXTENSION,WRS(MAPS_EXT)); strcpy(type,"map");
     run {
 	fp2=NULL;
         fp2=open_file(name,READ);
@@ -228,7 +228,7 @@ bool israw;
 	close_file(fp2);
     } except_when(CANTOPEN) { } /* need a better handler */
 
-    make_filename(name,FORCE_EXTENSION,TWO_EXT); strcpy(type,"two-point");
+    make_filename(name,FORCE_EXTENSION,WRS(TWO_EXT)); strcpy(type,"two-point");
     run {
 	fp2=NULL;
 	fp2=open_file(name,READ);
@@ -240,7 +240,7 @@ bool israw;
 	close_file(fp2);
     } except_when(CANTOPEN) { } /* need a better handler */
 
-    make_filename(name,FORCE_EXTENSION,THREE_EXT); strcpy(type,"three-point");
+    make_filename(name,FORCE_EXTENSION,WRS(THREE_EXT)); strcpy(type,"three-point");
     run {
 	fp2=NULL;
         fp2=open_file(name,READ);
@@ -285,39 +285,39 @@ bool save_genos_too;
     run {
 	strcpy(name,base_name);
 	if (save_genos_too) {
-	    fp= start_save_to_file(name,DATA_EXT,"genotype",&exists);
+	    fp= start_save_to_file(name,WRS(DATA_EXT),"genotype",&exists);
 	    write_f2_data(fp); /* deals with header and magic number */
 	    close_file(fp); fp=NULL;
-	    finish_save_to_file(name,DATA_OLD,exists);
+	    finish_save_to_file(name,WRS(DATA_OLD),exists);
 	}
-	fp= start_save_to_file(name,MAPS_EXT,"map",&exists);
+	fp= start_save_to_file(name,WRS(MAPS_EXT),"map",&exists);
 	write_magic_number(fp,"map");
 	write_order_data(fp);
 	write_mapping_data(fp);
 	write_status(fp);
 	close_file(fp); fp=NULL;
-	finish_save_to_file(name,MAPS_OLD,exists);
+	finish_save_to_file(name,WRS(MAPS_OLD),exists);
 
 	if (two_pt_touched) {
-	    fp= start_save_to_file(name,TWO_EXT,"two-point",&exists);
+	    fp= start_save_to_file(name,WRS(TWO_EXT),"two-point",&exists);
 	    write_magic_number(fp,"two-point");
 	    write_two_pt(fp);
 	    close_file(fp); fp=NULL;
-	    finish_save_to_file(name,TWO_OLD,exists);
+	    finish_save_to_file(name,WRS(TWO_OLD),exists);
 	}
 	if (three_pt_touched) {
-	    fp= start_save_to_file(name,THREE_EXT,"three-point",&exists);
+	    fp= start_save_to_file(name,WRS(THREE_EXT),"three-point",&exists);
 	    write_magic_number(fp,"three-point");
 	    write_three_pt(fp);
 	    close_file(fp); fp=NULL;
-	    finish_save_to_file(name,THREE_OLD,exists);
+	    finish_save_to_file(name,WRS(THREE_OLD),exists);
 	}
 	if (num_traits>0) {
-	    fp= start_save_to_file(name,TRAIT_EXT,"traits",&exists);
+	    fp= start_save_to_file(name,WRS(TRAIT_EXT),"traits",&exists);
 	    write_magic_number(fp,"trait");
 	    write_traits(fp);
 	    close_file(fp); fp=NULL;
-	    finish_save_to_file(name,TRAIT_OLD,exists);
+	    finish_save_to_file(name,WRS(TRAIT_OLD),exists);
 	    free_traits();
 	}
 	two_pt_touched= FALSE;
@@ -576,15 +576,15 @@ FILE *fp;
     char header[MAXLINE+1];
 
     if (raw.data.f2.cross_type==F2_INTERCROSS) 
-      fprint(fp,"prepared data f2 intercross\n");
+      fprint(fp,WRS("prepared data f2 intercross\n"));
     else if (raw.data.f2.cross_type==F2_BACKCROSS) 
-      fprint(fp,"prepared data f2 backcross\n");
+      fprint(fp,WRS("prepared data f2 backcross\n"));
     else if (raw.data.f2.cross_type==RI_SIB) 
-      fprint(fp,"prepared data f2 ri-sib\n");
+      fprint(fp,WRS("prepared data f2 ri-sib\n"));
     else if (raw.data.f2.cross_type==RI_SELF) 
-      fprint(fp,"prepared data f2 ri-self\n");
+      fprint(fp,WRS("prepared data f2 ri-self\n"));
     else if (raw.data.f2.cross_type==F3_SELF)
-      fprint(fp,"prepared data f3\n");
+      fprint(fp,WRS("prepared data f3\n"));
     
     sf(header,"%d %d %d\n",raw.filenumber,raw.data.f2.num_indivs,
        raw.num_markers); fprint(fp,header);
@@ -593,7 +593,7 @@ FILE *fp;
 	sf(ps,"*%-10s   ", raw.locus_name[i]);
 	fpr(fp);
 	for (j=0; j<raw.data.f2.num_indivs; j++) {
-	    if (j%50==0 && j!=0) fprint(fp,"\n        ");
+	    if (j%50==0 && j!=0) fprint(fp,WRS("\n        "));
 	    sf(ps,"%c",raw.data.f2.allele[i][j]);
 	    fpr(fp);
 	    }
@@ -828,9 +828,7 @@ int chr;
 char *symb;
 {
     /* CHANGED FOR THIS VERION - NOW READS "-AHBCD" */
-
-    if      (chr==symb[0]) return(MISSING_DATA);
-    else if (chr==symb[1]) return(PARENTAL_TYPE_A);
+if      (chr==symb[0]) return(MISSING_DATA); else if (chr==symb[1]) return(PARENTAL_TYPE_A);
     else if (chr==symb[2]) return(HYBRID_TYPE_H);
     else if (chr==symb[3]) return(PARENTAL_TYPE_B);
     else if (chr==symb[4]) return(TYPE_NOT_A);
@@ -856,26 +854,26 @@ FILE *fp;
 	fnl(fp);
     }
     fnl(fp);
-    fprint(fp,"#QTL only variables:\n");
-    fprint(fp,"*Print mapm loci: 1\n");
-    fprint(fp,"*Like tolerance: 0.001\n");
-    fprint(fp,"*Brute force: 1\n");
-    fprint(fp,"*Max intervals: -7\n");
-    fprint(fp,"*Max continuous vars: -3\n");
-    fprint(fp,"*Max wiggles: 0\n");
-    fprint(fp,"*Max compares: 0\n");
-    fprint(fp,"*Default units: 1\n");
-    fprint(fp,"*Chromosomes: 0\n");
-    fprint(fp,"*Number of contexts: 1\n");
-    fprint(fp,"*Active context: 0\n");
+    fprint(fp,WRS("#QTL only variables:\n"));
+    fprint(fp,WRS("*Print mapm loci: 1\n"));
+    fprint(fp,WRS("*Like tolerance: 0.001\n"));
+    fprint(fp,WRS("*Brute force: 1\n"));
+    fprint(fp,WRS("*Max intervals: -7\n"));
+    fprint(fp,WRS("*Max continuous vars: -3\n"));
+    fprint(fp,WRS("*Max wiggles: 0\n"));
+    fprint(fp,WRS("*Max compares: 0\n"));
+    fprint(fp,WRS("*Default units: 1\n"));
+    fprint(fp,WRS("*Chromosomes: 0\n"));
+    fprint(fp,WRS("*Number of contexts: 1\n"));
+    fprint(fp,WRS("*Active context: 0\n"));
     fnl(fp);
-    fprint(fp,"*Context 1\n");
+    fprint(fp,WRS("*Context 1\n"));
     if(num_traits == 1)
-      fprint(fp,"*Trait: 0\n");
+      fprint(fp,WRS("*Trait: 0\n"));
     else 
-      fprint(fp,"*Trait: -1\n");
-    fprint(fp,"*Named sequences: 0\n");
-    fprint(fp,"*Sequence history: 0\n");
+      fprint(fp,WRS("*Trait: -1\n"));
+    fprint(fp,WRS("*Named sequences: 0\n"));
+    fprint(fp,WRS("*Sequence history: 0\n"));
 }
 
 
