--- src/idn2.c.orig	2016-12-26 21:00:11 UTC
+++ src/idn2.c
@@ -31,7 +31,7 @@
 #include <unistr.h>
 
 /* Gnulib headers. */
-#include "error.h"
+#include "err.h"
 #include "gettext.h"
 #define _(String) dgettext (PACKAGE, String)
 #include "progname.h"
@@ -167,7 +167,7 @@ process_input (char *readbuf, int flags)
       free (output);
     }
   else
-    error (EXIT_FAILURE, 0, "%s: %s",
+    errc (EXIT_FAILURE, 0, "%s: %s",
 	   args_info.register_given ? "register" : "lookup",
 	   idn2_strerror (rc));
 }
@@ -228,7 +228,7 @@ main (int argc, char *argv[])
     }
 
   if (ferror (stdin))
-    error (EXIT_FAILURE, errno, "%s", _("input error"));
+    errc (EXIT_FAILURE, errno, "%s", _("input error"));
 
   cmdline_parser_free (&args_info);
 
