--- kent/src/inc/common.mk.orig	2024-10-16 04:15:27 UTC
+++ kent/src/inc/common.mk
@@ -65,6 +65,9 @@ ifeq ($(UNAME_S),Darwin)
   ifneq ($(wildcard /opt/local/lib/libiconv.a),)
     ICONVLIB = /opt/local/lib/libiconv.a
   endif
+  ifeq ($(UNAME_S),FreeBSD)
+    ICONVLIB=-L${LOCALBASE}/lib -liconv
+  endif
   ifneq ($(wildcard /opt/homebrew/lib/libmysqlclient.a),)
     MYSQLLIBS = /opt/homebrew/lib/libmysqlclient.a
   endif
