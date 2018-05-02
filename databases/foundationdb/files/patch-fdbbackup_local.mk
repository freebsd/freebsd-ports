--- fdbbackup/local.mk.orig	2018-04-19 02:55:50 UTC
+++ fdbbackup/local.mk
@@ -34,6 +34,8 @@ ifeq ($(PLATFORM),linux)
   # fdbbackup_STATIC_LIBS += -ltcmalloc -lunwind -lprofiler
 else ifeq ($(PLATFORM),osx)
   fdbbackup_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbbackup_LDFLAGS += -lc++ -lm -lexecinfo -lpthread -leio
 endif
 
 fdbbackup_GENERATED_SOURCES += versions.h
