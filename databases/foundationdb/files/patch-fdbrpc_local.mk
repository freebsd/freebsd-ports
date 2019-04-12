--- fdbrpc/local.mk.orig	2019-04-09 00:11:05 UTC
+++ fdbrpc/local.mk
@@ -20,10 +20,11 @@
 
 # -*- mode: makefile; -*-
 
-fdbrpc_BUILD_SOURCES += fdbrpc/libeio/eio.c
+#fdbrpc_BUILD_SOURCES += fdbrpc/libeio/eio.c
 
-fdbrpc_CFLAGS := -I$(BOOSTDIR) -I. -Ifdbrpc/libeio -DUSE_UCONTEXT
-fdbrpc_LDFLAGS :=
+fdbrpc_CFLAGS := -I$(BOOSTDIR)/include -I. -DUSE_UCONTEXT
+fdbrpc_LDFLAGS := -L$(BOOSTDIR)/lib
+fdbrpc_LIBS := -lm -lc++ -lpthread -leio -lboost_system
 
 ifeq ($(PLATFORM),osx)
   fdbrpc_CFLAGS += -fasynchronous-unwind-tables -fno-omit-frame-pointer
