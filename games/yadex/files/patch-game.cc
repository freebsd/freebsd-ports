--- src/game.cc.orig	Wed May 10 15:01:58 2000
+++ src/game.cc	Sun Jun 17 20:42:48 2001
@@ -42,10 +42,8 @@
    "./%b",
    "~/.yadex/%v/%b",
    "%i/%b",
-   "/usr/local/share/games/yadex/%v/%b",
-   "/usr/share/games/yadex/%v/%b",
-   "/usr/local/share/games/yadex/%b",
-   "/usr/share/games/yadex/%b",
+   PREFIX "/share/yadex/%v/%b",
+   PREFIX "/share/yadex/%b",
    0
    };
 
