--- src/GameConfig.h.orig	2015-06-07 21:44:10 UTC
+++ src/GameConfig.h
@@ -8,7 +8,8 @@
 
 class GameConfig : public IniConfig {
 public:
-	GameConfig(const std::map<std::string,std::string> &override_ = std::map<std::string,std::string>());
+	typedef std::map<std::string, std::string> map_string;
+	GameConfig(const map_string &override_ = map_string());
 
 	void Load();
 	bool Save();
