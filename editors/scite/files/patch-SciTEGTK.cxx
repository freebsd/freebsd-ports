--- SciTEGTK.cxx.orig	Tue Nov  5 17:24:05 2002
+++ SciTEGTK.cxx	Tue Nov  5 17:24:42 2002
@@ -1910,7 +1910,7 @@
 	return 0;
 }
 
-void SciTEGTK::AddToPopUp(const char *label, int cmd, bool enabled) {
+void SciTEGTK::AddToPopUp(const char *label, int cmd=0, bool enabled=true) {
 	SString localised = LocaliseString(label);
 	localised.insert(0, "/");
 	GtkItemFactoryEntry itemEntry = {
