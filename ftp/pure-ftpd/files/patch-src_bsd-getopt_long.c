--- src/bsd-getopt_long.c.orig	Mon Jun 21 01:29:56 2004
+++ src/bsd-getopt_long.c	Thu Jul 15 22:03:34 2004
@@ -462,16 +462,8 @@
                     fprintf(stderr, recargchar, optchar);
                 pure_optopt = optchar;
                 return BADARG;
-            } else if (!(flags & FLAG_PERMUTE)) {
-                /* 
-                 * If permutation is disabled, we can accept an
-                 * optional arg separated by whitespace so long
-                 * as it does not start with a dash (-).
-                 */
-                 if (pure_optind + 1 < nargc && pure_optind + 1 > 0 &&
-                     *nargv[pure_optind + 1] != '-') {
-                     pure_optarg = nargv[++pure_optind];
-                 }
+            } else {
+                pure_optarg = nargv[++pure_optind];
             }
         }
         pure_place = EMSG;
