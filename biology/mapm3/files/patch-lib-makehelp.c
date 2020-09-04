--- lib/makehelp.c.orig	1993-02-09 21:19:35 UTC
+++ lib/makehelp.c
@@ -131,7 +131,7 @@ char *name;
 {
     close_file(file);
 
-    fwrite(hlp,"@end\n");
+    fwrite(hlp,WRS("@end\n"));
     close_file(hlp);
 
     write_topics_and_end();
@@ -172,9 +172,9 @@ char *argv[];
 	strcpy(man_name, argv[4]);
 
 	strcpy(code_failed,code_name);
-	make_filename(code_failed,FORCE_EXTENSION,"failed");
+	make_filename(code_failed,FORCE_EXTENSION,WRS("failed"));
 	strcpy(final_hlp_name,hlp_name);
-	make_filename_in_dir(final_hlp_name,FORCE_EXTENSION,"help",
+	make_filename_in_dir(final_hlp_name,FORCE_EXTENSION,WRS("help"),
 			     FORCE_DIR,argv[5]);
 
 	file= open_file(file_name,READ);
@@ -187,16 +187,16 @@ char *argv[];
 	matrix(entry,MAX_COMMANDS,MAXLINE+1,char);
 
 	/* start help file 12345678901234567890123456789012345 */
-	fwrite(hlp,       "#MAPMAKER help file - do not edit!\n");
+	fwrite(hlp,WRS("#MAPMAKER help file - do not edit!\n"));
 	pos= 34l + LINE_BREAK_LEN;
 	
 	/* code file */
-	fwrite(code,"/* MAPMAKER help code file - do not edit! */ \n\n");
-	fwrite(code,"#define INC_LIB \n#define INC_SHELL \n");
-	fwrite(code,"#include \"system.h\" \n\n");
+	fwrite(code,WRS("/* MAPMAKER help code file - do not edit! */ \n\n"));
+	fwrite(code,WRS("#define INC_LIB \n#define INC_SHELL \n"));
+	fwrite(code,WRS("#include \"system.h\" \n\n"));
 	/* sf(ps,"char help_filename[]= \"%s\";\n\n",final_hlp_name);
 	   fwrite(code,ps); */
-	fwrite(code,"void make_help_entries()\n{\n");
+	fwrite(code,WRS("void make_help_entries()\n{\n"));
 
 	/* man file */
 	man_write_title();
@@ -242,7 +242,7 @@ char *argv[];
 	    strcpy(name,str+i); despace(name);
 	    nextstr();
 	    sf(ps,"\t%s...  ",name); pr(); flush();
-	    
+
 	    if      (streq(type,"cmd"))   parse_entry(CMD,name,abbreviation); 
 	    else if (streq(type,"opt"))   parse_entry(OPT,name,abbreviation); 
 	    else if (streq(type,"param")) parse_entry(PAR,name,abbreviation);
@@ -419,7 +419,7 @@ void write_topics_and_end()
 	sf(ps," mktopic(%d,\"%s\",TOP,%ldl);\n",s,temp,position[s]);
 	fpr(code); s++;
     }
-    fprint(code,"}\n");
+    fprint(code,WRS("}\n"));
 }
 
 
@@ -681,7 +681,7 @@ void man_write_contents()
 	    case TOP:
 	      man_write_line("");
 	      strcpy(upcase,section[s]); uppercase(upcase);
-	      sf(temp," %s\(%d\) %s ",(s>=10 ? "":" "),s,upcase); s++; break;
+	      sf(temp," %s(%d) %s ",(s>=10 ? "":" "),s,upcase); s++; break;
 	    case CMD: 
 	      strcpy(upcase,entry[i]); uppercase(upcase);
 	      sf(temp,"      %s Command ",upcase); break;
@@ -718,7 +718,7 @@ void man_write_contents()
 	if (entry_type[i]==TOP) {
 	    man_write_line("");
 	    strcpy(upcase,section[s]); uppercase(upcase);
-	    sf(temp,"%s\(%d\) %s ",(s>=10 ? "":""),s,upcase); s++;
+	    sf(temp,"%s(%d) %s ",(s>=10 ? "":""),s,upcase); s++;
 	    man_write_line(temp);
 	} else {
 	    sf(temp,"%s%s",entry[i],(entry_type[i]==HLP ? "*":""));
