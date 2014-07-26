--- odalaunch/src/dlg_main.cpp.orig	2013-11-29 02:22:10.000000000 +0100
+++ odalaunch/src/dlg_main.cpp	2014-07-19 17:50:52.000000000 +0200
@@ -1,7 +1,7 @@
 // Emacs style mode select   -*- C++ -*-
 //-----------------------------------------------------------------------------
 //
-// $Id: dlg_main.cpp 4376 2013-11-29 01:22:10Z russellrice $
+// $Id: dlg_main.cpp 4996 2014-06-11 04:26:49Z hypereye $
 //
 // Copyright (C) 2006-2012 by The Odamex Team.
 //
@@ -208,7 +208,7 @@
     launchercfg_s.get_list_on_start = 1;
     launchercfg_s.show_blocked_servers = 0;
     launchercfg_s.wad_paths = wxGetCwd();
-    launchercfg_s.odamex_directory = wxGetCwd();
+    launchercfg_s.odamex_directory = wxString("/usr/local/bin");
 
     m_LstCtrlServers = XRCCTRL(*this, "Id_LstCtrlServers", LstOdaServerList);
     m_LstCtrlPlayers = XRCCTRL(*this, "Id_LstCtrlPlayers", LstOdaPlayerList);
@@ -383,6 +383,7 @@
     wxFileConfig ConfigInfo;
     wxInt32 ServerTimeout;
     Server tmp_server;
+    odalpapi::BufferedSocket socket;	
     wxString server_hash;
     wxString ped_hash;
     wxString ped_result;
@@ -455,6 +456,7 @@
     }
 
     // Query the server and try to acquire its password hash
+    tmp_server.SetSocket(&socket);
     tmp_server.SetAddress(wxstr_tostdstr(IPHost), Port);
     tmp_server.Query(ServerTimeout);
 
