- workaround for https://github.com/pawelsalawa/sqlitestudio/issues/4999

--- ../Plugins/DbSqliteWx/DbSqliteWx.pro.orig	2024-06-12 16:33:52 UTC
+++ ../Plugins/DbSqliteWx/DbSqliteWx.pro
@@ -66,7 +66,7 @@ DEFINES += SQLITE_HAS_CODEC SQLITE_ALLOW_XTHREAD_CONNE
     SQLITE_ENABLE_RTREE=1 \
     SQLITE_ENABLE_MATH_FUNCTIONS=1
 
-QMAKE_CFLAGS += -msse4.1 -msse4.2 -maes
+#QMAKE_CFLAGS += -msse4.1 -msse4.2 -maes
 QMAKE_CFLAGS_WARN_ON = -Wall -Wno-unused-parameter -Wno-sign-compare -Wno-unused-function -Wno-unused-but-set-variable \
     -Wno-parentheses -Wno-unused-variable -Wno-unknown-pragmas
 
