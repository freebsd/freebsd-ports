--- src/menuspec.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/menuspec.cpp
@@ -616,7 +616,8 @@ void MenuMgr::ReadPopupMenu(FXRegistry*r
       memset(keyname,0, sizeof(keyname));
       snprintf(keyname,sizeof(keyname)-1,"Command_%d", i+1);
       if (reg->existingEntry(popup_sect,keyname)) {
-        PopupCommands[i]=strdup(reg->readStringEntry(popup_sect,keyname));
+        const char*tmp=reg->readStringEntry(popup_sect,keyname);
+        PopupCommands[i]=strdup(tmp?tmp:"");
       }
     }
   } else {
