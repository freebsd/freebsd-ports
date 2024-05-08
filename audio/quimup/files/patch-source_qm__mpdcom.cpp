--- source/qm_mpdcom.cpp.orig	2024-02-02 09:26:32 UTC
+++ source/qm_mpdcom.cpp
@@ -369,32 +369,35 @@ QString qm_mpdCommand::get_mpdconf_path()
             mpdconf_path = find_config_files(false);
     }
 
-    if (confpath.isEmpty())
+    if (confpath.isEmpty() && mpdconf_path.isEmpty())
         b_mpdconf_found = false;
     else
         b_mpdconf_found = true;
 
+    if (!mpdconf_path.isEmpty())
+        return mpdconf_path;
+
     return confpath;
 }
 
-// Get mpd.conf from  /etc/default/mpd
+// Get mpd.conf from  %%PREFIX%%/etc/musicpd.conf
 QString qm_mpdCommand::get_etc_default_mpd()
 {
     QFile file;
     QString line = "";
 
-    file.setFileName("/etc/default/mpd");
+    file.setFileName("%%PREFIX%%/etc/musicpd.conf");
     if ( !file.exists() )
     {
         if (config->cout_extensive)
-            printf ("MPD's config: Tried /etc/default/mpd but it does not exist\n");
+            printf ("MPD's config: Tried %%PREFIX%%/etc/musicpd.conf but it does not exist\n");
         return line;
     }
 
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         if (config->cout_extensive)
-            printf ("MPD's config: Tried /etc/default/mpd but it is not readable\n");
+            printf ("MPD's config: Tried %%PREFIX%%/etc/musicpd.conf but it is not readable\n");
         return line;
     }
     else
@@ -418,19 +421,19 @@ QString qm_mpdCommand::get_etc_default_mpd()
         if (!file.exists())
         {
             if (config->cout_extensive)
-                printf ("MPD's config in /etc/default/mpd does not exist\n");
+                printf ("MPD's config in %%PREFIX%%/etc/musicpd.conf does not exist\n");
             line = "";
         }
     }
     else
     {
         if (config->cout_extensive)
-            printf ("MPD's config: Tried /etc/default/mpd but MPDCONF is not set\n");
+            printf ("MPD's config: Tried %%PREFIX%%/etc/musicpd.conf but MPDCONF is not set\n");
     }
 
     if (!line.isEmpty() && config->cout_extensive)
     {
-        printf ("MPD's config from /etc/default/mpd: %s\n", line.toUtf8().constData());
+        printf ("MPD's config from %%PREFIX%%/etc/musicpd.conf: %s\n", line.toUtf8().constData());
     }
 
     return line;
@@ -2996,7 +2999,7 @@ QString qm_mpdCommand::find_config_files(bool show_dia
 
 QString qm_mpdCommand::find_config_files(bool show_dialog)
 {
-/*  If not specified on the command-line or in /etc/default/mpd
+/*  If not specified on the command-line or in %%PREFIX%%/etc/musicpd.conf
     MPD searches
     1st at    ~/.config/mpd/mpd.conf
     2nd at     ~/.mpdconf
@@ -3062,20 +3065,20 @@ QString qm_mpdCommand::find_config_files(bool show_dia
         }
     }
 
-    thispath = "/etc/mpd.conf";
+    thispath = "%%PREFIX%%/etc/musicpd.conf";
     file.setFileName(thispath);
     if ( file.exists() )
     {
         if (file.open(QIODevice::ReadOnly))
         {
             file.close();
-            printf ("located: /etc/mpd.conf\n");
+            printf ("located: %%PREFIX%%/etc/musicpd.conf\n");
             return thispath;
         }
         else
         {
             if (config->cout_extensive)
-                printf ("/etc/mpd.conf, but it is not readable\n");
+                printf ("%%PREFIX%%/etc/musicpd.conf, but it is not readable\n");
         }
     }
 
@@ -3196,7 +3199,7 @@ bool qm_mpdCommand::is_mpd_installed(bool showmsg)
 {
     QProcess proc;
     proc.setProgram("which");
-    proc.setArguments({"mpd"});
+    proc.setArguments({"musicpd"});
     proc.start();
     if (!proc.waitForFinished())
     {
@@ -3207,7 +3210,7 @@ bool qm_mpdCommand::is_mpd_installed(bool showmsg)
 
     QString output = proc.readAllStandardOutput();
     output = output.trimmed();
-    if (output.contains("/usr/bin/mpd") || output.contains("/usr/local/bin/mpd") || output.contains("/usr/sbin/mpd"))
+    if (output.contains("%%PREFIX%%/bin/musicpd"))
     {
         if (showmsg)
             printf ("MPD is installed on this system\n");
@@ -3227,8 +3230,8 @@ bool qm_mpdCommand::is_mpd_running(bool showmsg)
     config->mpd_process_owner = ""; // empty equals not running
 
     QProcess proc;
-    proc.setProgram("pidof");
-    proc.setArguments({"mpd"});
+    proc.setProgram("pgrep");
+    proc.setArguments({"musicpd"});
     proc.start();
     if (!proc.waitForFinished())
         return false;
