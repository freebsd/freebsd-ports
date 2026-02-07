--- plugin/klash/klash_part.cpp.orig	2016-07-21 12:25:09 UTC
+++ plugin/klash/klash_part.cpp
@@ -160,7 +160,7 @@ KDE_NO_EXPORT void KlashPart::play ()
     QString procname;
     char *gnash_env = getenv("KLASH_PLAYER");
     if (!gnash_env) {
-      procname = GNASHBINDIR "/kde-gnash";
+      procname = GNASHBINDIR "/kde3-gnash";
     } else {
       procname = gnash_env;
     }
