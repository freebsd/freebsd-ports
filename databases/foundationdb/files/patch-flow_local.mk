--- flow/local.mk.orig	2019-04-09 00:11:05 UTC
+++ flow/local.mk
@@ -20,8 +20,9 @@
 
 # -*- mode: makefile; -*-
 
-flow_CFLAGS := -I$(BOOSTDIR) -I. -DUSE_UCONTEXT
-flow_LDFLAGS :=
+flow_CFLAGS := -I$(BOOSTDIR)/include -I. -DUSE_UCONTEXT
+flow_LDFLAGS := -L$(BOOSTDIR)/lib
+flow_LIBS := -lm -lc++ -lpthread -leio -lexecinfo -lboost_system
 
 ifeq ($(PLATFORM),osx)
   flow_CFLAGS += -fasynchronous-unwind-tables -fno-omit-frame-pointer
