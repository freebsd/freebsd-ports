--- odk/settings/settings.mk.orig	2026-09-18 00:49:39 UTC
+++ odk/settings/settings.mk
@@ -498,7 +498,7 @@ ifneq (,$(findstring freebsd,$(PLATFORM)))
 ifneq (,$(findstring freebsd,$(PLATFORM)))
 # Settings for FreeBSD using gcc compiler
 
-PROCTYPE := $(shell $(PRJ)/config.guess | cut -d"-" -f1)
+PROCTYPE := $(shell $(PRJ)/config.guess | cut -d "-" -f1 | sed -e 's/^i.86$$/i386/')
 
 ifeq (kfreebsd,$(findstring kfreebsd,$(PLATFORM)))
 PLATFORM=kfreebsd
