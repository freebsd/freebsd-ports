--- common/loader.c.orig	2012-04-20 00:41:50 UTC
+++ common/loader.c
@@ -225,6 +225,7 @@ int main
    /*
     * Get any program options.
     */
+   optind = 1;  /* Previously clobbered by regina */
    while ((c = getopt(argc, argv, "Dudivh?f:")) != EOF)
    {
       switch (c)
