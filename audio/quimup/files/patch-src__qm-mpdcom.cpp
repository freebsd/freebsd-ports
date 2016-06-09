--- src/qm_mpdcom.cpp.orig	2016-02-28 04:52:46.000000000 -0500
+++ src/qm_mpdcom.cpp	2016-06-02 13:24:56.493027000 -0400
@@ -2500,17 +2500,10 @@
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
 
