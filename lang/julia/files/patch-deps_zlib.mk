--- deps/zlib.mk.orig	2026-10-25 17:06:47 UTC
+++ deps/zlib.mk
@@ -9,6 +9,7 @@ $(BUILDDIR)/$(ZLIB_SRC_DIR)/build-configured: $(SRCCAC
 ZLIB_BUILD_OPTS += -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DZLIB_BUILD_TESTING=OFF -DZLIB_BUILD_STATIC=OFF
 
 $(BUILDDIR)/$(ZLIB_SRC_DIR)/build-configured: $(SRCCACHE)/$(ZLIB_SRC_DIR)/source-extracted
+	sed -i.bak -e '/gz_intmax;/d' $(SRCCACHE)/$(ZLIB_SRC_DIR)/zlib.map
 	mkdir -p $(dir $@)
 	cd $(dir $@) && $(CMAKE) -G"Unix Makefiles" $(ZLIB_BUILD_OPTS) $(dir $<)
 	echo 1 > $@
