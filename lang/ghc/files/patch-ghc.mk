--- ghc.mk.orig	2012-06-06 19:10:25.000000000 +0200
+++ ghc.mk	2013-01-30 16:24:02.000000000 +0100
@@ -81,6 +81,7 @@
 # Catch make if it runs away into an infinite loop
 ifeq      "$(MAKE_RESTARTS)" ""
 else ifeq "$(MAKE_RESTARTS)" "1"
+else ifeq "$(MAKE_RESTARTS)" "2"
 else
 $(error Make has restarted itself $(MAKE_RESTARTS) times; is there a makefile bug?)
 endif
@@ -574,12 +575,18 @@
    $(GHC_GENPRIMOP_DIR)
 endif
 
+ifeq "$(UseSystemLibFFI)" "YES"
+MAYBE_LIBFFI=
+else
+MAYBE_LIBFFI=libffi
+endif
+
 BUILD_DIRS += \
    driver \
    driver/ghci \
    driver/ghc \
    driver/haddock \
-   libffi \
+   $(MAYBE_LIBFFI) \
    includes \
    rts
 
@@ -971,6 +978,7 @@
 	echo "BUILD_DOCBOOK_PDF  = $(BUILD_DOCBOOK_PDF)"  >> $(BIN_DIST_MK)
 	echo "BUILD_MAN          = $(BUILD_MAN)"          >> $(BIN_DIST_MK)
 	echo "GHC_CABAL_INPLACE  = utils/ghc-cabal/dist-install/build/tmp/ghc-cabal" >> $(BIN_DIST_MK)
+	echo "UseSystemLibFFI    = $(UseSystemLibFFI)"    >> $(BIN_DIST_MK)
 	cd $(BIN_DIST_PREP_DIR) && autoreconf
 	$(call removeFiles,$(BIN_DIST_PREP_TAR))
 # h means "follow symlinks", e.g. if aclocal.m4 is a symlink to a source
