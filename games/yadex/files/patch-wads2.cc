--- src/wads2.cc.orig	Sun May  7 05:47:11 2000
+++ src/wads2.cc	Sun Jun 17 20:46:41 2001
@@ -910,10 +910,8 @@
    {
    "",
    "~/",                            // "~" means "the user's home directory"
-   "/usr/local/share/games/%s/",    // %s is replaced by <Game>
-   "/usr/share/games/%s/",          // %s is replaced by <Game>
-   "/usr/local/share/games/wads/",
-   "/usr/share/games/wads/",
+   "~/doom/",			    // several doom variants put wads here
+   PREFIX "/share/%s/",             // %s is replaced by <Game>
    0
    };
 
