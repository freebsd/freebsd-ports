--- ./advance/advance.mak.orig	Sun Dec 11 10:10:33 2005
+++ ./advance/advance.mak	Sat Jan 20 17:02:36 2007
@@ -24,8 +24,6 @@
 ifneq ($(wildcard $(EMUSRC)),)
 INSTALL_DIRS += $(OBJ)
 INSTALL_BINFILES += $(OBJ)/$(EMUNAME)$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advmame.1
-INSTALL_MANFILES += $(DOCOBJ)/advdev.1
 ifeq ($(CONF_EMU),mame)
 INSTALL_DATAFILES += $(srcdir)/support/event.dat
 INSTALL_DATAFILES += $(srcdir)/support/history.dat
@@ -42,40 +40,6 @@
 INSTALL_BINFILES += $(MENUOBJ)/advmenu$(EXE)
 INSTALL_MANFILES += $(DOCOBJ)/advmenu.1
 endif
-ifeq ($(CONF_LIB_DIRECT),yes)
-ifneq ($(wildcard $(srcdir)/advance/cfg.mak),)
-INSTALL_DIRS += $(CFGOBJ)
-INSTALL_BINFILES += $(CFGOBJ)/advcfg$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advcfg.1
-endif
-ifneq ($(wildcard $(srcdir)/advance/v.mak),)
-INSTALL_DIRS += $(VOBJ)
-INSTALL_BINFILES += $(VOBJ)/advv$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advv.1
-endif
-endif
-ifneq ($(CONF_SYSTEM),windows)
-ifneq ($(wildcard $(srcdir)/advance/s.mak),)
-INSTALL_DIRS += $(SOBJ)
-INSTALL_BINFILES += $(SOBJ)/advs$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advs.1
-endif
-ifneq ($(wildcard $(srcdir)/advance/k.mak),)
-INSTALL_DIRS += $(KOBJ)
-INSTALL_BINFILES += $(KOBJ)/advk$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advk.1
-endif
-ifneq ($(wildcard $(srcdir)/advance/j.mak),)
-INSTALL_DIRS += $(JOBJ)
-INSTALL_BINFILES += $(JOBJ)/advj$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advj.1
-endif
-ifneq ($(wildcard $(srcdir)/advance/m.mak),)
-INSTALL_DIRS += $(MOBJ)
-INSTALL_BINFILES += $(MOBJ)/advm$(EXE)
-INSTALL_MANFILES += $(DOCOBJ)/advm.1
-endif
-endif
 
 INSTALL_DOCFILES += $(subst $(srcdir)/doc/,$(DOCOBJ)/,$(subst .d,.txt,$(wildcard $(srcdir)/doc/*.d)))
 INSTALL_DOCFILES += $(subst $(srcdir)/doc/,$(DOCOBJ)/,$(subst .d,.html,$(wildcard $(srcdir)/doc/*.d)))
@@ -288,8 +252,8 @@
 ############################################################################
 # Common install
 
-pkgdir = $(datadir)/advance
-pkgdocdir = $(docdir)/advance
+pkgdir = $(datadir)/advancemess
+pkgdocdir = $(docdir)/advancemess
 
 install-dirs:
 	-$(INSTALL_PROGRAM_DIR) $(bindir)
