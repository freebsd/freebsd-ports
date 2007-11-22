--- common/UpdateDlg.cpp.orig	2007-11-13 23:56:27.000000000 +0100
+++ common/UpdateDlg.cpp	2007-11-13 23:56:46.000000000 +0100
@@ -56,7 +56,7 @@
 #	endif
 #endif /* WIN32 */
 
-char *sDefTagNames[] = 
+const char *sDefTagNames[] = 
 {
 	"1.1",
 	"1.6.2.4",
@@ -65,7 +65,7 @@
 	0L
 };
 
-char *sDefDateNames[] = 
+const char *sDefDateNames[] = 
 {
 	"1998-3",
 	"1998-3-24",
@@ -76,7 +76,7 @@
 	0L
 };
 
-char *sDefRevDateNames[] = 
+const char *sDefRevDateNames[] = 
 {
 	"1.1",
 	"1.6.2.4",
