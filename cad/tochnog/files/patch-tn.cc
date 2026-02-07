--- tn.cc.orig	2013-08-16 01:47:35.000000000 +0200
+++ tn.cc	2014-03-09 17:57:23.000000000 +0100
@@ -33,6 +33,40 @@
   int PetscFinalize(void);
 #endif
 
+#include "getopt.h"
+
+bool enable_gid;
+bool enable_test;
+
+struct option long_options [] =
+{
+  {"version", no_argument, NULL, 'v'},
+  {"help", no_argument, NULL, 'h'},
+  {"gid", no_argument, NULL, 'G'},
+  {"test", no_argument, NULL, 't'}, // Not yet implemented
+  {NULL, 0, 0, 0}
+};
+
+int usage ()
+{
+  cout << "Usage: tochnog [options]\n"
+    "or:    tochnog [options] file.dat\n"
+    "or:    tochnog [options] file.dat > file.out\n\n"
+    "options: --version  print the version of the tochnog program\n"
+    "         --help     print a short options overview and exit\n"
+    "         --gid      generate the files necessary for GID interaction\n"
+    "         --test     notify if target_item/_value could be meet\n"
+    "                    (not very usefull now)\n";
+  return 1;
+}
+
+int version ()
+{
+  cout << TOCHNOG_VERSION << '\n';
+  return 1;
+}
+
+
 int main( int argc, char* argv[] )
 
 {
@@ -40,37 +74,107 @@
   Time CPU;
   CPU.firsttime=CPU.taketime();
 
-  long int i=0, l=0, any_point=0;
+  extern char *optarg;
+  extern int optind, opterr, optopt;
+
+  int opt_index, option, error_count = 0;
+  bool print_usage = false, print_version = false;
+
+  size_t i=0, l=0, s_len=0, any_point=0;
 
     // initialise static variables
   initialize();
 
     // test arguments
+  while ((option = getopt_long (argc, argv, "hvGt", long_options, &opt_index))
+	 != EOF)
+    {
+      switch (option)
+	{
+	  // Options without argument
+
+	case 'h':	  // print a short help message and exit
+	  print_usage = true;
+	  break;
+	case 'v':         // print the version string and exit
+	  print_version = true;
+	  break;
+	case 'G':         // use the *flavia* for interaction with gid
+	  enable_gid = true;
+	  break;
+	case 't':         // use the *flavia* for interaction with gid
+	  enable_test = true;
+	  break;
+	  // Options with 1 argument
+	default:
+	  cerr << "tochnog: unrecognized option " << optarg << '\n';
+	  error_count++;
+	}
+    }
+
+  if (error_count > 0)
+    {
+      cerr << "Try tochnog --help for more information";
+      exit(TN_EXIT_STATUS);
+    }
+
+  if (print_usage)
+    {
+      usage();
+    }
+  if (print_version || print_usage)
+    {
+      version();
+      exit(TN_EXIT_STATUS);
+    }
+
+  // No comand argument
+
+  if (argc == optind)
+    {
+      strncpy( data_file, "tn.dat", 6 );
+    }
+
+  // 1 command line argument, should be input file name
+
+  else if (argc == optind + 1)
+    {
+      s_len = strlen (argv[optind]);
+      strncpy(data_file, argv[optind], s_len);
+
+      // Check if input file name containes already ".dat" suffix
+
+      if (strncmp(&data_file[s_len - 4], ".dat", 4) != 0)
+	{
+
+	  // to preserve compatibility
+
+	  if (strncmp(&data_file[s_len - 4], ".dbs", 4) != 0)
+	    {
+	      strncpy(data_file_base, data_file, s_len);
+	      strncpy(&data_file[s_len], ".dat", 4);
+	    }
+	  else
+	    {
+	      strncpy(data_file_base, data_file, s_len - 4);
+	    }
+	}
+      else
+	{
+	  // to preserve compatibility
+
+	  strncpy(data_file_base, data_file, s_len - 4);
+	}
+    }
+  else
+    {
+      usage();
+      exit(TN_EXIT_STATUS);
+    }
+
 #if MPI_USE
   strcpy( data_file, "tn.dat" );
-#else
-  if ( argc==1 ) strcpy( data_file, "tn.dat" );
-  else if ( argc==2 ) strcpy( data_file, argv[1] );
-  else {
-    pri( "Usage: tochnog" );
-    pri( "or:    tochnog file.dat" );
-    pri( "or:    tochnog file.dat > file.out" );
-    exit(TN_EXIT_STATUS);
-  }
-#endif
-
-    // append .dat to input file name
-  l = strlen( data_file );
-  strcpy( data_file_base, "" );
-  for ( i=0; i<l && !any_point; i++ ) {
-    if ( data_file[i]=='.' ) any_point = 1;
-    else strncat( data_file_base, &data_file[i], 1 );
-  }
-  if ( !any_point ) strcat( data_file, ".dat" );
-
-    // empty the tn.dvd file at the start of calculation
-  ofstream outdvd( "tn.dvd" );
-  outdvd.close();
+#endif
 
     // read input file
   input();
