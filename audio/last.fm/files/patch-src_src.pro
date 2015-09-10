--- src/src.pro.orig	2010-10-11 17:11:16 UTC
+++ src/src.pro
@@ -4,13 +4,7 @@ QT += gui network xml sql
 
 INCLUDEPATH += lib libFingerprint/recommendation-commons
 
-PRECOMPILED_HEADER = precompiled.h
-CONFIG += precompile_header
-
-unix {
-    # precompiled headers breaks icecream builds for some reason :(
-    system( test `ps aux | grep iceccd | wc -l` -gt 1 ): CONFIG -= precompile_header
-}
+CONFIG -= precompile_header
 
 #universal binaries cannot be built from precompiled headers
 mac:release:CONFIG -= precompile_header
