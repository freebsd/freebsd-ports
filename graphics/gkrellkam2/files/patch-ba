--- gkrellkam2.c.orig	Sun Nov 24 04:26:59 2002
+++ gkrellkam2.c	Sun Nov 24 04:30:50 2002
@@ -139,8 +139,7 @@
 "_full_ filename in the \"Image Source\" box. To watch a webcam\n",
 "or other online picture, or use an online list, just put its\n",
 "address (beginning with http:// or ftp://) in the \"Image Source\n",
-"box. Lists should end in \"-list\" or \".list\". You'll need GNU\n",
-"wget installed to be able to get files from the internet.\n",
+"box. Lists should end in \"-list\" or \".list\".\n",
 "Special case: when this field begins with \"-x\" followed by a\n",
 "space and some more text, the remaining text is assumed to be a\n",
 "script or other system commmand, and the whole path does not\n",
@@ -178,7 +177,6 @@
   ""
 };
 
-#define wget_opts "--cache=off"
 #define BUFLEN 256
 #define MIN_NUMPANELS 0
 #define MAX_NUMPANELS 5
@@ -690,11 +688,11 @@
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
 
@@ -710,16 +708,16 @@
   }
   close (tmpfd);
 
-  wget_str = g_strdup_printf ("wget -q %s -O %s \"%s\"",
-                              wget_opts, tmpfile,
+  fetch_str = g_strdup_printf ("fetch -p -q -o %s \"%s\"",
+			      tmpfile,
                               panel_cursource (p)->img_name);
 
-  p->cmd_pipe = popen (wget_str, "r");
-  g_free (wget_str);
+  p->cmd_pipe = popen (fetch_str, "r");
+  g_free (fetch_str);
   if (p->cmd_pipe == NULL)
   {
     unlink (tmpfile);
-    report_error (p, _("Couldn't start wget: %s"), strerror (errno));
+    report_error (p, _("Couldn't start fetch: %s"), strerror (errno));
     return;
   }
   
@@ -819,7 +817,7 @@
     p->cmd_pipe = NULL;
 
     /* pclose will return a -1 on a wait4 error. If that happens,
-       we have no way to know whether wget succeeded. Just try */
+       we have no way to know whether fetch succeeded. Just try */
     if (ks->type == SOURCE_URL && code <= 0)
     {
       ks->next_dl = time (NULL) + ks->tlife;
@@ -827,7 +825,7 @@
       return 1;
     }
 
-    report_error (p, _("Error: wget gave bad code or script died. code %d"),
+    report_error (p, _("Error: fetch gave bad code or script died. code %d"),
                   code);
     return -1;
   }
@@ -848,10 +846,10 @@
   }
   else
   {
-    /* if we get here with wget, then wget said something. This is generally
+    /* if we get here with fetch, then fetch said something. This is generally
        not good, since we passed -q. We'll have to wait for it to die */
     
-    report_error (p, _("wget said: \"%s\""), buf);
+    report_error (p, _("fetch said: \"%s\""), buf);
     return -1;
   }
 }
@@ -949,14 +947,14 @@
     code = 256;
 
   /* pclose will return a -1 on a wait4 error. If that happens,
-     we have no way to know whether wget succeeded. Just try */
+     we have no way to know whether fetch succeeded. Just try */
   if (code <= 0)
   {
     kkam_read_list (p, p->listurl_file, 0);
     update_image (p);
   }
   else
-    report_error (p, _("Error: wget listurl download died. code %d"), code);
+    report_error (p, _("Error: fetch listurl download died. code %d"), code);
 
   unlink (p->listurl_file);
   g_free (p->listurl_file);
@@ -1607,7 +1605,7 @@
 
 static void kkam_read_listurl (KKamPanel *p, char *source)
 {
-  gchar *wget_str;
+  gchar *fetch_str;
   char tmpfile[] = TEMPTEMPLATE "-urllistXXXXXX";
   int tmpfd;
 
@@ -1623,15 +1621,15 @@
   }
   close (tmpfd);
 
-  wget_str = g_strdup_printf ("wget -q %s -O %s \"%s\"",
-                              wget_opts, tmpfile, source);
+  fetch_str = g_strdup_printf ("fetch -p -q -o %s \"%s\"",
+                              tmpfile, source);
 
-  p->listurl_pipe = popen (wget_str, "r");
-  g_free (wget_str);
+  p->listurl_pipe = popen (fetch_str, "r");
+  g_free (fetch_str);
   if (p->listurl_pipe == NULL)
   {
     unlink (tmpfile);
-    report_error (p, _("Couldn't start wget for list download: %s"),
+    report_error (p, _("Couldn't start fetch for list download: %s"),
                   strerror (errno));
     return;
   }
