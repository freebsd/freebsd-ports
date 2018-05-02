--- fdbmonitor/local.mk.orig	2018-04-26 01:54:14 UTC
+++ fdbmonitor/local.mk
@@ -27,6 +27,8 @@ ifeq ($(PLATFORM),linux)
   fdbmonitor_LDFLAGS := -static-libstdc++ -static-libgcc -lrt
 else ifeq ($(PLATFORM),osx)
   fdbmonitor_LDFLAGS := -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbmonitor_LDFLAGS := -lc++ -lm
 endif
 
 bin/fdbmonitor.debug: bin/fdbmonitor
