--- gkrellkam.c.orig	Thu Nov 29 02:04:48 2001
+++ gkrellkam.c	Thu Nov 29 02:04:24 2001
@@ -131,8 +131,7 @@
 "local picture file, list of files, or a script, enter the\n",
 "_full_ filename in the \"Image Source\" box. To watch a webcam\n",
 "or other online picture, just put its address (beginning with\n",
-"http:// or ftp://) in the \"Image Source\" box. You'll need\n",
-"GNU wget installed to be able to get pictures from the internet.\n",
+"http:// or ftp://) in the \"Image Source\" box.\n",
 "Special case: when this field begins with \"-x\" followed by a\n",
 "space and some more text, the remaining text is assumed to be a\n",
 "script or other system commmand, and the whole path does not\n",
@@ -172,7 +171,6 @@
 
 static const char *default_viewer = "eeyes";
 
-#define wget_opts "--proxy=off --cache=off"
 #define BUFLEN 256
 #define MIN_NUMPANELS 0
 #define MAX_NUMPANELS 5
@@ -448,11 +446,11 @@
 /*
   start_img_dl ()
 
-  Open a pipe and spawn wget.
+  Open a pipe and spawn fetch.
 */
 static void start_img_dl (KKamPanel *p)
 {
-  gchar *wget_str;
+  gchar *fetch_str;
   char tmpfile[] = TEMPTEMPLATE "XXXXXX";
   int tmpfd;
 
@@ -473,20 +471,19 @@
   p->delete_when_done = TRUE;
   p->from_script = FALSE;
 
-  wget_str = g_strdup_printf ("wget -q %s -O %s %s",
-                              wget_opts,
+  fetch_str = g_strdup_printf ("fetch -p -q -o %s %s",
                               p->tmpfile,
                               panel_cursource (p)->img_name);
 
-  p->cmd_pipe = popen (wget_str, "r");
-  g_free (wget_str);
+  p->cmd_pipe = popen (fetch_str, "r");
+  g_free (fetch_str);
   if (p->cmd_pipe == NULL)
   {
     unlink (p->tmpfile);
     g_free (p->tmpfile);
     p->tmpfile = NULL;
     p->delete_when_done = FALSE;
-    report_error (_("Couldn't start wget: %s"), strerror (errno));
+    report_error (_("Couldn't start fetch: %s"), strerror (errno));
     return;
   }
   fcntl (fileno (p->cmd_pipe), F_SETFL, O_NONBLOCK);
@@ -578,7 +575,7 @@
     /* if we reach here the pipe is dead- the command has finished. */
     code = pclose (p->cmd_pipe);
     p->cmd_pipe = NULL;
-    if (p->from_script == FALSE && code == 0) /* success for wget */
+    if (p->from_script == FALSE && code == 0) /* success for fetch */
     {
       load_image_file (p, p->tmpfile);
       g_free (p->tmpfile);
@@ -598,7 +595,7 @@
     load_image_file (p, buf);
   }
 
-  /* if we get here with wget, then wget said something. This is generally
+  /* if we get here with fetch, then fetch said something. This is generally
      not good, since we passed -q. We'll have to wait for it to die */
     
   pclose (p->cmd_pipe);
