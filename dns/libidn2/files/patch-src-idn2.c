--- src/idn2.c.orig	2017-04-12 18:43:32 UTC
+++ src/idn2.c
@@ -33,7 +33,7 @@
 #include <unistring/localcharset.h>
 
 /* Gnulib headers. */
-#include "error.h"
+#include "err.h"
 #include "gettext.h"
 #define _(String) dgettext (PACKAGE, String)
 #include "progname.h"
@@ -176,7 +176,7 @@ process_input (char *readbuf, int flags)
       free (output);
     }
   else
-    error (EXIT_FAILURE, 0, "%s: %s", tag, idn2_strerror (rc));
+    errc (EXIT_FAILURE, 0, "%s: %s", tag, idn2_strerror (rc));
 }
 
 int
@@ -237,7 +237,7 @@ main (int argc, char *argv[])
     }
 
   if (ferror (stdin))
-    error (EXIT_FAILURE, errno, "%s", _("input error"));
+    errc (EXIT_FAILURE, errno, "%s", _("input error"));
 
   cmdline_parser_free (&args_info);
 
