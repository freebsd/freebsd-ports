--- common/ImportFilterDlg.cpp.orig	2007-11-13 22:52:32.000000000 +0100
+++ common/ImportFilterDlg.cpp	2007-11-13 22:53:30.000000000 +0100
@@ -892,7 +892,7 @@
 
 #define NUM_COLUMNS	3
 
-static char *_gszColumnLabel[NUM_COLUMNS] =
+static const char *_gszColumnLabel[NUM_COLUMNS] =
 {
 	"Entry state", "Entry description", "Entry kind"
 };
