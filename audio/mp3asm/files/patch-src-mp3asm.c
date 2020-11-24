--- src/mp3asm.c.orig	2001-04-12 04:16:24 UTC
+++ src/mp3asm.c
@@ -49,17 +49,17 @@ extern void parse_args (int argc, char *argv[]);
 
 int verbosity, inputs, quiet, info; 
 char *me;
-logfile_t log;
+logfile_t mp3asm_log;
 input_t **input;
 output_t *output;
 
 /*
- * getprogname: sets me to be the name of the executable.
+ * mp3info_getprogname: sets me to be the name of the executable.
  *
  */
 
 char *
-getprogname(const char *argv0)
+mp3info_getprogname(const char *argv0)
 {
   char *string;
   (string = strrchr(argv0, '/')) ? string++ : (string = (char *)argv0);
@@ -97,8 +97,8 @@ init_global (char *progname)
 {
   me = strcpy((char *)tmalloc(strlen(progname) + 1), progname);
 
-  log.name = NULL;
-  log.file = NULL;
+  mp3asm_log.name = NULL;
+  mp3asm_log.file = NULL;
 
   verbosity = 0;
   quiet = 0;
@@ -129,7 +129,7 @@ open_inputs (void)
       input[i]->stream = read_stream (input[i]->file);
       if (!input[i]->stream)
 	{
-	  sprintf (log.buf, "bad input file specified\n");
+	  sprintf (mp3asm_log.buf, "bad input file specified\n");
 	  print_std (-1);
 	  exit (EX_NOINPUT);
 	}
@@ -152,7 +152,7 @@ write_output (void)
 
   if (!inputs)
     {
-      sprintf (log.buf, "Please provide valid inputfiles...\n");
+      sprintf (mp3asm_log.buf, "Please provide valid inputfiles...\n");
       print_std (-1);
       exit (EX_USAGE);
     }
@@ -169,7 +169,7 @@ write_output (void)
 	    }
 	  else
 	    {
-	      sprintf (log.buf, "Unable to use a non-existent id3 tag.\n");
+	      sprintf (mp3asm_log.buf, "Unable to use a non-existent id3 tag.\n");
 	      print_std (0);
 	    }
 	}
@@ -200,7 +200,7 @@ write_output (void)
 int
 main(int argc, char *argv[])
 { 
-  init_global (getprogname(argv[0]));
+  init_global (mp3info_getprogname(argv[0]));
 
   parse_args (argc, argv);
 
