--- main.cxx.orig	Mon Sep  4 20:04:09 2006
+++ main.cxx	Wed Sep  6 05:03:34 2006
@@ -655,13 +655,7 @@
   fprintf(stderr,"plib is (c) by Steve Baker\n");
   fprintf(stderr,"OpenDE is (c) by Russel L. Smith\n");
 
-  char *bindirname  = dirname(argv[0]);
-  if (!strcmp(bindirname,"."))
     dirprefix="/usr/share/games/sturmbahnfahrer";
-  else
-  {
-    dirprefix = dirname(bindirname) + std::string("/share/games/sturmbahnfahrer");
-  }
   if (getenv("PLODE_DATADIR"))
     dirprefix = getenv("PLODE_DATADIR");
   if (getenv("PLODE_DISPLAYMODE"))
