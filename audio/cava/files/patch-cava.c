--- cava.c.orig	2020-06-24 19:18:09 UTC
+++ cava.c
@@ -31,13 +31,11 @@
 #include "util.h"
 
 #ifdef NCURSES
-#include "output/terminal_bcircle.h"
 #include "output/terminal_ncurses.h"
 #include <curses.h>
 #endif
 
 #include "output/raw.h"
-#include "output/terminal_noncurses.h"
 
 #include "input/alsa.h"
 #include "input/common.h"
@@ -90,8 +88,6 @@ void cleanup(void) {
 #else
         ;
 #endif
-    } else if (output_mode == OUTPUT_NONCURSES) {
-        cleanup_terminal_noncurses();
     }
 }
 
@@ -337,8 +333,12 @@ as of 0.4.0 all options are specified in config file, 
             if (strncmp(ttyname(0), "/dev/ttys", 9) == 0)
                 inAtty = 0;
             if (inAtty) {
+#ifdef __FreeBSD__
+                system("/usr/sbin/vidcontrol -f " FONT_DIR "/cava.fnt >/dev/null 2>&1");
+#else
                 system("setfont cava.psf  >/dev/null 2>&1");
                 system("setterm -blank 0");
+#endif
             }
 
             // We use unicode block characters to draw the bars and
@@ -546,12 +546,6 @@ as of 0.4.0 all options are specified in config file, 
                 height = lines * 8;
                 break;
 #endif
-            case OUTPUT_NONCURSES:
-                get_terminal_dim_noncurses(&width, &lines);
-                init_terminal_noncurses(inAtty, p.col, p.bgcol, width, lines, p.bar_width);
-                height = (lines - 1) * 8;
-                break;
-
             case OUTPUT_RAW:
                 if (strcmp(p.raw_target, "/dev/stdout") != 0) {
                     // checking if file exists
@@ -997,10 +991,6 @@ as of 0.4.0 all options are specified in config file, 
                                                p.gradient);
                     break;
 #endif
-                case OUTPUT_NONCURSES:
-                    rc = draw_terminal_noncurses(inAtty, lines, width, number_of_bars, p.bar_width,
-                                                 p.bar_spacing, rest, bars, previous_frame);
-                    break;
                 case OUTPUT_RAW:
                     rc = print_raw_out(number_of_bars, fp, p.is_bin, p.bit_format, p.ascii_range,
                                        p.bar_delim, p.frame_delim, bars);
