--- main.cc.orig	Sat May 31 17:21:37 1997
+++ main.cc	Tue Nov 19 12:31:55 2002
@@ -28,9 +28,10 @@
 
 */
 
-#include <iostream.h>
+#include <iostream>
 #include <sysexits.h>
 #include <unistd.h>
+#define HAVE_DECL_GETOPT 0
 #include <getopt.h>
 
 #include "hexfile.h"
@@ -105,7 +106,7 @@
     }
 
   if (!opt_quiet || opt_warranty || opt_copying || opt_usage)
-    cerr << "Picprog version 1.0, Copyright © 1997 Jaakko Hyvätti\n"
+    std::cerr << "Picprog version 1.0, Copyright © 1997 Jaakko Hyvätti\n"
       "Picprog comes with ABSOLUTELY NO WARRANTY; for details\n"
       "type `" << prog.name << " --warranty'.  This is free software,\n"
       "and you are welcome to redistribute it under certain conditions;\n"
@@ -118,7 +119,7 @@
     prog.warranty ();
 
   if (opt_usage) {
-    cerr << "Full documentation is at "
+    std::cerr << "Full documentation is at "
       "<URL:http://www.iki.fi/hyvatti/pic/picprog.html>.\n"
       "The author may be contacted at:\n\n"
 
@@ -133,7 +134,7 @@
     return EX_OK;
 
   if (!opt_input && !opt_output) {
-    cerr << "Please specify either input or output hexfile.\n";
+    std::cerr << "Please specify either input or output hexfile.\n";
     prog.usage (long_opts, short_opts);
   }
 
@@ -150,7 +151,7 @@
       if (EX_OK != (retval = mem.program (opt_port, opt_erase)))
 	return retval;
     } else
-      cout << "No --burn option specified, device not programmed\n";
+      std::cout << "No --burn option specified, device not programmed\n";
 
     if (opt_cc)
       if (EX_OK != (retval = mem.save (opt_cc, hexfile::formats (opt_format),
