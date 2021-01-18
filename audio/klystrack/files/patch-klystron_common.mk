--- klystron/common.mk.orig	2021-01-18 12:35:42 UTC
+++ klystron/common.mk
@@ -1,3 +1,5 @@
+MAKE ?= make
+
 # make it possible to do a verbose build by running `make V=1`
 ifeq ($(V),1)
 Q=
