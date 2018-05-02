--- fdbclient/local.mk.orig	2018-04-26 06:55:09 UTC
+++ fdbclient/local.mk
@@ -21,7 +21,7 @@
 # -*- mode: makefile; -*-
 
 fdbclient_CFLAGS := $(fdbrpc_CFLAGS)
-
+fdbclient_LIBS := -lm -lc++ -lpthread -lexecinfo -leio
 fdbclient_GENERATED_SOURCES += fdbclient/FDBOptions.g.h
 
 fdbclient/FDBOptions.g.cpp: fdbclient/FDBOptions.g.h
