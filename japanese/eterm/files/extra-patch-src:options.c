--- src/options.c.orig	Sun Jan 18 05:19:54 2004
+++ src/options.c	Sun Jan 18 05:25:51 2004
@@ -2648,8 +2648,6 @@
                 eterm_font_add(&etmfonts, rs_mfont[i], ((i == 0) ? def_font_idx : ((i <= def_font_idx) ? (i - 1) : i)));
                 RESET_AND_ASSIGN(rs_mfont[i], NULL);
             }
-        } else {
-            eterm_font_add(&etmfonts, etfonts[i], i);
         }
 #endif
     }
