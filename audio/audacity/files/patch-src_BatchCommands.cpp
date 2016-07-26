--- src/BatchCommands.cpp.orig	2016-07-26 13:34:06 UTC
+++ src/BatchCommands.cpp
@@ -151,7 +151,7 @@ bool BatchCommands::ReadChain(const wxSt
          else if (cmd == wxT("ExportWav"))
             cmd = wxT("ExportWAV");
          else if (cmd == wxT("Compressor") && (parm.find(wxT("DecayTime")) != parm.npos))
-            parm.Replace(wxT("DecayTime"), wxT("ReleaseTime"), NULL);   // 2.0.6
+            parm.Replace(wxT("DecayTime"), wxT("ReleaseTime"), false);   // 2.0.6
 
          // Add to lists
          mCommandChain.Add(cmd);
