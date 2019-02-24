--- fdbcli/local.mk.orig	2018-09-11 01:21:54 UTC
+++ fdbcli/local.mk
@@ -22,7 +22,7 @@
 
 fdbcli_CFLAGS := $(fdbclient_CFLAGS)
 fdbcli_LDFLAGS := $(fdbrpc_LDFLAGS)
-fdbcli_LIBS := lib/libfdbclient.a lib/libfdbrpc.a lib/libflow.a -ldl $(FDB_TLS_LIB)
+fdbcli_LIBS := lib/libfdbclient.a lib/libfdbrpc.a lib/libflow.a $(FDB_TLS_LIB)
 fdbcli_STATIC_LIBS := $(TLS_LIBS)
 
 fdbcli_GENERATED_SOURCES += versions.h
@@ -32,6 +32,8 @@ ifeq ($(PLATFORM),linux)
   fdbcli_LIBS += -lpthread -lrt
 else ifeq ($(PLATFORM),osx)
   fdbcli_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbcli_LDFLAGS += -lc++ -lm -lpthread -leio -lexecinfo -lboost_system
 endif
 
 test_fdbcli_status: fdbcli
