--- tpmd/unix/tpmd.c.orig	2011-12-20 18:30:06 UTC
+++ tpmd/unix/tpmd.c
@@ -85,7 +85,7 @@ static void print_usage(char *name)
 
 static void parse_options(int argc, char **argv)
 {
-    char c;
+    int c;
     struct passwd *pwd;
     struct group *grp;
     opt_uid = getuid();
