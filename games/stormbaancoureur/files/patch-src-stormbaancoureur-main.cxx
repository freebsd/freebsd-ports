--- src-stormbaancoureur/main.cxx.orig	2007-12-28 23:09:41.000000000 +0300
+++ src-stormbaancoureur/main.cxx	2007-12-31 16:48:41.000000000 +0300
@@ -1176,12 +1176,7 @@
   fprintf(stderr,"OpenDE is (c) by Russel L. Smith\n");
 
   char *bindirname  = dirname(argv[0]);
-  if (!strcmp(bindirname,"."))
-    dirprefix="/usr/share/games/stormbaancoureur";
-  else
-  {
-    dirprefix = dirname(bindirname) + std::string("/share/games/stormbaancoureur");
-  }
+  dirprefix=__DATADIR;
   if (getenv("PLODE_DATADIR"))
     dirprefix = getenv("PLODE_DATADIR");
   if (getenv("PLODE_DISPLAYMODE"))
