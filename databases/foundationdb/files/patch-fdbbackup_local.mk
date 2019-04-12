--- fdbbackup/local.mk.orig	2019-04-09 00:11:05 UTC
+++ fdbbackup/local.mk
@@ -34,6 +34,8 @@ ifeq ($(PLATFORM),linux)
   # fdbbackup_STATIC_LIBS += -ltcmalloc -lunwind -lprofiler
 else ifeq ($(PLATFORM),osx)
   fdbbackup_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbbackup_LDFLAGS += -lc++ -lm -lexecinfo -lpthread -leio -lboost_system
 endif
 
 fdbbackup_GENERATED_SOURCES += versions.h
