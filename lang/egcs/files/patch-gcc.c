--- gcc/gcc.c.orig	1999/08/26 09:27:23	1.1.1.3
+++ gcc/gcc.c	1999/09/13 15:50:16	1.10
@@ -21,6 +21,8 @@
 This paragraph is here to try to keep Sun CC from dying.
 The number of chars here seems crucial!!!!  */
 
+/* $from_FreeBSD: src/contrib/gcc/gcc.c,v 1.10 1999/09/13 15:50:16 bde Exp $ */
+
 /* This program is the user interface to the C compiler and possibly to
 other compilers.  It is used because compilation is a complicated procedure
 which involves running several programs and passing temporary files between
@@ -2401,6 +2403,9 @@
 /* Gives value to pass as "warn" to add_prefix for standard prefixes.  */
 static int *warn_std_ptr = 0;
 
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+static int objformat_aout = 0;	/* ELF by default */
+#endif
 
 #if defined(HAVE_OBJECT_SUFFIX) || defined(HAVE_EXECUTABLE_SUFFIX)
 
@@ -2712,6 +2717,39 @@
 	}
     }
 
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+  {
+    /* first hint is /etc/objformat */
+    FILE *fp = fopen("/etc/objformat", "r");
+    if (fp) {
+      char buf[1024];
+      buf[1023] = '\0';
+      while (fgets(buf, sizeof(buf) - 1, fp) != NULL) {
+	i = strlen(buf);
+	if (buf[i - 1] == '\n')
+	  buf[i - 1] = '\0';
+	if (strcmp(buf, "OBJFORMAT=aout") == 0)
+	  objformat_aout = 1;
+	else if (strcmp(buf, "OBJFORMAT=elf") == 0)
+	  objformat_aout = 0;
+	else
+	  fprintf(stderr, "Unrecognized line in /etc/objformat: %s\n", buf);
+      }
+      fclose(fp);
+    }
+    /* but the user $OBJFORMAT overrides system default */
+    temp = getenv("OBJFORMAT");
+    if (temp) {
+      if (strcmp(temp, "aout") == 0)
+	objformat_aout = 1;
+      else if (strcmp(temp, "elf") == 0)
+	objformat_aout = 0;
+      else
+	fprintf(stderr, "Unrecognized value of $OBJFORMAT: %s\n", temp);
+    }
+  }
+#endif
+
   /* Convert new-style -- options to old-style.  */
   translate_options (&argc, &argv);
 
@@ -2726,6 +2764,19 @@
 
   for (i = 1; i < argc; i++)
     {
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+      /* .. and command line args override all */
+      if (strcmp (argv[i], "-aout") == 0)
+	{
+	  objformat_aout = 1;
+	  continue;
+	}
+      else if (strcmp (argv[i], "-elf") == 0)
+	{
+	  objformat_aout = 0;
+	  continue;
+	}
+#endif
       if (! strcmp (argv[i], "-dumpspecs"))
 	{
 	  struct spec_list *sl;
@@ -3049,6 +3100,23 @@
      (such as cpp) rather than those of the host system.  */
   /* Use 2 as fourth arg meaning try just the machine as a suffix,
      as well as trying the machine and the version.  */
+#ifdef FREEBSD_NATIVE
+#if defined(__i386__)
+  if (objformat_aout) {
+    n_switches++;		/* add implied -maout */
+    add_prefix (&exec_prefixes, "/usr/libexec/aout/", "BINUTILS",
+	      0, 0, NULL_PTR);
+  } else
+    add_prefix (&exec_prefixes, "/usr/libexec/elf/", "BINUTILS",
+	      0, 0, NULL_PTR);
+#endif
+  add_prefix (&exec_prefixes, "/usr/libexec", "GCC",
+	      0, 0, warn_std_ptr);
+  add_prefix (&exec_prefixes, "/usr/bin", "GCC",
+	      0, 0, warn_std_ptr);
+  add_prefix (&startfile_prefixes, "/usr/libdata/gcc/", "BINUTILS",
+	      0, 0, warn_std_ptr);
+#else /* not FREEBSD_NATIVE */
 #ifndef OS2
   add_prefix (&exec_prefixes, standard_exec_prefix, "BINUTILS",
 	      0, 2, warn_std_ptr);
@@ -3060,6 +3128,7 @@
 	      0, 1, warn_std_ptr);
   add_prefix (&startfile_prefixes, standard_exec_prefix_1, "BINUTILS",
 	      0, 1, warn_std_ptr);
+#endif /* FREEBSD_NATIVE */
 
   tooldir_prefix = concat (tooldir_base_prefix, spec_machine, 
 			   dir_separator_str, NULL_PTR);
@@ -3094,12 +3163,14 @@
 			       dir_separator_str, tooldir_prefix, NULL_PTR);
     }
 
+#ifndef FREEBSD_NATIVE
   add_prefix (&exec_prefixes, 
               concat (tooldir_prefix, "bin", dir_separator_str, NULL_PTR),
 	      "BINUTILS", 0, 0, NULL_PTR);
   add_prefix (&startfile_prefixes,
 	      concat (tooldir_prefix, "lib", dir_separator_str, NULL_PTR),
 	      "BINUTILS", 0, 0, NULL_PTR);
+#endif /* FREEBSD_NATIVE */
 
   /* More prefixes are enabled in main, after we read the specs file
      and determine whether this is cross-compilation or not.  */
@@ -3118,6 +3189,19 @@
      to the copy in the vector of switches.
      Store all the infiles in their vector.  */
 
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+  if (objformat_aout == 1) {
+    switches[n_switches].part1 = "maout";
+    switches[n_switches].args = 0;
+    switches[n_switches].live_cond = 0;
+    switches[n_switches].valid = 0;
+    n_switches++;
+    putenv("OBJFORMAT=aout");
+  } else {
+    putenv("OBJFORMAT=elf");
+  }
+#endif
+
   for (i = 1; i < argc; i++)
     {
       /* Just skip the switches that were handled by the preceding loop.  */
@@ -3137,6 +3221,12 @@
 	;
       else if (! strcmp (argv[i], "-print-multi-directory"))
 	;
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+      else if (! strcmp (argv[i], "-aout"))
+	;
+      else if (! strcmp (argv[i], "-elf"))
+	;
+#endif
       else if (strcmp (argv[i], "-fhelp") == 0)
 	{
 	  if (verbose_flag)
@@ -4592,6 +4682,7 @@
   *cp++ = '.';
   *cp = '\0';
 
+#ifndef FREEBSD_NATIVE
   /* Exclude directories that the linker is known to search.  */
   if (linker
       && ((cp - path == 6
@@ -4602,6 +4693,7 @@
 				       dir_separator_str, "lib", 
 				       dir_separator_str, ".", NULL_PTR)) == 0)))
     return 0;
+#endif /* FREEBSD_NATIVE */
 
   return (stat (path, &st) >= 0 && S_ISDIR (st.st_mode));
 }
@@ -4775,9 +4867,13 @@
 
   /* Read specs from a file if there is one.  */
 
+#ifndef FREEBSD_NATIVE
   machine_suffix = concat (spec_machine, dir_separator_str,
 			   spec_version, dir_separator_str, NULL_PTR);
   just_machine_suffix = concat (spec_machine, dir_separator_str, NULL_PTR);
+#else /* FREEBSD_NATIVE */
+  just_machine_suffix = "";
+#endif /* FREEBSD_NATIVE */
 
   specs_file = find_a_file (&startfile_prefixes, "specs", R_OK);
   /* Read the specs file unless it is a default one.  */
@@ -4857,6 +4953,7 @@
 		      NULL_PTR, 0, 0, NULL_PTR);
 	}		       
 
+#ifndef FREEBSD_NATIVE
       add_prefix (&startfile_prefixes, standard_startfile_prefix_1,
 		  "BINUTILS", 0, 0, NULL_PTR);
       add_prefix (&startfile_prefixes, standard_startfile_prefix_2,
@@ -4864,6 +4961,7 @@
 #if 0 /* Can cause surprises, and one can use -B./ instead.  */
       add_prefix (&startfile_prefixes, "./", NULL_PTR, 0, 1, NULL_PTR);
 #endif
+#endif /* FREEBSD_NATIVE */
     }
   else
     {
@@ -4947,7 +5045,7 @@
 
       if (! verbose_flag)
 	{
-	  printf ("\nReport bugs to egcs-bugs@egcs.cygnus.com.\n");
+	  printf ("\nReport bugs to egcs-bugs@cygnus.com.\n");
 	  printf ("Please see the file BUGS (included with the sources) first.\n");
 	  
 	  exit (0);
@@ -4981,7 +5079,7 @@
     }
 
   if (n_infiles == added_libraries)
-    fatal ("No input files");
+    fatal ("No input files specified");
 
   /* Make a place to record the compiler output file names
      that correspond to the input files.  */
@@ -5137,7 +5235,7 @@
 
   if (print_help_list)
     {
-      printf ("\nReport bugs to egcs-bugs@egcs.cygnus.com.\n");
+      printf ("\nReport bugs to egcs-bugs@cygnus.com.\n");
       printf ("Please see the file BUGS (included with the sources) first.\n");
     }
   
