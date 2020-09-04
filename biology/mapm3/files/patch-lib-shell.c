--- lib/shell.c.orig	1993-02-09 16:35:25 UTC
+++ lib/shell.c
@@ -129,7 +129,7 @@ char *version_filename;
 
     run {
 	strcpy(name,version_filename);
-	if (!make_filename_in_dir(name,FORCE_EXTENSION,".v",
+	if (!make_filename_in_dir(name,FORCE_EXTENSION,WRS(".v"),
 				  FORCE_DIR,CODE_DIR)) send(CANTOPEN); 
 	fp=open_file(name,READ);
 	finput(fp,ln_,MAXLINE); p=ln_; /* don't hack &ln_ */
@@ -226,7 +226,7 @@ char *program, *version, *copyright, *help_filename; 
     help_uses_wimp_help=  FALSE;
 
     help_file=NULL;
-    if (make_filename_in_dir(help_filename,FORCE_EXTENSION,HELP_EXT,
+    if (make_filename_in_dir(help_filename,FORCE_EXTENSION,WRS(HELP_EXT),
 			     DEFAULT_DIR,CODE_DIR)) {
 	run help_file=open_file(help_filename,READ);
 	  except_when(CANTOPEN) {}
@@ -950,7 +950,7 @@ command run_from_file()
     use_uncrunched_args();
     get_one_arg(stoken,sREQUIRED,file_name);
 
-    if (!make_filename(file_name,DEFAULT_EXTENSION,"in")) 
+    if (!make_filename(file_name,DEFAULT_EXTENSION,WRS("in")))
       error("bad input file name");
     else redirect_input(file_name,TRUE); /* verbose -> messages */
 }
@@ -972,7 +972,7 @@ command do_photo()
 	usage_error(1);
 
     } else if (!nullstr(file_name)) {
-	if (!make_filename(file_name,DEFAULT_EXTENSION,"out")) 
+	if (!make_filename(file_name,DEFAULT_EXTENSION,WRS("out")))
 	  sf(ps,"error: Bad photo file name");
 	if (!photo_to_file(file_name,"a")) 
 	  sf(ps,"error: Unable to open photo file '%s'\n",file_name); 
@@ -1080,12 +1080,12 @@ command help()
 		else if (topic_help_key[i]==HELPLESS) print(NO_HELP_KEY);
 		else {
 		    fgoto_line(help_file,topic_help_key[i]);
-		    fgetln(help_file);
+		    fgetln_(help_file);
 		    got_any=FALSE;
 		    while (ln[0]!='@') {
 			got_any=TRUE;
 			print(ln); nl();
-			fgetln(help_file);
+			fgetln_(help_file);
 		    }
 		    if (!got_any) print(NO_HELP_KEY);
 		}
@@ -1131,12 +1131,12 @@ command help()
 		else if (cmd[i]->help_key==HELPLESS) print(NO_HELP_KEY);
 		else {
 		    fgoto_line(help_file,cmd[i]->help_key);
-		    fgetln(help_file);
+		    fgetln_(help_file);
 		    got_any=FALSE;
 		    while (ln[0]!='@') {
 			got_any=TRUE;
 			print(ln); nl();
-			fgetln(help_file);
+			fgetln_(help_file);
 		    }
 		    if (!got_any) print(NO_HELP_KEY);
 		}
@@ -1164,10 +1164,10 @@ command about()
       { print(NO_HELP_KEY); nl(); print(SURROGATE_ABOUT); }
     else {
 	fgoto_line(help_file,n);
-	fgetln(help_file);
+	fgetln_(help_file);
 	while (ln[0]!='@') {
 	    print(ln); nl();
-	    fgetln(help_file);
+	    fgetln_(help_file);
 	}
     }
     nl(); print(MOREHELP0); print(MOREHELP1); print(MOREHELP2);
