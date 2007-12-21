--- boxes.c.orig	2007-11-24 19:46:36.000000000 -0500
+++ boxes.c	2007-11-24 19:42:17.000000000 -0500
@@ -749,8 +749,13 @@
   guint ikey, istate;
   gchar msg[43], email_file_names[5][13], lpr_line[81];
   gint margin=9;
+#ifdef BSD
+  const gchar *lpr_cmd =
+         "lpr ";
+#else
   const gchar *lpr_cmd =
          "lpr -r -o page-top=36 -o page-left=18 -o page-bottom=36 ";
+#endif
   const gchar *print_file_names[4] = {"PRINT.SUM", "PRINT.DUP",
                                       "PRINT.LOG", "PRINT.MLT"};
   
@@ -778,14 +783,14 @@
         if(icall_count)
          {
           write_summary_file (print_file_names[obd->item], margin);
-          strcpy(lpr_line, lpr_cmd);
-          strcat(lpr_line, print_file_names[obd->item]);
+          snprintf(lpr_line, sizeof(lpr_line), "%s %s", lpr_cmd,
+		   print_file_names[obd->item]);
           icopy = system(lpr_line);
           if(isel_contest==WPX)
            {
             write_multiplier_file (print_file_names[3], margin);
-            strcpy(lpr_line, lpr_cmd);
-            strcat(lpr_line, print_file_names[3]);
+            snprintf(lpr_line, sizeof(lpr_line), "%s %s", lpr_cmd,
+		     print_file_names[3]);
             icopy = system(lpr_line);
            }
           if(!icopy)
