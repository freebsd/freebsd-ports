--- make/template/main.mk.orig	2016-09-03 14:51:50 UTC
+++ make/template/main.mk
@@ -61,6 +61,10 @@ INSTMODE_LIB = 0644
 @IFEQ $(SYSTEM) linux
   LDLIBS += -ldl -lrt
 @ENDIF
+@IFEQ $(SYSTEM) freebsd
+  CXXFLAGS += -I/usr/local/include
+  LDFLAGS += -L/usr/local/lib
+@ENDIF
 @IFEQ $(SYSTEM) gnukfreebsd
   LDLIBS += -ldl -lrt
 @ENDIF
@@ -138,7 +142,7 @@ CXXFLAGS += -Iinclude
   CXXFLAGS += -DPURE_STATIC
 @ENDIF
 
-@DO_EXPORT RUNCC RUNLD CXXFLAGS LDLIBS PICLDFLAGS VERBOSE SOCKETENGINE CORELDFLAGS
+@DO_EXPORT RUNCC RUNLD CXXFLAGS LDLIBS PICLDFLAGS VERBOSE SOCKETENGINE CORELDFLAGS LDFLAGS
 @DO_EXPORT SOURCEPATH BUILDPATH PURE_STATIC SPLIT_CC
 
 # Default target
@@ -226,8 +230,6 @@ install: target
 		exit 1; \
 	fi
 	@-$(INSTALL) -d -o $(INSTUID) -m $(INSTMODE_DIR) $(BASE)
-	@-$(INSTALL) -d -o $(INSTUID) -m $(INSTMODE_DIR) $(DATPATH)
-	@-$(INSTALL) -d -o $(INSTUID) -m $(INSTMODE_DIR) $(LOGPATH)
 	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(BINPATH)
 	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(CONPATH)/examples/aliases
 	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(CONPATH)/examples/modules
