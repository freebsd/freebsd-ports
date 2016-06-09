--- src/qm_config.cpp.orig	2016-02-28 04:52:29.000000000 -0500
+++ src/qm_config.cpp	2016-06-02 13:28:13.722103000 -0400
@@ -168,9 +168,9 @@
     version       	    = sts.value("version",			    "0.0" ).toString();  
     // server related values
     quitMPD_onquit    	= sts.value("quitMPD_onquit",		false ).toBool();
-    onquit_mpd_command  = sts.value("onquit_mpd_command",	"mpd --kill").toString();
+    onquit_mpd_command  = sts.value("onquit_mpd_command",	"musicpd --kill").toString();
     startMPD_onstart    = sts.value("startMPD_onstart",		false  ).toBool();
-    onstart_mpd_command = sts.value("onstart_mpd_command",	"mpd"  ).toString();
+    onstart_mpd_command = sts.value("onstart_mpd_command",	"musicpd"  ).toString();
     auto_connect     	= sts.value("auto_connect",			true   ).toBool();
     
     profile    			= sts.value("profile",				0   ).toInt();
