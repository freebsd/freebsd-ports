--- ./solenv/inc/libs.mk.orig	2013-02-01 13:12:41.000000000 -0500
+++ ./solenv/inc/libs.mk	2013-02-01 13:40:41.000000000 -0500
@@ -213,7 +213,7 @@
 NEON3RDLIB=-lneon
 .ENDIF
 .IF "$(SYSTEM_DB)" == "YES"
-BERKELEYLIB=-l$(DB_LIB)
+BERKELEYLIB=$(DB_LIB)
 .ELIF "$(GUI)$(COM)"=="WNTGCC"
 BERKELEYLIB=-ldb47
 .ELSE
