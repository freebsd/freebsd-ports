--- src-sturmbahnfahrer/main.cxx.orig	Thu May 17 20:02:03 2007
+++ src-sturmbahnfahrer/main.cxx	Thu Aug  9 02:21:33 2007
@@ -656,12 +656,7 @@
   fprintf(stderr,"OpenDE is (c) by Russel L. Smith\n");
 
   char *bindirname  = dirname(argv[0]);
-  if (!strcmp(bindirname,"."))
     dirprefix="/usr/share/games/sturmbahnfahrer";
-  else
-  {
-    dirprefix = dirname(bindirname) + std::string("/share/games/sturmbahnfahrer");
-  }
   if (getenv("PLODE_DATADIR"))
     dirprefix = getenv("PLODE_DATADIR");
   if (getenv("PLODE_DISPLAYMODE"))
