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
@@ -42,10 +44,10 @@
 */
 Settings::~Settings(void) {
 	TelldusCore::MutexLocker locker(&mutex);
-	if (d->cfg > 0) {
+	if (d->cfg != 0) {
 		cfg_free(d->cfg);
 	}
-	if (d->var_cfg > 0) {
+	if (d->var_cfg != 0) {
 		cfg_free(d->var_cfg);
 	}
 	delete d;
@@ -56,7 +58,7 @@
 */
 std::wstring Settings::getSetting(const std::wstring &strName) const {
 	TelldusCore::MutexLocker locker(&mutex);
-	if (d->cfg > 0) {
+	if (d->cfg != 0) {
 		std::string setting(cfg_getstr(d->cfg, TelldusCore::wideToString(strName).c_str()));
 		return TelldusCore::charToWstring(setting.c_str());
 	}
@@ -68,7 +70,7 @@
 */
 int Settings::getNumberOfNodes(Node node) const {
 	TelldusCore::MutexLocker locker(&mutex);
-	if (d->cfg > 0) {
+	if (d->cfg != 0) {
 		if (node == Device) {
 			return cfg_size(d->cfg, "device");
 		} else if (node == Controller) {
