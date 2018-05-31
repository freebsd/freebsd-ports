--- FDBLibTLS/local.mk.orig	2018-05-16 23:59:08 UTC
+++ FDBLibTLS/local.mk
@@ -1,6 +1,6 @@
-FDBLibTLS_CFLAGS := -fPIC -I/usr/local/include -I$(BOOSTDIR) -Ifdbrpc
-FDBLibTLS_STATIC_LIBS := -ltls -lssl -lcrypto
-FDBLibTLS_LDFLAGS := -L/usr/local/lib -static-libstdc++ -static-libgcc -lrt
+FDBLibTLS_CFLAGS := -fPIC -I/usr/local/include -I$(BOOSTDIR)/include -I../fdbrpc
+FDBLibTLS_LIBS := -lssl -lcrypto
+FDBLibTLS_LDFLAGS := -lc++
 FDBLibTLS_LDFLAGS += -Wl,-soname,FDBLibTLS.so -Wl,--version-script=FDBLibTLS/FDBLibTLS.map
 
 # The plugin isn't a typical library, so it feels more sensible to have a copy
