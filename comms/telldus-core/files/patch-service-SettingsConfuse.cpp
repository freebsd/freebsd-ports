--- service/SettingsConfuse.cpp
+++ service/SettingsConfuse.cpp
@@ -17,6 +17,8 @@
 
 class Settings::PrivateData {
 public:
+	PrivateData()
+		: cfg(NULL), var_cfg(NULL) {}
 	cfg_t *cfg;
 	cfg_t *var_cfg;
 };
