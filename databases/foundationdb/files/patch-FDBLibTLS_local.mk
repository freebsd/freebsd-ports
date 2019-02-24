--- FDBLibTLS/local.mk.orig	2018-09-11 01:21:54 UTC
+++ FDBLibTLS/local.mk
@@ -23,6 +23,6 @@
 FDBLibTLS_BUILD_SOURCES +=
 
 
-FDBLibTLS_CFLAGS := -fPIC -I/usr/local/include -I$(BOOSTDIR) -Iflow -Ifdbrpc -DUSE_UCONTEXT
+FDBLibTLS_CFLAGS := -fPIC -I$(BOOSTDIR)/include -Ifdbrpc -Iflow -DUSE_UCONTEXT
 
 lib/libFDBLibTLS.a: bin/coverage.FDBLibTLS.xml
