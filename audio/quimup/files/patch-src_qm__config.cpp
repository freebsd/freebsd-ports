--- src/qm_config.cpp.orig	2018-11-28 18:19:33 UTC
+++ src/qm_config.cpp
@@ -172,9 +172,9 @@ void qm_config::load_config()
     version       	    = sts.value("version",			    "0.0" ).toString();  
     // server related values
     quitMPD_onquit    	= sts.value("quitMPD_onquit",		false ).toBool();
-    onquit_mpd_command  = sts.value("onquit_mpd_command",	"mpd --kill").toString();
+    onquit_mpd_command  = sts.value("onquit_mpd_command",	"musicpd --kill").toString();
     startMPD_onstart    = sts.value("startMPD_onstart",		false  ).toBool();
-    onstart_mpd_command = sts.value("onstart_mpd_command",	"mpd"  ).toString();
+    onstart_mpd_command = sts.value("onstart_mpd_command",	"musicpd"  ).toString();
     auto_connect     	= sts.value("auto_connect",			true   ).toBool();
     start_minimized     = sts.value("start_minimized",		false   ).toBool();
     
