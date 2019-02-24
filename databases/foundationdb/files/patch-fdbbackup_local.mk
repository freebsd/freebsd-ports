--- fdbbackup/local.mk.orig	2018-09-11 01:21:54 UTC
+++ fdbbackup/local.mk
@@ -35,6 +35,8 @@ ifeq ($(PLATFORM),linux)
   # fdbbackup_STATIC_LIBS += -ltcmalloc -lunwind -lprofiler
 else ifeq ($(PLATFORM),osx)
   fdbbackup_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbbackup_LDFLAGS += -lc++ -lm -lexecinfo -lpthread -leio -lboost_system
 endif
 
 fdbbackup_GENERATED_SOURCES += versions.h
