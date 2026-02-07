--- quant/qcmds.c.orig	1993-02-09 21:12:33 UTC
+++ quant/qcmds.c
@@ -1348,7 +1348,7 @@ command load_data() 
     if (nullstr(args)) {
 	if (!data_loaded()) print(NO_LOADED_DATA); else {
 	    strcpy(tfile,raw.file);
-	    make_filename(tfile,FORCE_EXTENSION,TRAIT_EXT);
+	    make_filename(tfile,FORCE_EXTENSION,WRS(TRAIT_EXT));
 	    sf(ps,LOADED_DATA,raw.file,tfile,"",raw.n_indivs,
 	       (raw.data_type==BACKCROSS ? "backcross":"intercross"),
 	       raw.n_loci,raw.n_traits,maybe_s(raw.n_traits)); pr();
@@ -1363,9 +1363,9 @@ command load_data() 
 	nstoken(&args,sREQUIRED,dfile,PATH_LENGTH); tfile[0]='\0';
 	nomore_args(num_args);
 	run {
-	    if (!make_filename(dfile,FORCE_EXTENSION,DATA_EXT)) send(CANTOPEN);
+	    if (!make_filename(dfile,FORCE_EXTENSION,WRS(DATA_EXT))) send(CANTOPEN);
 	    fpa= open_file(dfile,READ);
-	    fgetln(fpa);
+	    fgetln_(fpa);
 
 	    if (streq(ln,"prepared data f2 backcross")) {
 		strcpy(geno_chars,default_backcross_chars);
@@ -1384,11 +1384,11 @@ command load_data() 
 	    }
 
 	    strcpy(tfile,dfile);
-	    if (!make_filename(tfile,FORCE_EXTENSION,TRAIT_EXT))
+	    if (!make_filename(tfile,FORCE_EXTENSION,WRS(TRAIT_EXT)))
 	      send(CANTOPEN);
 	    fpb = open_file(tfile,READ);
 	    strcpy(mfile,dfile);
-	    if (!make_filename(mfile,FORCE_EXTENSION,MAPS_EXT))
+	    if (!make_filename(mfile,FORCE_EXTENSION,WRS(MAPS_EXT)))
 	      send(CANTOPEN);
 	    fpc = open_file(mfile,READ);
 
@@ -1449,7 +1449,7 @@ command prep_data()
 
 	out_name = get_temp_string();
 	strcpy(out_name,in_name);
-	make_filename(out_name,FORCE_EXTENSION,DATA_EXT);
+	make_filename(out_name,FORCE_EXTENSION,WRS(DATA_EXT));
 
  fp = open_file(in_name,READ);
 	getdataln(fp);  crunch(ln);
@@ -1488,7 +1488,7 @@ command save_status()
     name = mkstrcpy(raw.file);
     name3 = mkstrcpy(raw.file);
     name2 = "dummy.qtls";
-    make_filename(name, FORCE_EXTENSION, QTL_EXT);
+    make_filename(name, FORCE_EXTENSION, WRS(QTL_EXT));
 
     /* The following accounts for the case where there is no file 'name'
        (i.e. it makes one)  */
@@ -1500,7 +1500,7 @@ command save_status()
 	close_file(fp);
     }
 
-    make_filename(name3, FORCE_EXTENSION, QTL_OLD);
+    make_filename(name3, FORCE_EXTENSION, WRS(QTL_OLD));
     run {
 	fp = open_file(name2, WRITE);
 	sf(ps,"Now saving %s...\n",name);  pr();
@@ -1520,8 +1520,8 @@ command save_status()
     }
 
     name2="dummy.traits";
-    make_filename(name, FORCE_EXTENSION, TRAIT_EXT);
-    make_filename(name3, FORCE_EXTENSION, TRAIT_OLD);
+    make_filename(name, FORCE_EXTENSION, WRS(TRAIT_EXT));
+    make_filename(name3, FORCE_EXTENSION, WRS(TRAIT_OLD));
     run {
 	fp = open_file(name2, WRITE);
 	sf(ps,"Now saving %s...\n",name);  pr();
@@ -1560,7 +1560,7 @@ FILE *fp;
 	save_wiggle(fp,i);
     }
     
-    fprint(fp,"#Compares\n");
+    fprint(fp,WRS("#Compares\n"));
     
     fprintf(fp,"%d %d\n",num_compares,first_compare);
     for(i = 0; i < num_compares; i++) {
@@ -1587,7 +1587,7 @@ void load_qtl_files()
 
     run {
 	strcpy(name,raw.file);
-	make_filename(name,FORCE_EXTENSION,QTL_EXT);
+	make_filename(name,FORCE_EXTENSION,WRS(QTL_EXT));
 	fp= open_file(name,READ);
 
 	if(fscanf(fp,"%d\n",&filenum) != 1) send(IOERROR); /* KLUDGE */
