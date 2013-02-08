--- kernel/unix.c.orig
+++ kernel/unix.c
@@ -267,7 +267,7 @@
     /* The scorefile is only writable by the owner of the Xconq
        executable, but we normally run as the user, so switch over
        before writing. */
-    setuid(games_uid);
+    setgid(games_uid);
     fp = open_file(score_file_pathname(name), "a");
     return fp;
 }
@@ -277,7 +277,7 @@
 {
     fclose(fp);
     /* Reset the uid back to the user who started the game. */
-    setuid(getuid());
+    setgid(getgid());
 }
 
 /* Given the name of a scorefile, return a complete path to it,
