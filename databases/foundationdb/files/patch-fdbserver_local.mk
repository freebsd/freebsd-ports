--- fdbserver/local.mk.orig	2018-04-19 02:55:50 UTC
+++ fdbserver/local.mk
@@ -34,6 +34,8 @@ ifeq ($(PLATFORM),linux)
   # fdbserver_STATIC_LIBS += -ltcmalloc -lunwind -lprofiler
 else ifeq ($(PLATFORM),osx)
   fdbserver_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbserver_LDFLAGS += -lc++ -lm -lpthread -lexecinfo -leio
 endif
 
 ifeq ($(WORKLOADS),false)
