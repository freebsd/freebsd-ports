--- src/qm_config.cpp.orig	2016-02-28 09:52:29 UTC
+++ src/qm_config.cpp
@@ -168,9 +168,9 @@ void qm_config::load_config()
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
