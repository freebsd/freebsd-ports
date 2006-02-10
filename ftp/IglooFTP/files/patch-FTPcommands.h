--- FTPcommands.h.orig	Thu Apr 15 17:05:15 1999
+++ FTPcommands.h	Sat Feb  4 01:12:52 2006
@@ -14,8 +14,12 @@
  *
  */
 
+#include "defines.h"
+
 #define ERROR_REPLY_CODE (FTPctrl->reply[0] == '5' || FTPctrl->reply[0] == '4')
 
+extern char tmpfile_template[];
+
 
 
 /* LOGIN */
@@ -282,11 +286,14 @@
 char
 FTP_LIST (FTP * FTPctrl, char *filename)
 {
+  int fd = -1;
   char tmp_filename[256];
   char list_command[10];
   int data_socket = FTP_open_data_connection (FTPctrl);
   FILE *local;
 
+  sprintf(tmp_filename, tmpfile_template);
+
   if (FTPctrl->host_type == HOST_VMS)
     strcpy (list_command, "LIST");
   else
@@ -296,11 +303,18 @@
 
   FTP_TYPE_ASCII (FTPctrl);
 
-  tmpnam (tmp_filename);
   if (!FTP_exec_command (FTPctrl, list_command) || ERROR_REPLY_CODE)
     return FTP_error (FALSE, "LIST command failed.", "", data_socket);
 
-  local = fopen (tmp_filename, "w");
+  if ((fd = mkstemp (tmp_filename)) == -1 || (local = fdopen (fd, "w")) == NULL)
+  {
+    if (fd != -1) {
+      unlink(tmp_filename);
+      close(fd);
+    }
+    return FTP_error (FALSE, "Unable to create temporary file.", "", 0);
+  }
+
   if (!FTP_download (FTPctrl, data_socket, local))
     return FTP_error (FALSE, "Unable to retreive directory listing. ", "", data_socket);
 
--- custom_profiles.h.orig	Thu Apr 15 17:05:15 1999
+++ custom_profiles.h	Sat Feb  4 00:59:51 2006
@@ -169,6 +169,7 @@
 static void
 delete_user_prof_from_file (GtkWidget * widget, gpointer data)
 {
+  int fd = -1;
   const int remove_this_one = (int) GTK_CLIST (clist)->selection->data;
   char tmp_filename[256];
   char prof_path[1024];
@@ -180,9 +181,21 @@
 
   gtk_widget_destroy (gtk_widget_get_toplevel (widget));
   sprintf (prof_path, "%s/%s/%s", home_path, PREFERENCES_PATH, USER_PROF);
-  tmpnam (tmp_filename);
+  sprintf (tmp_filename, "%s.%s", prof_path, "tmp.XXXXXXXX");
+
+  if ((fd = mkstemp (tmp_filename)) == -1) {
+    DEBUG("Unable to create temporary file.");
+    return;
+  }
+
+  close (fd);
+
   rename (prof_path, tmp_filename);
-  file_handle = open (tmp_filename, O_RDONLY, RC_PERM);
+
+  if ((file_handle = open (tmp_filename, O_RDONLY|O_EXCL, RC_PERM)) == -1) {
+    DEBUG("Unable to create temporary file.");
+    return;
+  }
 
   for (index = 0; index < index_total; index++)
     {
--- defines.h.orig	Thu Apr 15 17:05:15 1999
+++ defines.h	Sat Feb  4 01:10:47 2006
@@ -47,6 +47,9 @@
 #define SHARE_PATH "/usr/local/src/IglooFTP"
 #endif
 
+#define TMPFILE_FILE "IglooFTP.tmp.XXXXXXXX"
+char tmpfile_template[256];
+
 
 #define PREFERENCES_PATH ".IglooFTP"
 #define USER_LAYOUT "user.layout"
--- dirlist.c.orig	Thu Apr 15 17:05:14 1999
+++ dirlist.c	Fri Feb  3 23:20:24 2006
@@ -1619,6 +1619,7 @@
 upload_selection_recursive (void)
 {
 
+  int fd = -1;
   GdkColor done_color = GREYCYAN;
   GdkColormap *colormap;
   GList *selection = GTK_CLIST (clist)->selection;
@@ -1635,8 +1636,15 @@
 
   getcwd (current_local_dir, sizeof (current_local_dir));
 
-  tmpnam (tmp_filename);
-  tmp = fopen (tmp_filename, "w");
+  if ((fd = mkstemp (tmp_filename)) == -1 || (tmp = fdopen (fd, "w")) == NULL)
+  {
+    if (fd != -1) {
+      unlink(tmp_filename);
+      close(fd);
+    }
+    DEBUG("Unable to create temporary file.");
+    return;
+  }
 
   colormap = gtk_widget_get_colormap (window);
   gdk_color_alloc (colormap, &done_color);
--- session.c.orig	Thu Apr 15 17:05:15 1999
+++ session.c	Fri Feb  3 23:20:24 2006
@@ -32,7 +32,8 @@
 {
   FILE *out = NULL;
   FTPsession that_session;
-  int file_handle;
+  int fd = -1;
+  FILE *file_handle = NULL;
   char tmp_filename[MPLEN];
   char spawn_tmp[MPLEN];
 
@@ -41,8 +42,16 @@
 
   strcpy (that_session.start_dir, this_session.cwd_dir);
 
-  tmpnam (tmp_filename);
-  file_handle = open (tmp_filename, O_CREAT | O_RDWR, RC_PERM);
+  if ((fd = mkstemp (tmp_filename)) == -1 || (file_handle = fdopen (fd, "w")) == NULL)
+  {
+    if (fd != -1) {
+      unlink(tmp_filename);
+      close(fd);
+    }
+    DEBUG("Unable to create temporary file.");
+    return;
+  }
+
   write (file_handle, &that_session, sizeof (FTPsession));
   close (file_handle);
 
