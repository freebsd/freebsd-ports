--- src/3rdparty/qjsonrpc/src/json/json.pri.orig	2017-07-20 14:27:57 UTC
+++ src/3rdparty/qjsonrpc/src/json/json.pri
@@ -29,4 +29,4 @@ json.files = \
     $${PWD}/qjsonarray.h
 
 json.path = $${PREFIX}/include/qjsonrpc/json
-INSTALLS += json
+# INSTALLS += json
