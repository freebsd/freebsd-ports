--- src/Config.hpp.orig	Fri Feb 22 19:18:07 2002
+++ src/Config.hpp	Thu Oct  7 21:07:16 2004
@@ -39,7 +39,7 @@
 	static Config& instance();
 private:
 	typedef std::auto_ptr<Config> ConfigPtr;
-	friend class ConfigPtr;
+	friend class std::auto_ptr<Config>;
 	Config();
 	~Config() {};
 	void setDefault(const QString& key, const char* value);
