--- src/qm_mpdcom.cpp.orig	2016-02-28 09:52:46 UTC
+++ src/qm_mpdcom.cpp
@@ -2500,17 +2500,10 @@ bool qm_mpdCom::is_mpd_running()
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
 
