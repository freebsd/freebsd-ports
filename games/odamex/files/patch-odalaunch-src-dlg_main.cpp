--- odalaunch/src/dlg_main.cpp.orig	2012-05-31 03:49:32.000000000 +0400
+++ odalaunch/src/dlg_main.cpp	2012-12-03 21:21:50.000000000 +0400
@@ -193,7 +193,7 @@
     launchercfg_s.get_list_on_start = 1;
     launchercfg_s.show_blocked_servers = 0;
     launchercfg_s.wad_paths = wxGetCwd();
-    launchercfg_s.odamex_directory = wxGetCwd();
+    launchercfg_s.odamex_directory = wxString("%%PREFIX%%/bin");
 
     m_LstCtrlServers = XRCCTRL(*this, "Id_LstCtrlServers", LstOdaServerList);
     m_LstCtrlPlayers = XRCCTRL(*this, "Id_LstCtrlPlayers", LstOdaPlayerList);
