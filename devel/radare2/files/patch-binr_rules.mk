--- binr/rules.mk.orig	2018-07-03 15:16:33 UTC
+++ binr/rules.mk
@@ -2,6 +2,8 @@ BINR_PROGRAM=1
 include ../../libr/config.mk
 include ../../shlr/zip/deps.mk
 
+LDFLAGS+=-lexecinfo
+
 ifeq (,$(findstring tcc,${CC}))
 CFLAGS+=-pie
 endif
