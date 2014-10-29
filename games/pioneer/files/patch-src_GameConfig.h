--- src/GameConfig.h.orig	2014-08-28 18:02:26.000000000 +0400
+++ src/GameConfig.h	2014-09-01 03:51:12.000000000 +0400
@@ -8,7 +8,8 @@
 
 class GameConfig : public IniConfig {
 public:
-	GameConfig(const std::map<std::string,std::string> &override_ = std::map<std::string,std::string>());
+	typedef std::map<std::string, std::string> map_string;
+	GameConfig(const map_string &override_ = map_string());
 
 	void Load();
 	bool Save();
