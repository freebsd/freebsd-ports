--- kent/src/inc/common.mk.orig	2026-07-07 22:13:59 UTC
+++ kent/src/inc/common.mk
@@ -124,6 +124,9 @@ ifeq ($(UNAME_S),Darwin)
   ifneq ($(wildcard /opt/local/lib/libiconv.a),)
     ICONVLIB = /opt/local/lib/libiconv.a
   endif
+  ifeq ($(UNAME_S),FreeBSD)
+    ICONVLIB=-L${LOCALBASE}/lib -liconv
+  endif
   ifneq ($(wildcard /usr/local/Cellar/mariadb/11.6.2/lib/libmariadbclient.a),)
       MYSQLLIBS = /usr/local/Cellar/mariadb/11.6.2/lib/libmariadbclient.a
   else
