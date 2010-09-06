--- src/main.c	2010-06-20 10:10:35 +0000
+++ src/main.c	2010-07-28 19:22:22 +0000
@@ -266,6 +266,7 @@
     { "timeout", 'T', OPT_VALUE, "timeout", -1 },
     { "timestamping", 'N', OPT_BOOLEAN, "timestamping", -1 },
     { "tries", 't', OPT_VALUE, "tries", -1 },
+    { "trust-server-names", 0, OPT_BOOLEAN, "trustservernames", -1 },
     { "user", 0, OPT_VALUE, "user", -1 },
     { "user-agent", 'U', OPT_VALUE, "useragent", -1 },
     { "verbose", 'v', OPT_BOOLEAN, "verbose", -1 },
@@ -680,6 +681,8 @@
     N_("\
   -I,  --include-directories=LIST  list of allowed directories.\n"),
     N_("\
+  --trust-server-names  use the name specified by the redirection url last component.\n"),
+    N_("\
   -X,  --exclude-directories=LIST  list of excluded directories.\n"),
     N_("\
   -np, --no-parent                 don't ascend to the parent directory.\n"),

=== modified file 'src/options.h'
