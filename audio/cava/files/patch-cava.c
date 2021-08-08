--- cava.c.orig	2021-05-18 18:13:38 UTC
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
 
@@ -260,10 +256,10 @@ as of 0.4.0 all options are specified in config file, 
             if (inAtty) {
                 // checking if cava psf font is installed in FONTDIR
                 FILE *font_file;
-                font_file = fopen(FONTDIR "/cava.psf", "r");
+                font_file = fopen(FONTDIR "/cava.fnt", "r");
                 if (font_file) {
                     fclose(font_file);
-                    system("setfont " FONTDIR "/cava.psf  >/dev/null 2>&1");
+		     system("/usr/sbin/vidcontrol -f " FONTDIR "/cava.fnt > /dev/null 2>&1");
                 } else {
                     // if not it might still be available, we dont know, must try
                     system("setfont cava.psf  >/dev/null 2>&1");
@@ -532,16 +528,6 @@ as of 0.4.0 all options are specified in config file, 
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
                     int fptest;
@@ -787,11 +773,6 @@ as of 0.4.0 all options are specified in config file, 
             if (p.xaxis != NONE) {
                 x_axis_info = 1;
                 double center_frequency;
-                if (output_mode == OUTPUT_NONCURSES) {
-                    printf("\r\033[%dB", lines + 1);
-                    if (remainder)
-                        printf("\033[%dC", remainder);
-                }
                 for (int n = 0; n < number_of_bars; n++) {
                     if (p.stereo) {
                         if (n < number_of_bars / 2)
@@ -817,16 +798,6 @@ as of 0.4.0 all options are specified in config file, 
                             mvprintw(lines, n * (p.bar_width + p.bar_spacing) + remainder, "%.1f",
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
@@ -1142,11 +1113,6 @@ as of 0.4.0 all options are specified in config file, 
                                                p.gradient, x_axis_info);
                     break;
 #endif
-                case OUTPUT_NONCURSES:
-                    rc = draw_terminal_noncurses(inAtty, lines, width, number_of_bars, p.bar_width,
-                                                 p.bar_spacing, remainder, bars, previous_frame,
-                                                 x_axis_info);
-                    break;
                 case OUTPUT_RAW:
                     rc = print_raw_out(number_of_bars, fp, p.is_bin, p.bit_format, p.ascii_range,
                                        p.bar_delim, p.frame_delim, bars);
