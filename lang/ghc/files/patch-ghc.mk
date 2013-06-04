--- ghc.mk.orig	2013-04-18 23:22:46.000000000 +0200
+++ ghc.mk	2013-04-29 20:42:16.000000000 +0200
@@ -80,6 +80,7 @@
 # Catch make if it runs away into an infinite loop
 ifeq      "$(MAKE_RESTARTS)" ""
 else ifeq "$(MAKE_RESTARTS)" "1"
+else ifeq "$(MAKE_RESTARTS)" "2"
 else
 $(error Make has restarted itself $(MAKE_RESTARTS) times; is there a makefile bug?)
 endif
@@ -595,12 +596,18 @@
 MAYBE_GHCI=driver/ghci
 endif
 
+ifeq "$(UseSystemLibFFI)" "YES"
+MAYBE_LIBFFI=
+else
+MAYBE_LIBFFI=libffi
+endif
+
 BUILD_DIRS += \
    driver \
    $(MAYBE_GHCI) \
    driver/ghc \
    driver/haddock \
-   libffi \
+   $(MAYBE_LIBFFI) \
    includes \
    rts
 
@@ -1005,6 +1012,7 @@
 	echo "BUILD_DOCBOOK_PDF  = $(BUILD_DOCBOOK_PDF)"  >> $(BIN_DIST_MK)
 	echo "BUILD_MAN          = $(BUILD_MAN)"          >> $(BIN_DIST_MK)
 	echo "GHC_CABAL_INPLACE  = utils/ghc-cabal/dist-install/build/tmp/ghc-cabal" >> $(BIN_DIST_MK)
+	echo "UseSystemLibFFI    = $(UseSystemLibFFI)"    >> $(BIN_DIST_MK)
 	cd $(BIN_DIST_PREP_DIR) && autoreconf
 	$(call removeFiles,$(BIN_DIST_PREP_TAR))
 # h means "follow symlinks", e.g. if aclocal.m4 is a symlink to a source
