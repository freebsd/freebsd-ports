--- config.h.orig	Thu Dec 21 14:30:15 2006
+++ config.h	Thu Dec 21 14:30:26 2006
@@ -71,7 +71,7 @@
 
  public:
   Config();
-  void Config::args(int argc, char *argv[]);
+  void args(int argc, char *argv[]);
   int parse();
   int     force, command, with, reverse, readonly, encrypted;
   string  filename, key, value, usage, token, phrase;
