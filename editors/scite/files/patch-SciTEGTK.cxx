
$FreeBSD$

--- SciTEGTK.cxx	2002/08/19 16:01:39	1.1
+++ SciTEGTK.cxx	2002/08/19 16:02:02
@@ -1882,7 +1882,7 @@
 	return 0;
 }
 
-void SciTEGTK::AddToPopUp(const char *label, int cmd=0, bool enabled=true) {
+void SciTEGTK::AddToPopUp(const char *label, int cmd, bool enabled) {
 	SString localised = LocaliseString(label);
 	localised.insert(0, "/");
 	GtkItemFactoryEntry itemEntry = {
