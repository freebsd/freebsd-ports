--- common/ImportDlg.cpp.orig	2007-11-13 22:38:26.000000000 +0100
+++ common/ImportDlg.cpp	2007-11-13 22:49:01.000000000 +0100
@@ -51,20 +51,20 @@
 #include "PromptFiles.h"
 #include "TextBinary.h"
 
-static char *sDefReleases[] = 
+static const char * const sDefReleases[] = 
 {
 	"V10",
 	"V101",
 	0L
 };
 
-static char *sDefVendors[] = 
+static const char * const sDefVendors[] = 
 {
 	"GNU",
 	0L
 };
 
-static char *sDefModuleNames[] = 
+static const char * const sDefModuleNames[] = 
 {
 	"Module",
 	"Project",
