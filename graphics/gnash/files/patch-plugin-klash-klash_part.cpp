--- plugin/klash/klash_part.cpp.orig	2011-06-16 18:54:16.833252653 -0400
+++ plugin/klash/klash_part.cpp	2011-06-16 18:54:56.913835639 -0400
@@ -161,7 +161,7 @@
     QString procname;
     char *gnash_env = getenv("KLASH_PLAYER");
     if (!gnash_env) {
-      procname = GNASHBINDIR "/kde-gnash";
+      procname = GNASHBINDIR "/kde3-gnash";
     } else {
       procname = gnash_env;
     }
