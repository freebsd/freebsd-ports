--- src/cfgfile.cc.orig	Sat Aug 26 13:21:12 2000
+++ src/cfgfile.cc	Sun Jun 17 20:33:08 2001
@@ -572,10 +572,8 @@
    "~/.yadex/%v/%b",
    "~/.yadex/%b",
    "%i/%b",
-   "/usr/local/etc/yadex/%v/%b",
-   "/usr/local/etc/yadex/%b",
-   "/etc/yadex/%v/%b",
-   "/etc/yadex/%b",
+   PREFIX "/etc/yadex/%v/%b",
+   PREFIX "/etc/yadex/%b",
    0
    };
 
