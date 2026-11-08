--- odk/settings/settings.mk.orig	2021-04-02 12:58:21 UTC
+++ odk/settings/settings.mk
@@ -491,7 +491,7 @@ ifneq (,$(findstring freebsd,$(PLATFORM)))
 ifneq (,$(findstring freebsd,$(PLATFORM)))
 # Settings for FreeBSD using gcc compiler
 
-PROCTYPE := $(shell $(PRJ)/config.guess | cut -d"-" -f1)
+PROCTYPE := $(shell $(PRJ)/config.guess | cut -d "-" -f1 | sed -e 's/^i.86$$/i386/')
 
 ifeq (kfreebsd,$(findstring kfreebsd,$(PLATFORM)))
 PLATFORM=kfreebsd
