--- src-crashtest/crashtest.cxx.orig	2009-02-15 22:08:24 UTC
+++ src-crashtest/crashtest.cxx
@@ -616,12 +616,7 @@ void seatbelt_cb(Fl_Widget *o)
 int main(int argc, char *argv[]) 
 {
   char *bindirname  = dirname(argv[0]);
-  if (!strcmp(bindirname,"."))
-    dirprefix="/usr/share/games/crashtest";
-  else
-  {
-    dirprefix = dirname(bindirname) + std::string("/share/games/crashtest");
-  }
+  dirprefix="%%DATADIR%%";
   if (getenv("PLODE_DATADIR"))
     dirprefix = getenv("PLODE_DATADIR");
   modelmap = new ModelMap(dirprefix);
