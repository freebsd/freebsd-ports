--- FDBLibTLS/local.mk.orig	2019-04-09 00:11:05 UTC
+++ FDBLibTLS/local.mk
@@ -23,6 +23,6 @@
 FDBLibTLS_BUILD_SOURCES +=
 
 
-FDBLibTLS_CFLAGS := -fPIC -I/usr/local/include -I$(BOOSTDIR) -I. -DUSE_UCONTEXT
+FDBLibTLS_CFLAGS := -fPIC -I$(BOOSTDIR)/include -I. -DUSE_UCONTEXT
 
 lib/libFDBLibTLS.a: bin/coverage.FDBLibTLS.xml
