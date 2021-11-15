--- src/libs/3rdparty/sqlite/sqlite.pri.orig	2021-11-15 16:37:07 UTC
+++ src/libs/3rdparty/sqlite/sqlite.pri
@@ -2,6 +2,7 @@ INCLUDEPATH *= $$PWD
 
 linux:DEFINES += _POSIX_C_SOURCE=200809L _GNU_SOURCE
 osx:DEFINES += _BSD_SOURCE
+freebsd:DEFINES += _POSIX_C_SOURCE=200809L _BSD_SOURCE __XSI_VISIBLE
 
 
 HEADERS += $$PWD/sqlite3.h \
