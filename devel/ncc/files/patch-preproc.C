preproc.C:275:7: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
"ncc "NCC_VERSION"  -  The new/next generation C compiler\n"
      ^

--- preproc.C.orig	2008-10-11 15:18:56 UTC
+++ preproc.C
@@ -47,7 +47,7 @@ static void openout (char *f, char *mode = "w")
 	if (!f) return;
 	char *c = (char*) alloca (strlen (f) + sizeof OUTPUT_EXT);
 	report_stream = fopen (strcat (strcpy (c, f), OUTPUT_EXT), mode);
-	fprintf (stderr, "ncc: output file is ["COLS"%s"COLE"]\n", c);
+	fprintf (stderr, "ncc: output file is [" COLS "%s" COLE "]\n", c);
 }
 
 static void stripout (char *f)
@@ -55,7 +55,7 @@ static void stripout (char *f)
 	if (report_stream != stdout) {
 		fclose (report_stream);
 		char tmp [1024];
-		sprintf (tmp, "nccstrip2.py %s"OUTPUT_EXT" %s"OUTPUT_EXT, f, f);
+		sprintf (tmp, "nccstrip2.py %s" OUTPUT_EXT " %s" OUTPUT_EXT, f, f);
 		system (tmp);
 	}
 	report_stream = stdout;
@@ -86,7 +86,7 @@ static void LINK (char **obj, int objn)
 		strcat (strcpy (ncobj, obj [i]), OUTPUT_EXT);
 		load_file L (ncobj);
 		if (L.success == ZC_OK) {
-			fprintf (stderr, "ncc: Linking object file ["COLS"%s"COLE"] (%i bytes)\n",
+			fprintf (stderr, "ncc: Linking object file [" COLS "%s" COLE "] (%i bytes)\n",
 				 ncobj, L.len);
 			PRINTF (NCCOBJ"%s\n", ncobj);
 			CATFILE (L.data, L.len, report_stream);
@@ -157,7 +157,7 @@ static void nccar_x (int argc, char **argv)
 			n [strlen (n) - 1] = 0;
 			if (OUTF) fclose (OUTF);
 			OUTF = fopen (n, "w");
-			fprintf (stderr, "ncc: extract ["COLS"%s"COLE"]\n", n);
+			fprintf (stderr, "ncc: extract [" COLS "%s" COLE "]\n", n);
 		}
 		if (OUTF)
 			fputs (tmp, OUTF);
@@ -272,7 +272,7 @@ static void emubinutils (int argc, char **argv)
 }
 
 const char help [] =
-"ncc "NCC_VERSION"  -  The new/next generation C compiler\n"
+"ncc " NCC_VERSION "  -  The new/next generation C compiler\n"
 "The user is the only one responsible for any damages\n"
 "Written by Stelios Xanthakis\n"
 "Homepage: http://students.ceid.upatras.gr/~sxanth/ncc/\n"
@@ -282,10 +282,10 @@ const char help [] =
 "	-ncgcc=PROG : use PROG instead of \"gcc\"\n"
 "	-nccpp=PROG : use PROG for preprocessing\n"
 " Files:\n"
-"	-ncld : emulate object file output: write the output to <objectfile>"OUTPUT_EXT"\n"
-"	-ncoo : write the output to sourcefile.c"OUTPUT_EXT"\n"
+"	-ncld : emulate object file output: write the output to <objectfile>" OUTPUT_EXT "\n"
+"	-ncoo : write the output to sourcefile.c" OUTPUT_EXT "\n"
 "	-ncspp : keep sourcefile.i preprocessor output instead of "
-				PREPROCESSOR_OUTPUT"\n"
+				PREPROCESSOR_OUTPUT "\n"
 " Output:\n"
 "	-nccc : compile and produce virtual bytecode\n"
 "	-ncmv : display multiple uses of functions and variables\n"
@@ -301,7 +301,7 @@ const char help [] =
 "	-nc- : ignored option\n"
 "\nncc can also be called as 'nccar', 'nccld', 'nccc++', 'nccg++'\n"
 "In these cases it will invoke the programs 'ar', 'ld', 'c++' and 'g++'\n"
-"and then attempt to collect and link object files with the extension "OUTPUT_EXT"\n"
+"and then attempt to collect and link object files with the extension " OUTPUT_EXT "\n"
 ;
 
 void preproc (int argc, char**argv)
