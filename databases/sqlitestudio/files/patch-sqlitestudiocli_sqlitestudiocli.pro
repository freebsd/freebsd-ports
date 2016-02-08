--- sqlitestudiocli/sqlitestudiocli.pro.orig	2015-11-24 19:09:31 UTC
+++ sqlitestudiocli/sqlitestudiocli.pro
@@ -74,7 +74,7 @@ win32: {
 }
 
 unix: {
-    LIBS += -lreadline -lcurses
+    LIBS += -lreadline -lncurses
 }
 
 HEADERS += \
