--- src/daemon/main.c.orig	2009-01-12 18:11:38.000000000 -0500
+++ src/daemon/main.c	2009-03-07 19:56:16.000000000 -0500
@@ -689,7 +690,7 @@ int main(int argc, char *argv[]) {
          * first take the autospawn lock to make things
          * synchronous. */
 
-        if ((autospawn_fd = pa_autospawn_lock_init()) < 0) {
+        /*if ((autospawn_fd = pa_autospawn_lock_init()) < 0) {
             pa_log("Failed to initialize autospawn lock");
             goto finish;
         }
@@ -699,7 +700,7 @@ int main(int argc, char *argv[]) {
             goto finish;
         }
 
-        autospawn_locked = TRUE;
+        autospawn_locked = TRUE;*/
     }
 
     if (conf->daemonize) {
