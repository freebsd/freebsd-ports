--- src/SqlUiLexer.cpp.orig	2026-09-01 07:41:25 UTC
+++ src/SqlUiLexer.cpp
@@ -4,7 +4,7 @@
 #include "Qsci/qsciapis.h"
 #include "Settings.h"
 #include "sqlitedb.h"
-#include "sqlite3.h"
+#include "sqlcipher/sqlite3.h"
 
 namespace
 {
