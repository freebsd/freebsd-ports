
$FreeBSD$

--- src/as80.c.orig	Fri Nov 30 02:34:26 2001
+++ src/as80.c	Fri Nov 30 02:36:13 2001
@@ -26,11 +26,6 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <errno.h>
-
-#if SYSTEM == GNU
-#include <getopt.h>
-#endif
-
 #include "types.h"
 #include "symtbl.h"
 #include "as80.h"
@@ -218,8 +213,6 @@
 int
 init (int argc, char **argv)
 {
-/* on a GNU system we can use getopt to parse command line options */
-#if SYSTEM == GNU
   int index, c;
 
   /* no proper command line input */
@@ -294,78 +287,6 @@
 	  break;
 	}
     }
-
-#else
-  /* otherwise we have to do it manually */
-  int arg = 1;
-
-  puts ("non-GNU system\n");
-
-  /* no proper command line input */
-  if (argc < 2)
-    {
-      fprintf (stderr,
-	       "usage: %s infile [-o outfile] [-l listfile] [-s symfile]\n",
-	       argv[0]);
-      return ERR_INIT;
-    }
-
-  /* parse */
-  while (arg < argc)
-    {
-      if (argv[arg][0] != '-')
-	{
-	  iname = argv[arg];
-	  if ((IN = fopen (iname, "r")) == NULL)
-	    {
-	      perror ("couldn't open input file");
-	      return ERR_INIT;
-	    }
-	  arg = 1;
-	  break;
-	}
-      arg++;
-    }
-
-  while ((arg < argc) && (argv[arg][0] == '-'))
-    {
-      if (strcmp (argv[arg], "-o"))
-	{
-	  if ((OUT = fopen (argv[++arg], "wb")) == NULL)
-	    {
-	      perror ("couldn't topen output file");
-	      return ERR_INIT;
-	    }
-	  doout = 1;
-	}
-      else if (strcmp (argv[arg], "-l"))
-	{
-	  if ((LST = fopen (optarg, "w")) == NULL)
-	    {
-	      perror ("couldn't open list file");
-	      return ERR_INIT;
-	    }
-	  dolist = 1;
-	}
-      else if (strcmp (argv[arg], "-s"))
-	{
-	  if ((SYM = fopen (optarg, "w")) == NULL)
-	    {
-	      perror ("couldn't open symbol file");
-	      return ERR_INIT;
-	    }
-	  dosym = 1;
-	}
-      else
-	{
-	  fprintf (stderr, "unknown option %s\n", argv[arg]);
-	  return ERR_INIT;
-	}
-
-      arg++;
-    }
-
-#endif
 
   /* open default outputfile */
   if (doout == 0)
