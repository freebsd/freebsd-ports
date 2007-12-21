--- init.c.orig	2007-09-10 10:34:21.000000000 -0400
+++ init.c	2007-11-24 16:43:45.000000000 -0500
@@ -30,6 +30,7 @@
 static gint set_error_check(gpointer data);
 static gint check_precedence(void);
 static gint butt_kick(gpointer widget);
+static void set_fixed_font(GtkWidget *);
 struct init_vars
 {
   gint row1;
@@ -108,33 +109,13 @@
                    (col1+9)*wcol,
                    (row1+9)*hrow+hrow/2,
                    layout);
-  pfd = pango_font_description_from_string ("misc fixed 16");
-  pc = gtk_widget_get_pango_context (widget);
-  pl = pango_context_get_language (pc);
-  pfm = pango_context_get_metrics (pc, pfd, pl);
-  ipfmgadw = pango_font_metrics_get_approximate_digit_width (pfm);
-  cursor_offset = 8-pango_font_metrics_get_descent (pfm)/PANGO_SCALE;
-  pango_font_metrics_unref (pfm);
-  if(ipfmgadw==10240)
-   {
-    pango_layout_set_font_description (layout, pfd);
-    pango_font_description_free (pfd);
-   }
-  else
-   {
-    pango_font_description_free (pfd);
-    pfd = pango_font_description_from_string ("luxi mono 12");
-    pango_layout_set_font_description (layout, pfd);
-    pango_font_description_free (pfd);
-    printf("%s\n", missing_font);
-    printf("For a more readable KB screen ");
-    printf("add the Misc Fixed font to your system.\n");
-    printf("%s\n", missing_font);
-    write_line (row1+23, col1+20, missing_font, HI_RED, SAVEPIX);
-    write_line (row1+24, col1+6,
-     "Now Using Alternate Font.  KB Screens May Exhibit Display Problems.",
-                HI_RED, SAVEPIX);
-   }
+  /* Original code would only work on a 1024 wide screen.
+   * This works for other sized screens, including mine which is 1280 wide.
+   * 
+   * - Diane VA3DB db@db.net
+   */
+  set_fixed_font(widget);
+
   concat(comp_mon, __DATE__, 0, 2, COPY);
   concat(comp_yr, __DATE__, 7, 10, COPY);
   while(strcmp(comp_mon, month_array[icm]) && icm<11)
@@ -404,6 +385,7 @@
    mode = CW;
   else
    mode = PH;
+  shift_fkeys = 0;
   if(!sccfn && strcmp(init_screen_choices[16], port_bracket[0]))
    {
     idisplay_type = IDT_KEYER;
@@ -1139,8 +1121,13 @@
          beep = 0;
         break;
        case 7 :
-        if(isdigit_ui(ikey) || ikey=='-')
-         beep = 0;
+	 /* Canadian postal codes will be ANA[space]NAN
+	  * I will cheat and allow any combination of alpha, numeric and space.
+	  * - Diane VA3DB <db@db.net>
+	  */
+	 ikey = toupper_ui(ikey);
+	 if(isalpha_ui(ikey) || isdigit_ui(ikey) || ikey==' ' || ikey=='-')
+	   beep = 0;
         break;
        case 8 :
         ikey = toupper_ui(ikey);
@@ -1163,7 +1150,7 @@
        edit_line (&esd);
       }
      else
-      play_bells (BAD_KEY_SOUND);
+       play_bells (BAD_KEY_SOUND);
    }
   return TRUE;
 }
@@ -1791,6 +1778,7 @@
       }
      write_ini_file ();
      insert_mode = 0;
+     shift_fkeys = 0;
      shift_fkeys = (strcmp(set_screen_choices[11], yn_bracket[1]));
      ssd->done = TRUE;
      break;
@@ -2381,3 +2369,57 @@
                               update_rect.height);
   return TRUE;
 }
+
+/*
+ * set_fixed_font
+ *
+ * Author	- Diane Bruce <db@db.net> VA3DB
+ * Inputs	- None
+ * Output	- None
+ * Side effects	- Try to find a font that fits the screen
+ *		  giving 80 columns across
+ *		  KB relies upon the width of a monospace font being equal
+ *		  in width to one of 80 (NUMBER_OF_COLUMNS) columns.
+ * Bugs		- I am sure there must be better ways of doing this.
+ *		  There is probably a mapping function between 
+ *		  font size and pixel width. I'll look for that next.
+ */
+#define SBUFSIZE 64
+static void
+set_fixed_font(GtkWidget *widget)
+{
+  int width_col;
+  char font_desc[SBUFSIZE];
+  int width_font;
+  int font_size;
+  gint ipfmgadw;
+  PangoFontDescription *pfd;
+  PangoContext *pc;
+  PangoLanguage *pl;
+  PangoFontMetrics *pfm;
+
+  width_col = widget->allocation.width/NUMBER_OF_COLUMNS;
+
+  pc = gtk_widget_get_pango_context (widget);
+  pl = pango_context_get_language (pc);
+
+  for (font_size = 10; font_size < 24; font_size++) 
+    {
+      snprintf(font_desc, sizeof(font_desc)-1, "monospace %d", font_size);
+
+      pfd = pango_font_description_from_string (font_desc);
+      pfm = pango_context_get_metrics (pc, pfd, pl);
+      ipfmgadw = pango_font_metrics_get_approximate_digit_width (pfm);
+      if (ipfmgadw/PANGO_SCALE == width_col)
+	{
+	  printf("Found a good font [%s]\n", font_desc);
+	  pango_font_metrics_unref (pfm);
+	  break;
+	}
+      pango_font_metrics_unref (pfm);
+    }
+
+  cursor_offset = 8-pango_font_metrics_get_descent (pfm)/PANGO_SCALE;
+  pango_layout_set_font_description (layout, pfd);
+  pango_font_description_free (pfd);
+}
