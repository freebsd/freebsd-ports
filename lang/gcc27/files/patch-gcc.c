--- gcc.c.orig	Tue Jun 24 11:42:50 1997
+++ gcc.c	Mon Mar 20 13:29:11 2000
@@ -32,6 +32,7 @@
 compilation is specified by a string called a "spec".  */
 
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <ctype.h>
 #include <signal.h>
 #include <sys/stat.h>
@@ -53,6 +54,9 @@
 #include <varargs.h>
 #endif
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <string.h>
 
 /* Include multi-lib information.  */
 #include "multilib.h"
@@ -1620,7 +1624,6 @@
   char **envp;
   int num_envs = 0;
   int name_len = 1;
-  int str_len = strlen (str);
   char *p = str;
   int ch;
 
@@ -2095,7 +2098,7 @@
       /* Exec the program.  */
       (*func) (program, argv);
       perror_exec (program);
-      exit (-1);
+      _exit (1);
       /* NOTREACHED */
       return 0;
 
@@ -2324,6 +2327,10 @@
   char *language;
 };
 
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+static int objformat_aout = 0;
+#endif
+
 /* Also a vector of input files specified.  */
 
 static struct infile *infiles;
@@ -2469,6 +2476,39 @@
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
 
@@ -2478,6 +2518,19 @@
 
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
 	  printf ("*asm:\n%s\n\n", asm_spec);
@@ -2703,6 +2756,18 @@
      (such as cpp) rather than those of the host system.  */
   /* Use 2 as fourth arg meaning try just the machine as a suffix,
      as well as trying the machine and the version.  */
+#ifdef FREEBSD_NATIVE
+#if defined(__i386__)
+  if (objformat_aout) {
+    n_switches++;		/* add implied -maout */
+    add_prefix (&exec_prefixes, "/usr/libexec/aout/", 0, 0, NULL_PTR);
+  } else
+    add_prefix (&exec_prefixes, "/usr/libexec/elf/", 0, 0, NULL_PTR);
+#endif
+  add_prefix (&exec_prefixes, "/usr/libexec/", 0, 0, NULL_PTR);
+  add_prefix (&exec_prefixes, "/usr/bin/", 0, 0, NULL_PTR);
+  add_prefix (&startfile_prefixes, "/usr/libdata/gcc/", 0, 0, NULL_PTR);
+#else /* not FREEBSD_NATIVE */
 #ifndef OS2
   add_prefix (&exec_prefixes, standard_exec_prefix, 0, 2, NULL_PTR);
   add_prefix (&exec_prefixes, standard_exec_prefix_1, 0, 2, NULL_PTR);
@@ -2710,6 +2775,7 @@
 
   add_prefix (&startfile_prefixes, standard_exec_prefix, 0, 1, NULL_PTR);
   add_prefix (&startfile_prefixes, standard_exec_prefix_1, 0, 1, NULL_PTR);
+#endif /* FREEBSD_NATIVE */
 
   tooldir_prefix = concat3 (tooldir_base_prefix, spec_machine, 
                             dir_separator_str);
@@ -2744,12 +2810,14 @@
                                 dir_separator_str, tooldir_prefix);
     }
 
+#ifndef FREEBSD_NATIVE
   add_prefix (&exec_prefixes, 
               concat3 (tooldir_prefix, "bin", dir_separator_str),
 	      0, 0, NULL_PTR);
   add_prefix (&startfile_prefixes,
 	      concat3 (tooldir_prefix, "lib", dir_separator_str),
 	      0, 0, NULL_PTR);
+#endif /* FREEBSD_NATIVE */
 
   /* More prefixes are enabled in main, after we read the specs file
      and determine whether this is cross-compilation or not.  */
@@ -2768,6 +2836,19 @@
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
@@ -2787,6 +2868,12 @@
 	;
       else if (! strcmp (argv[i], "-print-multi-directory"))
 	;
+#if defined(FREEBSD_NATIVE) && defined(__i386__)
+      else if (! strcmp (argv[i], "-aout"))
+	;
+      else if (! strcmp (argv[i], "-elf"))
+	;
+#endif
       else if (argv[i][0] == '+' && argv[i][1] == 'e')
 	{
 	  /* Compensate for the +e options to the C++ front-end;
@@ -3770,7 +3857,7 @@
 	    {
 	      int c1 = *p++;  /* Select first or second version number.  */
 	      char *v = compiler_version;
-	      char *q, *copy;
+	      char *q;
 	      /* If desired, advance to second version number.  */
 	      if (c1 == '2')
 		{
@@ -4266,8 +4353,10 @@
 
   /* Read specs from a file if there is one.  */
 
+#ifndef FREEBSD_NATIVE
   machine_suffix = concat4 (spec_machine, dir_separator_str,
                             spec_version, dir_separator_str);
+#endif
   just_machine_suffix = concat (spec_machine, dir_separator_str);
 
   specs_file = find_a_file (&startfile_prefixes, "specs", R_OK);
@@ -4326,6 +4415,7 @@
 		      0, 0, NULL_PTR);
 	}		       
 
+#ifndef FREEBSD_NATIVE
       add_prefix (&startfile_prefixes, standard_startfile_prefix_1, 0, 0,
 		  NULL_PTR);
       add_prefix (&startfile_prefixes, standard_startfile_prefix_2, 0, 0,
@@ -4333,6 +4423,8 @@
 #if 0 /* Can cause surprises, and one can use -B./ instead.  */
       add_prefix (&startfile_prefixes, "./", 0, 1, NULL_PTR);
 #endif
+#endif /* FREEBSD_NATIVE */
+
     }
   else
     {
@@ -4423,7 +4515,7 @@
     }
 
   if (n_infiles == 0)
-    fatal ("No input files");
+    fatal ("No input files specified");
 
   /* Make a place to record the compiler output file names
      that correspond to the input files.  */
