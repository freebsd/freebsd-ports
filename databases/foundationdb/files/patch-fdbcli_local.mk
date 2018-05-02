--- fdbcli/local.mk.orig	2018-04-19 02:55:50 UTC
+++ fdbcli/local.mk
@@ -22,7 +22,7 @@
 
 fdbcli_CFLAGS := $(fdbclient_CFLAGS)
 fdbcli_LDFLAGS := $(fdbrpc_LDFLAGS)
-fdbcli_LIBS := lib/libfdbclient.a lib/libfdbrpc.a lib/libflow.a -ldl
+fdbcli_LIBS := lib/libfdbclient.a lib/libfdbrpc.a lib/libflow.a
 fdbcli_STATIC_LIBS :=
 
 fdbcli_GENERATED_SOURCES += versions.h
@@ -32,6 +32,8 @@ ifeq ($(PLATFORM),linux)
   fdbcli_LIBS += -lpthread -lrt
 else ifeq ($(PLATFORM),osx)
   fdbcli_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbcli_LDFLAGS += -lc++ -lm -lpthread -leio -lexecinfo
 endif
 
 test_fdbcli_status: fdbcli
