--- ./src/xcowsay.c.orig	2010-12-22 22:33:28.806155135 -0800
+++ ./src/xcowsay.c	2010-12-22 22:34:03.718166298 -0800
@@ -252,7 +252,7 @@
    parse_config_file();
    
    int c, index = 0, failure = 0;
-   const char *spec = "hvld:rt:f:";
+   const char *spec = "hvld:r:t:f:";
    const char *dream_file = NULL;
    while ((c = getopt_long(argc, argv, spec, long_options, &index)) != -1) {
       switch (c) {
