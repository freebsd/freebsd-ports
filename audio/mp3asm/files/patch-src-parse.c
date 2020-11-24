--- src/parse.c.orig	2001-04-12 03:37:01 UTC
+++ src/parse.c
@@ -43,9 +43,9 @@ static void
 bad_flag (char *string, int i)
 {
   if (!i)
-    sprintf (log.buf, "%s: Bad flag specified: \"%s\"\n", me, string);
+    sprintf (mp3asm_log.buf, "%s: Bad flag specified: \"%s\"\n", me, string);
   else 
-    sprintf (log.buf, "%s: Bad flag specified: \"%s\" from \"%s\"\n", me, string+i, string);
+    sprintf (mp3asm_log.buf, "%s: Bad flag specified: \"%s\" from \"%s\"\n", me, string+i, string);
   print_std (-1);
   exit (EX_USAGE);
 }
@@ -53,7 +53,7 @@ bad_flag (char *string, int i)
 static void
 arg_needed (char flag)
 {
-  sprintf (log.buf, "%s: No argument specified for flag %c\n", me, flag);
+  sprintf (mp3asm_log.buf, "%s: No argument specified for flag %c\n", me, flag);
   print_std (-1);
   exit (EX_USAGE);
 }
@@ -61,7 +61,7 @@ arg_needed (char flag)
 static void
 double_flag (char flag)
 {
-  sprintf (log.buf, "%s: Flag specified twice: \"%c\"\n", me, flag);
+  sprintf (mp3asm_log.buf, "%s: Flag specified twice: \"%c\"\n", me, flag);
   print_std (-1);
   exit (EX_USAGE);
 }
@@ -69,7 +69,7 @@ double_flag (char flag)
 static void
 bad_arg (char *string)
 {
-  sprintf (log.buf, "%s: Bad argument given: \"%s\"\n", me, string);
+  sprintf (mp3asm_log.buf, "%s: Bad argument given: \"%s\"\n", me, string);
   print_std (-1);
   exit (EX_USAGE);
 }
@@ -139,7 +139,7 @@ report (char *arg)
 {
   char *name = tmalloc (1024 * sizeof (char));
   if (!gethostname (name, 1024))
-    sprintf (log.buf, "Sending notification to the authorities; Illegal use of copyrighted material on %s\n", name);
+    sprintf (mp3asm_log.buf, "Sending notification to the authorities; Illegal use of copyrighted material on %s\n", name);
   free (name);
   return (0);
 }
@@ -147,9 +147,9 @@ report (char *arg)
 static int
 use_log (char *arg)
 {
-  if (log.name)
+  if (mp3asm_log.name)
     return (1);
-  log.name = strcpy (tmalloc (strlen (arg) + 1), arg); 
+  mp3asm_log.name = strcpy (tmalloc (strlen (arg) + 1), arg); 
   return (0);
 }
 
@@ -190,11 +190,11 @@ usage (void)
 { 
   int k = 0;
   
-  sprintf (log.buf, "Usage: %s [options] inputfile.mp3 [...]\n", me);
+  sprintf (mp3asm_log.buf, "Usage: %s [options] inputfile.mp3 [...]\n", me);
   print_std (0);
   while (parse[k].flag)
     {
-      sprintf (log.buf, "   -%c     %s\n", parse[k].flag, parse[k].help);
+      sprintf (mp3asm_log.buf, "   -%c     %s\n", parse[k].flag, parse[k].help);
       print_std (0);
       k++;
     }
@@ -259,7 +259,7 @@ parse_argument (int argc, char *argv[])
 	  
 	  input[inputs - 1]->name = tmalloc (strlen (argv[i]) + 1);
 	   strcpy (input[inputs - 1]->name, argv[i]);
-	   /*sprintf (log.buf, "%d input: %s\n", inputs - 1, input[inputs - 1]->name);
+	   /*sprintf (mp3asm_log.buf, "%d input: %s\n", inputs - 1, input[inputs - 1]->name);
 	     print_std (5);*/
 	  new_input ();
 	}
@@ -285,7 +285,7 @@ check_options ()
       
       if ((input[i]->endframe && (input[i]->startframe > input[i]->endframe)) || (input[i]->startframe && (input[i]->startframe == input[i]->endframe)))
 	{
-	 sprintf (log.buf, "%s: Invalid options given. The number of frames to skip should be smaller than the number of the last frame to read for \"%s\".\n", me, input[i]->name);
+	 sprintf (mp3asm_log.buf, "%s: Invalid options given. The number of frames to skip should be smaller than the number of the last frame to read for \"%s\".\n", me, input[i]->name);
 	 print_std (-1);
  	exit (EX_USAGE);
        }
@@ -293,7 +293,7 @@ check_options ()
       if (input[i]->use_id3) {
 	if (id3)
 	  {
-	    sprintf (log.buf, "%s: Invalid options given. More than one id3 tag specified for use.\n", me);
+	    sprintf (mp3asm_log.buf, "%s: Invalid options given. More than one id3 tag specified for use.\n", me);
 	    print_std (-1);
 	    exit (EX_USAGE);
 	  }
@@ -305,7 +305,7 @@ check_options ()
     {
       if (input[inputs -1]->startframe ||input[inputs -1]->endframe || input[inputs -1]->readframes || input[inputs -1]->use_id3)
 	{
-	  sprintf (log.buf, "%s: Flags specified for input file, but no input file has been given.\n", me);
+	  sprintf (mp3asm_log.buf, "%s: Flags specified for input file, but no input file has been given.\n", me);
 	  print_std (-1);
 	  exit(EX_USAGE);
 	}
@@ -314,37 +314,37 @@ check_options ()
     }
   if (!inputs)
     {
-      sprintf (log.buf, "%s: No input files specified.\n", me);
+      sprintf (mp3asm_log.buf, "%s: No input files specified.\n", me);
       print_std (-1);
       exit (EX_USAGE);
     }
   /* else
     {
-      sprintf (log.buf, "inputs: %d\n", inputs);
+      sprintf (mp3asm_log.buf, "inputs: %d\n", inputs);
       print_std (5);
       }*/
 
   if (!info)
     {
-      sprintf (log.buf, "%s: Program from Olli Fromme & _Death_.\n", me);
+      sprintf (mp3asm_log.buf, "%s: Program from Olli Fromme & _Death_.\n", me);
       print_std (-1);
       
       if (!output->name)
-	sprintf (log.buf, "%s: Checking the following mp3 files for header errors:\n", me);
+	sprintf (mp3asm_log.buf, "%s: Checking the following mp3 files for header errors:\n", me);
       else
-	sprintf(log.buf, "%s: Taking input from:\n", me);
+	sprintf(mp3asm_log.buf, "%s: Taking input from:\n", me);
       print_std (1);
       
       for (i = 0; i < inputs; ++i) 
 	{
-	  sprintf (log.buf, "%s: input %d: %s from frame %ld to %ld [%ld].\n", me, i, input[i]->name, input[i]->startframe, input[i]->endframe, input[i]->readframes);
+	  sprintf (mp3asm_log.buf, "%s: input %d: %s from frame %ld to %ld [%ld].\n", me, i, input[i]->name, input[i]->startframe, input[i]->endframe, input[i]->readframes);
 	  print_std (2);
 	}
       
       if (!output->name)
-	sprintf (log.buf, "%s: No output file specified.\n", me);
+	sprintf (mp3asm_log.buf, "%s: No output file specified.\n", me);
       else
-	sprintf (log.buf, "%s: Outputting to %s.\n", me, output->name);
+	sprintf (mp3asm_log.buf, "%s: Outputting to %s.\n", me, output->name);
       print_std (1);
     }
 }
