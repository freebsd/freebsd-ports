Index: Wnn/etc/getopt1.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/getopt1.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/getopt1.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/getopt1.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -66,14 +66,13 @@
 #endif
 
 int
-getopt_long (argc, argv, options, long_options, opt_index)
-     int argc;
-     char *const *argv;
-     const char *options;
-     const struct option *long_options;
-     int *opt_index;
+getopt_long(int argc,
+	    char * const *argv,
+	    const char *options,
+	    const struct option *long_options,
+	    int *opt_index)
 {
-  return _getopt_internal (argc, argv, options, long_options, opt_index, 0);
+	return _getopt_internal(argc, argv, options, long_options, opt_index, 0);
 }
 
 /* Like getopt_long, but '-' as well as '--' can indicate a long option.
@@ -82,14 +81,13 @@ getopt_long (argc, argv, options, long_o
    instead.  */
 
 int
-getopt_long_only (argc, argv, options, long_options, opt_index)
-     int argc;
-     char *const *argv;
-     const char *options;
-     const struct option *long_options;
-     int *opt_index;
+getopt_long_only(int argc,
+		 char * const *argv,
+		 const char *options,
+		 const struct option *long_options,
+		 int *opt_index)
 {
-  return _getopt_internal (argc, argv, options, long_options, opt_index, 1);
+	return _getopt_internal(argc, argv, options, long_options, opt_index, 1);
 }
 
 
@@ -100,91 +98,87 @@ getopt_long_only (argc, argv, options, l
 #include <stdio.h>
 
 int
-main (argc, argv)
-     int argc;
-     char **argv;
+main(int argc, char **argv)
 {
-  int c;
-  int digit_optind = 0;
+	int c;
+	int digit_optind = 0;
 
-  while (1)
-    {
-      int this_option_optind = optind ? optind : 1;
-      int option_index = 0;
-      static struct option long_options[] =
-      {
-	{"add", 1, 0, 0},
-	{"append", 0, 0, 0},
-	{"delete", 1, 0, 0},
-	{"verbose", 0, 0, 0},
-	{"create", 0, 0, 0},
-	{"file", 1, 0, 0},
-	{0, 0, 0, 0}
-      };
-
-      c = getopt_long (argc, argv, "abc:d:0123456789",
-		       long_options, &option_index);
-      if (c == -1)
-	break;
-
-      switch (c)
-	{
-	case 0:
-	  printf ("option %s", long_options[option_index].name);
-	  if (optarg)
-	    printf (" with arg %s", optarg);
-	  printf ("\n");
-	  break;
-
-	case '0':
-	case '1':
-	case '2':
-	case '3':
-	case '4':
-	case '5':
-	case '6':
-	case '7':
-	case '8':
-	case '9':
-	  if (digit_optind != 0 && digit_optind != this_option_optind)
-	    printf ("digits occur in two different argv-elements.\n");
-	  digit_optind = this_option_optind;
-	  printf ("option %c\n", c);
-	  break;
-
-	case 'a':
-	  printf ("option a\n");
-	  break;
-
-	case 'b':
-	  printf ("option b\n");
-	  break;
-
-	case 'c':
-	  printf ("option c with value `%s'\n", optarg);
-	  break;
-
-	case 'd':
-	  printf ("option d with value `%s'\n", optarg);
-	  break;
+	while (1) {
+		int this_option_optind = optind ? optind : 1;
+		int option_index = 0;
+		static struct option long_options[] = {
+			{"add", 1, 0, 0},
+			{"append", 0, 0, 0},
+			{"delete", 1, 0, 0},
+			{"verbose", 0, 0, 0},
+			{"create", 0, 0, 0},
+			{"file", 1, 0, 0},
+			{0, 0, 0, 0}
+		};
+
+		c = getopt_long(argc, argv, "abc:d:0123456789",
+				long_options, &option_index);
+
+		if (c == -1)
+			break;
+
+		switch (c) {
+		case 0:
+			printf ("option %s", long_options[option_index].name);
+			if (optarg)
+				printf (" with arg %s", optarg);
+
+			printf ("\n");
+			break;
+		case '0':
+		case '1':
+		case '2':
+		case '3':
+		case '4':
+		case '5':
+		case '6':
+		case '7':
+		case '8':
+		case '9':
+			if (digit_optind != 0 && digit_optind != this_option_optind)
+				printf ("digits occur in two different argv-elements.\n");
+			digit_optind = this_option_optind;
+			printf ("option %c\n", c);
+			break;
+
+		case 'a':
+			printf ("option a\n");
+			break;
+
+		case 'b':
+			printf ("option b\n");
+			break;
+
+		case 'c':
+			printf ("option c with value `%s'\n", optarg);
+			break;
+
+		case 'd':
+			printf ("option d with value `%s'\n", optarg);
+			break;
+
+		case '?':
+			break;
+
+		default:
+			printf ("?? getopt returned character code 0%o ??\n", c);
+		}
+	}
 
-	case '?':
-	  break;
+	if (optind < argc) {
+		printf ("non-option ARGV-elements: ");
 
-	default:
-	  printf ("?? getopt returned character code 0%o ??\n", c);
+		while (optind < argc)
+			printf ("%s ", argv[optind++]);
+		printf ("\n");
 	}
-    }
-
-  if (optind < argc)
-    {
-      printf ("non-option ARGV-elements: ");
-      while (optind < argc)
-	printf ("%s ", argv[optind++]);
-      printf ("\n");
-    }
 
-  exit (0);
+	exit(0);
 }
 
 #endif /* TEST */
