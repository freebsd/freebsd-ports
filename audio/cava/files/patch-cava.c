--- cava.c.orig	2020-10-07 16:30:24 UTC
+++ cava.c
@@ -36,13 +36,11 @@
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
@@ -92,8 +90,6 @@ void cleanup(void) {
 #else
         ;
 #endif
-    } else if (output_mode == OUTPUT_NONCURSES) {
-        cleanup_terminal_noncurses();
     }
 }
 
@@ -291,8 +287,12 @@ as of 0.4.0 all options are specified in config file,
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
@@ -540,16 +540,6 @@ as of 0.4.0 all options are specified in config file,
                 height = lines * 8;
                 break;
 #endif
-            case OUTPUT_NONCURSES:
-                get_terminal_dim_noncurses(&width, &lines);
-
-                if (p.xaxis != NONE)
-                    lines--;
-
-                init_terminal_noncurses(inAtty, p.col, p.bgcol, width, lines, p.bar_width);
-                height = lines * 8;
-                break;
-
             case OUTPUT_RAW:
                 if (strcmp(p.raw_target, "/dev/stdout") != 0) {
                     // checking if file exists
@@ -785,11 +775,6 @@ as of 0.4.0 all options are specified in config file,
             if (p.xaxis != NONE) {
                 x_axis_info = 1;
                 double center_frequency;
-                if (output_mode == OUTPUT_NONCURSES) {
-                    printf("\r\033[%dB", lines + 1);
-                    if (rest)
-                        printf("\033[%dC", rest);
-                }
                 for (n = 0; n < number_of_bars; n++) {
                     if (p.stereo) {
                         if (n < number_of_bars / 2)
@@ -815,16 +800,6 @@ as of 0.4.0 all options are specified in config file,
                             mvprintw(lines, n * (p.bar_width + p.bar_spacing) + rest, "%.1f",
                                      freq_kilohz);
 #endif
-                    } else if (output_mode == OUTPUT_NONCURSES) {
-                        if (center_frequency < 1000)
-                            printf("%-4d", freq_floor);
-                        else if (center_frequency > 1000 && center_frequency < 10000)
-                            printf("%.2f", freq_kilohz);
-                        else
-                            printf("%.1f", freq_kilohz);
-
-                        if (n < number_of_bars - 1)
-                            printf("\033[%dC", p.bar_width + p.bar_spacing - 4);
                     }
                 }
                 printf("\r\033[%dA", lines + 1);
@@ -1124,11 +1099,6 @@ as of 0.4.0 all options are specified in config file,
                                                p.gradient, x_axis_info);
                     break;
 #endif
-                case OUTPUT_NONCURSES:
-                    rc = draw_terminal_noncurses(inAtty, lines, width, number_of_bars, p.bar_width,
-                                                 p.bar_spacing, rest, bars, previous_frame,
-                                                 x_axis_info);
-                    break;
                 case OUTPUT_RAW:
                     rc = print_raw_out(number_of_bars, fp, p.is_bin, p.bit_format, p.ascii_range,
                                        p.bar_delim, p.frame_delim, bars);
