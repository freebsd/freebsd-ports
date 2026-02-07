--- mapm/sys_cmds.c.orig	1993-02-09 16:35:06 UTC
+++ mapm/sys_cmds.c
@@ -98,7 +98,7 @@ bool prev_data, raw;
 	close_file(fp);
 	if (raw) {
 	    strcpy(run_file,name); 
-	    make_filename(run_file,FORCE_EXTENSION,PREP_EXT);
+	    make_filename(run_file,FORCE_EXTENSION,WRS(PREP_EXT));
 	    if (!redirect_input(run_file,FALSE)) {
 		sf(ps,"unable to run file '%s'... skipping initialization\n",
 		   run_file); pr();
@@ -145,7 +145,7 @@ command new_load_data()
 	if (!prev_data) print("no data are loaded\n");
 	else { sf(ps,DATA_LOADED,raw.filename,data_info(TRUE)); pr(); }
     } else {
-	fp=try_to_open(name,FORCE_EXTENSION,DATA_EXT,prev_data);
+	fp=try_to_open(name,FORCE_EXTENSION,WRS(DATA_EXT),prev_data);
 	if (prev_data) try_to_unload(fp,TRUE,auto_save,TRUE,just_prepared);
 	try_to_load(fp,name,prev_data,FALSE);
 	just_prepared=FALSE;
@@ -169,7 +169,7 @@ command new_prepare()
        if (streq(&name[end-4],DATA_EXT) || streq(&name[end-4],DATA_OLD) ||...
        error(RAW_EXTENSION); */
 
-    fp= try_to_open(name,DEFAULT_EXTENSION,RAW_EXT,prev_data);
+    fp= try_to_open(name,DEFAULT_EXTENSION,WRS(RAW_EXT),prev_data);
     if (prev_data) try_to_unload(fp,TRUE,auto_save,TRUE,just_prepared);
     try_to_load(fp,name,prev_data,TRUE);
     just_prepared=TRUE;
@@ -186,7 +186,7 @@ command new_save_data()
     get_one_arg(stoken,"",name); new_name= !nullstr(name);
     /* want to change this so it sets raw.filename only AFTER it writes OK */
 
-    if (new_name && !make_filename(name,FORCE_EXTENSION,DATA_EXT))
+    if (new_name && !make_filename(name,FORCE_EXTENSION,WRS(DATA_EXT)))
       { sf(ps,BAD_FILENAME,name); error(ps); }
 
     run {
@@ -621,7 +621,7 @@ command new_insert()
 	for (j=num_seq_tokens-1; j>i; j--)
 	  strcpy(seq_tokens[j+1],seq_tokens[j]);
 	/* this is severly broken, if len(appendage) > TOKLEN */
-	strcpy(seq_tokens[i+i],appendage);
+	strcpy(seq_tokens[i+1],appendage);
 	num_seq_tokens++;
 	
 	untokenize_seq(new_seq,seq_tokens,num_seq_tokens);
