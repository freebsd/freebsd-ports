--- source/qm_config.cpp.orig	2024-01-31 18:06:04 UTC
+++ source/qm_config.cpp
@@ -191,9 +191,9 @@ void qm_Config::load_config()
 
  // server related values
  onquit_quitmpd = sts.value("onquit_quitmpd", false ).toBool();
- onquit_mpd_command = sts.value("onquit_mpd_command", "systemctl --user stop mpd").toString();
+ onquit_mpd_command = sts.value("onquit_mpd_command", "musicpd --kill" ).toString();
  onstart_startmpd = sts.value("onstart_startmpd", false ).toBool();
- onstart_mpd_command = sts.value("onstart_mpd_command", "systemctl --user start mpd" ).toString();
+ onstart_mpd_command = sts.value("onstart_mpd_command", "musicpd" ).toString();
  auto_connect = sts.value("auto_connect", true ).toBool();
  auto_re_connect = sts.value("auto_re_connect", true ).toBool();
  mpd_timeout = sts.value("mpd_timeout", 12 ).toInt();
