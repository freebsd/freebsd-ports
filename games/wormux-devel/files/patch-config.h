--- src/game/config.h.orig	2008-08-20 13:36:54.000000000 +0300
+++ src/game/config.h	2008-08-20 13:35:42.000000000 +0300
@@ -126,7 +126,7 @@
 
   const std::string& GetTtfFilename();
 
-  std::string GetDataDir() const { return data_dir; };
+  std::string GetDataDir() const { return data_dir + "/"; };
   std::string GetLocaleDir() const { return locale_dir; };
   std::string GetPersonalDataDir() const { return personal_data_dir; };
   std::string GetChatLogDir() const { return chat_log_dir; };
