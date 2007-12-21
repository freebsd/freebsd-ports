--- support.c.orig	2007-07-18 14:21:10.000000000 -0400
+++ support.c	2007-12-20 18:48:00.000000000 -0500
@@ -1,3 +1,6 @@
+#ifdef BSDSOUND
+#include BSDSOUND
+#endif
 #include <termios.h>
 #include <libgnome/libgnome.h>
 #include <sys/utsname.h>
@@ -20,7 +23,6 @@
 static void concat(gchar *s1, const gchar *s2, gint is2, gint js2,
                    gint nullout_s1);
 static gint kb_index(const gchar *s1, const gchar *s2);
-static void add_eol_chars(gchar *line_out);
 static void left_zero_pad(gchar *s1, gint ss1);
 static void left_blank_pad(gchar *s1, gint ss1);
 static void left_blank_unpad(gchar *s1);
@@ -144,10 +146,22 @@
                    layout);
 }
 
+#ifdef BSDSOUND
+#include "bsd_bells.c"
+#endif
 static void play_bells(int isound)
 {
-  if(!strcmp(set_screen_choices[3], "<YES>"))
-   ioctl(fd_bells, _IO(KB_BELLS_IOCTL_BASE, isound));
+  if(fd_bells<0)
+    return;
+  if(strcmp(set_screen_choices[3], "<YES>") !=0)
+    return;
+#ifdef BSD
+#ifdef BSDSOUND
+  bsd_play_bells(isound);
+#endif
+#else
+  ioctl(fd_bells, _IO(KB_BELLS_IOCTL_BASE, isound));
+#endif
 }
 
 static void get_kb_time(void)
@@ -189,25 +203,8 @@
 
 static void fill_kb_dt(void)
 {
-  gchar *t1;
-
-  t1 = asctime(&kb_time);
-  kb_dt.date[0] = month_num[2*kb_time.tm_mon];
-  kb_dt.date[1] = month_num[2*kb_time.tm_mon+1];
-  kb_dt.date[2] = *(t1+8);
-  if(kb_dt.date[2]==' ')
-   kb_dt.date[2] = '0';
-  kb_dt.date[3] = *(t1+9);
-  kb_dt.date[4] = *(t1+22);
-  kb_dt.date[5] = *(t1+23);
-  kb_dt.date[6] = '\0';
-  kb_dt.time[0] = *(t1+11);
-  kb_dt.time[1] = *(t1+12);
-  kb_dt.time[2] = *(t1+14);
-  kb_dt.time[3] = *(t1+15);
-  kb_dt.time[4] = *(t1+17);
-  kb_dt.time[5] = *(t1+18);
-  kb_dt.time[6] = '\0';
+  strftime(kb_dt.date, sizeof(kb_dt.date), "%m%d%g", &kb_time);
+  strftime(kb_dt.time, sizeof(kb_dt.time), "%H%M%S", &kb_time);
 }
 
 static gint idelta_time(const gchar *day1, const gchar *day2,
@@ -284,15 +281,6 @@
   return -1;
 }
 
-static void add_eol_chars(gchar *line_out)
-{
-  gint lcil;
-
-  lcil = strlen(line_out);
-  line_out[lcil] = '\r';
-  line_out[lcil+1] = '\n';
-  line_out[lcil+2] = '\0';
-}
 
 static void left_zero_pad(gchar *s1, gint ss1)
 {
