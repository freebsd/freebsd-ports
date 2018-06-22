--- src-stormbaancoureur/main.cxx.orig	2008-04-20 15:58:29 UTC
+++ src-stormbaancoureur/main.cxx
@@ -837,12 +837,7 @@ int main(int argc, char *argv[]) 
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
