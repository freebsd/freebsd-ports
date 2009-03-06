--- plugin/klash/klash_part.cpp.orig	2009-03-02 18:29:45.000000000 +0300
+++ plugin/klash/klash_part.cpp	2009-03-06 05:27:45.000000000 +0300
@@ -160,7 +160,7 @@
     QString procname;
     char *gnash_env = getenv("KLASH_PLAYER");
     if (!gnash_env) {
-      procname = GNASHBINDIR "/kde-gnash";
+      procname = GNASHBINDIR "/kde3-gnash";
     } else {
       procname = gnash_env;
     }
