--- main.cc.orig	Thu Apr 29 00:41:25 2004
+++ main.cc	Fri Jul  8 22:02:29 2005
@@ -31,6 +31,7 @@
 
 #include <sysexits.h>
 #include <unistd.h>
+#define HAVE_DECL_GETOPT 1
 #include <getopt.h>
 #include <string.h>
 
@@ -41,7 +42,7 @@
 
 program prog;
 
-char short_opts [] = "d:p:i:o:c:qh?";
+char short_opts [] = "d:p:i:o:c:qsh?";
 
 int
 main (int argc, char **argv)
@@ -52,7 +53,7 @@
   int opt_usage = 0;
 
   int opt_format = hexfile::unknown;
-  char *opt_port = (char *)"/dev/ttyS0";
+  char *opt_port = (char *)"/dev/cuaa0";
   char *opt_input = NULL;
   char *opt_output = NULL;
   char *opt_cc = NULL;
@@ -81,6 +82,7 @@
     {"erase", no_argument, &opt_erase, 1},
     {"burn", no_argument, &opt_burn, 1},
     {"force-calibration", no_argument, &opt_calibration, 1},
+    {"slow", no_argument, NULL, 's'},
     {0, 0, 0, 0}
   };
 
@@ -113,6 +115,12 @@
     case 'q':
       opt_quiet = 1;
       break;
+    case 's':
+	// Add extra delays for capacity added by very long cable
+	picport::t_edge = 10; // 10 us
+	picport::t_on = 200000;  // 200 ms
+	picport::t_off = 700000; // 700 ms - I'm not kidding !
+	break;
     default: // -? -h --help unknown flag
       opt_usage = 1;
     }
