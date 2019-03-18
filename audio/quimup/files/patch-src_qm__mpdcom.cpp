--- src/qm_mpdcom.cpp.orig	2018-12-11 21:49:38 UTC
+++ src/qm_mpdcom.cpp
@@ -367,16 +367,16 @@ QString qm_mpdCom::get_from_etcdefaultmpd()
     QFile file;
     QString line = "";
 
-    file.setFileName("/etc/default/mpd");
+    file.setFileName("%%PREFIX%%/etc/musicpd.conf");
     if ( !file.exists() )
     {
-        printf ("MPD's config : Tried /etc/default/mpd but it does not exist\n");
+        printf ("MPD's config : Tried %%PREFIX%%/etc/musicpd.conf but it does not exist\n");
         return line;
     }
 
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
-        printf ("MPD's config : Tried /etc/default/mpd but it is not readable\n");
+        printf ("MPD's config : Tried %%PREFIX%%/etc/musicpd.conf but it is not readable\n");
         return line;
     }
 
@@ -393,10 +393,10 @@ QString qm_mpdCom::get_from_etcdefaultmpd()
     file.close();
 
     if (line.isEmpty())
-        printf ("MPD's config : Tried /etc/default/mpd but MPDCONF is not set\n");
+        printf ("MPD's config : Tried %%PREFIX%%/etc/musicpd.conf but MPDCONF is not set\n");
     else
     {
-        QString msg  = "MPD's config found in /etc/default/mpd : " + line + "\n";
+        QString msg  = "MPD's config found in %%PREFIX%%/etc/musicpd.conf : " + line + "\n";
         printf ("%s", msg.toUtf8().constData());
     }
 
@@ -2710,17 +2710,10 @@ bool qm_mpdCom::is_mpd_running()
     struct stat sts;
     bool b_isrunning = false;
 
-    // try pidof
-    if (stat("/bin/pidof", &sts) == 0)
-    {
-        if( system("pidof mpd > /dev/null") == 0)
-        b_isrunning = true;
-    }
-    else
     // try pgrep
-    if (stat("/usr/bin/pgrep", &sts) == 0)
+    if (stat("/bin/pgrep", &sts) == 0)
     {
-        if( system("pgrep mpd > /dev/null") == 0)
+        if( system("pgrep musicpd > /dev/null") == 0)
             b_isrunning = true;
     }
 
