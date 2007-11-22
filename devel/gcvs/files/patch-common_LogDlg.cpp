--- common/LogDlg.cpp.orig	2007-11-13 23:54:34.000000000 +0100
+++ common/LogDlg.cpp	2007-11-13 23:54:59.000000000 +0100
@@ -57,7 +57,7 @@
 #include "CvsPrefs.h"
 #include "MultiString.h"
 
-char *sDefLogTagNames[] = 
+const char *sDefLogTagNames[] = 
 {
 	"1.32:1.35",
 	"1.32:",
@@ -67,7 +67,7 @@
 	0L
 };
 
-char *sDefLogDateNames[] = 
+const char *sDefLogDateNames[] = 
 {
 	">1998-3-24",
 	"<1998-1-24",
@@ -76,7 +76,7 @@
 	0L
 };
 
-char *sDefLogStateNames[] = 
+const char *sDefLogStateNames[] = 
 {
 	"mystate",
 	"dead",
@@ -85,7 +85,7 @@
 	0L
 };
 
-char *sDefLogUserNames[] = 
+const char *sDefLogUserNames[] = 
 {
 	"johna",
 	"garyb",
