--- xlifegame.h.orig	Sat Oct 19 16:21:33 2002
+++ xlifegame.h	Sat Oct 19 16:21:52 2002
@@ -46,7 +46,7 @@
 OptionError(char *option)
 {
     printf("   X Life Game version %s \n     by Takeshi Hiyama\n",XLIFEGAME_VERSION);
-    if(strncmp(option, "-h"))
+    if(strncmp(option, "-h", 3))
         printf("\nxlife:  bad command line option \"%s\"\n", option);
     printf("usage: xlife [-display <displayname>] [-wait microseconds (default 10000)]\n             [-x width (default 60)] [-y height (default 60)] [-h]\n");
     exit(1);
