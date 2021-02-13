--- binr/rules.mk.orig	2021-02-11 00:59:05 UTC
+++ binr/rules.mk
@@ -3,6 +3,8 @@ include ../../libr/config.mk
 include ../../shlr/zip/deps.mk
 include ../../shlr/sdb.mk
 
+LDFLAGS+=-lexecinfo
+
 ifeq (,$(findstring tcc,${CC}))
 CFLAGS+=-pie
 endif
