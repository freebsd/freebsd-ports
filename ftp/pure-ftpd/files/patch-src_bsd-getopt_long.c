--- src/bsd-getopt_long.c.orig  Sun Jun 20 19:29:34 2004
+++ src/bsd-getopt_long.c       Tue Jun 22 15:21:09 2004
@@ -472,6 +472,8 @@
                      *nargv[pure_optind + 1] != '-') {
                      pure_optarg = nargv[++pure_optind];
                  }
+            } else {
+                    pure_optarg = nargv[pure_optind];       
             }
         }
         pure_place = EMSG;
