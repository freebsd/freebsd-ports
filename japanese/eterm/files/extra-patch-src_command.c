--- src/command.c.orig	2011-03-16 07:05:03.000000000 +0100
+++ src/command.c	2011-05-19 11:15:36.000000000 +0200
@@ -1883,10 +1883,6 @@
         D_FONT(("Created fontset from %s, %d missing charsets (\"%s\").\n", fontname, mc,
                 ((mc > 0) ? (ml[0]) : ("N/A"))));
         FREE(fontname);
-        if (mc) {
-            XFreeStringList(ml);
-            /*fontset = 0;*/
-        }
     }
     return fontset;
 }
