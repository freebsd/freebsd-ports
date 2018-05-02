--- flow/local.mk.orig	2018-04-19 02:55:50 UTC
+++ flow/local.mk
@@ -20,8 +20,9 @@
 
 # -*- mode: makefile; -*-
 
-flow_CFLAGS := -I$(BOOSTDIR) -I. -Iflow -DUSE_UCONTEXT
-flow_LDFLAGS :=
+flow_CFLAGS := -I$(BOOSTDIR)/include -I. -Iflow -DUSE_UCONTEXT
+flow_LDFLAGS := -L$(BOOSTDIR)/lib
+flow_LIBS := -lm -lc++ -lpthread -leio -lexecinfo
 
 ifeq ($(PLATFORM),osx)
   flow_CFLAGS += -fasynchronous-unwind-tables -fno-omit-frame-pointer
