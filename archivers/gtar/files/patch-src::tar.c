
$FreeBSD$

--- src/tar.c	2002/06/01 21:08:46	1.1
+++ src/tar.c	2002/06/01 21:09:16
@@ -184,7 +184,9 @@
   {"block-number", no_argument, 0, 'R'},
   {"block-size", required_argument, 0, OBSOLETE_BLOCKING_FACTOR},
   {"blocking-factor", required_argument, 0, 'b'},
+  {"bzip", no_argument, 0, 'j'},
   {"bzip2", no_argument, 0, 'j'},
+  {"bunzip2", no_argument, 0, 'j'},
   {"catenate", no_argument, 0, 'A'},
   {"checkpoint", no_argument, &checkpoint_option, 1},
   {"compare", no_argument, 0, 'd'},
@@ -200,6 +202,7 @@
   {"exclude", required_argument, 0, EXCLUDE_OPTION},
   {"exclude-from", required_argument, 0, 'X'},
   {"extract", no_argument, 0, 'x'},
+  {"fast-read", no_argument, &fast_read_option, 1},
   {"file", required_argument, 0, 'f'},
   {"files-from", required_argument, 0, 'T'},
   {"force-local", no_argument, &force_local_option, 1},
@@ -230,6 +233,7 @@
   {"no-ignore-case", no_argument, 0, NO_IGNORE_CASE_OPTION},
   {"no-wildcards", no_argument, 0, NO_WILDCARDS_OPTION},
   {"no-wildcards-match-slash", no_argument, 0, NO_WILDCARDS_MATCH_SLASH_OPTION},
+  {"norecurse", no_argument, &recursion_option, 0},
   {"no-recursion", no_argument, &recursion_option, 0},
   {"no-same-owner", no_argument, &same_owner_option, -1},
   {"no-same-permissions", no_argument, &same_permissions_option, -1},
@@ -266,6 +270,7 @@
   {"touch", no_argument, 0, 'm'},
   {"uncompress", no_argument, 0, 'Z'},
   {"ungzip", no_argument, 0, 'z'},
+  {"unlink", no_argument, 0, 'U'},
   {"unlink-first", no_argument, 0, 'U'},
   {"update", no_argument, 0, 'u'},
   {"use-compress-program", required_argument, 0, USE_COMPRESS_PROGRAM_OPTION},
@@ -326,15 +331,17 @@
   -k, --keep-old-files       don't replace existing files when extracting\n\
       --overwrite            overwrite existing files when extracting\n\
       --overwrite-dir        overwrite directory metadata when extracting\n\
-  -U, --unlink-first         remove each file prior to extracting over it\n\
+  -U, --unlink,\n\
+      --unlink-first         remove each file prior to extracting over it\n\
       --recursive-unlink     empty hierarchies prior to extracting directory\n\
   -S, --sparse               handle sparse files efficiently\n\
   -O, --to-stdout            extract files to standard output\n\
   -G, --incremental          handle old GNU-format incremental backup\n\
   -g, --listed-incremental=FILE\n\
                              handle new GNU-format incremental backup\n\
-      --ignore-failed-read   do not exit with nonzero on unreadable files\n"),
-	     stdout);
+      --ignore-failed-read   do not exit with nonzero on unreadable files\n\
+      --fast-read            stop after desired names in archive have been found\n"),
+	    stdout);
       fputs (_("\
 \n\
 Handling of file attributes:\n\
@@ -344,6 +351,8 @@
       --atime-preserve         don't change access times on dumped files\n\
   -m, --modification-time      don't extract file modified time\n\
       --same-owner             try extracting files with the same ownership\n\
+      --show-omitted-dirs      show omitted directories while processing the\n\
+                               archive\n\
       --no-same-owner          extract files as yourself\n\
       --numeric-owner          always use numbers for user/group names\n\
   -p, --same-permissions       extract permissions information\n\
@@ -357,7 +366,7 @@
 \n\
 Device selection and switching:\n\
   -f, --file=ARCHIVE             use archive file or device ARCHIVE\n\
-      --force-local              archive file is local even if has a colon\n\
+      --force-local              archive file is local even if it has a colon\n\
       --rsh-command=COMMAND      use remote COMMAND instead of rsh\n\
   -[0-7][lmh]                    specify drive and density\n\
   -M, --multi-volume             create/list/extract multi-volume archive\n\
@@ -381,7 +390,7 @@
               PATTERN                at list/extract time, a globbing PATTERN\n\
   -o, --old-archive, --portability   write a V7 format archive\n\
       --posix                        write a POSIX format archive\n\
-  -j, --bzip2                        filter the archive through bzip2\n\
+  -j, -y, --bzip, --bzip2, --bunzip2 filter the archive through bzip2\n\
   -z, --gzip, --ungzip               filter the archive through gzip\n\
   -Z, --compress, --uncompress       filter the archive through compress\n\
       --use-compress-program=PROG    filter through PROG (must accept -d)\n"),
@@ -390,9 +399,9 @@
 \n\
 Local file selection:\n\
   -C, --directory=DIR          change to directory DIR\n\
-  -T, --files-from=NAME        get names to extract or create from file NAME\n\
+  -T, -I, --files-from=NAME    get names to extract or create from file NAME\n\
       --null                   -T reads null-terminated names, disable -C\n\
-      --exclude=PATTERN        exclude files, given as a PATTERN\n\
+      --exclude=PATTERN        exclude files, given as a a globbing PATTERN\n\
   -X, --exclude-from=FILE      exclude patterns listed in FILE\n\
       --anchored               exclude patterns match file name start (default)\n\
       --no-anchored            exclude patterns match after any /\n\
@@ -404,14 +413,17 @@
       --no-wildcards-match-slash exclude pattern wildcards do not match '/'\n\
   -P, --absolute-names         don't strip leading `/'s from file names\n\
   -h, --dereference            dump instead the files symlinks point to\n\
+  -n, --norecurse\n\
       --no-recursion           avoid descending automatically in directories\n\
   -l, --one-file-system        stay in local file system when creating archive\n\
   -K, --starting-file=NAME     begin at file NAME in the archive\n"),
 	     stdout);
 #if !MSDOS
       fputs (_("\
-  -N, --newer=DATE             only store files newer than DATE\n\
-      --newer-mtime=DATE       compare date and time when data changed only\n\
+  -N, --newer=DATE             only store files with creation time newer than\n\
+                               DATE\n\
+      --newer-mtime=DATE       only store files with modification time newer\n\
+                               than DATE\n\
       --after-date=DATE        same as -N\n"),
 	     stdout);
 #endif
@@ -425,7 +437,7 @@
       --help            print this help, then exit\n\
       --version         print tar program version number, then exit\n\
   -v, --verbose         verbosely list files processed\n\
-      --checkpoint      print directory names while reading the archive\n\
+      --checkpoint      print number of buffer reads/writes\n\
       --totals          print total bytes written while creating archive\n\
   -R, --block-number    show block number within archive with each message\n\
   -w, --interactive     ask for confirmation for every action\n\
@@ -467,7 +479,7 @@
    Y  per-block gzip compression */
 
 #define OPTION_STRING \
-  "-01234567ABC:F:GIK:L:MN:OPRST:UV:WX:Zb:cdf:g:hijklmoprstuvwxyz"
+  "-01234567ABC:F:GI:K:L:MnN:OPRST:UV:WX:Zb:cdf:g:hijklmoprstuvwxyz"
 
 static void
 set_subcommand_option (enum subcommand subcommand)
@@ -507,6 +519,7 @@
   excluded = new_exclude ();
   newer_mtime_option = TYPE_MINIMUM (time_t);
   recursion_option = FNM_LEADING_DIR;
+  namelist_freed = 0;
 
   owner_option = -1;
   group_option = -1;
@@ -691,13 +704,8 @@
 	ignore_zeros_option = 1;
 	break;
 
-      case 'I':
-	USAGE_ERROR ((0, 0,
-		      _("Warning: the -I option is not supported;"
-			" perhaps you meant -j or -T?")));
-	break;
-
       case 'j':
+      case 'y':
 	set_use_compress_program_option ("bzip2");
 	break;
 
@@ -744,6 +752,10 @@
 	multi_volume_option = 1;
 	break;
 
+      case 'n':
+	recursion_option = 0;
+	break;
+
 #if !MSDOS
       case 'N':
 	after_date_option = 1;
@@ -834,6 +846,7 @@
 	break;
 
       case 'T':
+      case 'I':
 	files_from_option = optarg;
 	break;
 
@@ -875,12 +888,6 @@
 	  }
 	break;
 
-      case 'y':
-	USAGE_ERROR ((0, 0,
-		      _("Warning: the -y option is not supported;"
-			" perhaps you meant -j?")));
-	break;
-
       case 'z':
 	set_use_compress_program_option ("gzip");
 	break;
@@ -1266,7 +1273,7 @@
 #endif
     start_time = time (0);
   program_name = argv[0];
-  setlocale (LC_ALL, "");
+  (void) setlocale (LC_ALL, "");
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
 
