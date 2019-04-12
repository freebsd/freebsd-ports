--- fdbcli/local.mk.orig	2019-04-09 00:11:05 UTC
+++ fdbcli/local.mk
@@ -31,9 +31,11 @@ ifeq ($(PLATFORM),linux)
   fdbcli_LDFLAGS += -static-libstdc++ -static-libgcc -lpthread -lrt -ldl
 else ifeq ($(PLATFORM),osx)
   fdbcli_LDFLAGS += -lc++
+else ifeq ($(PLATFORM),freebsd)
+  fdbcli_LDFLAGS += -lc++ -lm -lpthread -leio -lexecinfo -lboost_system
 endif
 
 test_fdbcli_status: fdbcli
-	python scripts/test_status.py
+	$(PYTHON) scripts/test_status.py
 
 bin/fdbcli.debug: bin/fdbcli
