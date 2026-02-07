--- lib/syscode.c.orig	1993-02-09 16:35:26 UTC
+++ lib/syscode.c
@@ -198,7 +198,7 @@ long index;
     long fseekvalue= 0L;
     frewind(fp);
     run while (fseekvalue < index-1) {
-	fgetln(help_file);
+	fgetln_(help_file);
 	fseekvalue+=len(ln)+1;
     } except_when(ENDOFILE) return(FALSE);
     return(TRUE);
@@ -742,26 +742,26 @@ char *argv[];
 
 	} else if (matches(argv[i]+1,"load")) {
 	    check_file_arg(*argc_ptr-i,argv[i+1],file_arg[LOAD_FILE_ARG],
-			   "load","data",argv[0],READ);
+			   WRS("load"),WRS("data"),argv[0],READ);
 	    prep_it=FALSE;
 	    argv[i++][0]='\0'; argv[i][0]='\0';
 	} else if (matches(argv[i]+1,"prep")) {
 	    check_file_arg(*argc_ptr-i,argv[i+1],file_arg[LOAD_FILE_ARG],
-			   "prep","raw",argv[0],READ);
+			   WRS("prep"),WRS("raw"),argv[0],READ);
 	    prep_it=TRUE;
 	    argv[i++][0]='\0'; argv[i][0]='\0';
 	} else if (matches(argv[i]+1,"run")) {
 	    check_file_arg(*argc_ptr-i,argv[i+1],file_arg[RUN_FILE_ARG],
-			   "run","in",argv[0],READ);
+			   WRS("run"),WRS("in"),argv[0],READ);
 	    argv[i++][0]='\0'; argv[i][0]='\0';
 	} else if (matches(argv[i]+1,"photo")) {
 	    check_file_arg(*argc_ptr-i,argv[i+1],file_arg[PHOTO_FILE_ARG],
-			   "photo","out",argv[0],APPEND);
+			   WRS("photo"),WRS("out"),argv[0],APPEND);
 	    append_it=TRUE;
 	    argv[i++][0]='\0'; argv[i][0]='\0';
 	} else if (matches(argv[i]+1,"out")) {
 	    check_file_arg(*argc_ptr-i,argv[i+1],file_arg[PHOTO_FILE_ARG],
-			   "photo","out",argv[0],WRITE);
+			   WRS("photo"),WRS("out"),argv[0],WRITE);
 	    append_it=FALSE;
 	    argv[i++][0]='\0'; argv[i][0]='\0';
 	} else if (matches(argv[i]+1,"help")) {
