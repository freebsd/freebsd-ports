--- fdbserver/local.mk.orig	2018-09-11 01:21:54 UTC
+++ fdbserver/local.mk
@@ -35,6 +35,8 @@ ifeq ($(PLATFORM),linux)
   # fdbserver_STATIC_LIBS += -ltcmalloc -lunwind -lprofiler
 else ifeq ($(PLATFORM),osx)
   fdbserver_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbserver_LDFLAGS += -lc++ -lm -lpthread -lexecinfo -leio -lboost_system
 endif
 
 ifeq ($(WORKLOADS),false)
