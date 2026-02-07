--- deps/zlib.mk.orig	2023-01-18 16:25:14 UTC
+++ deps/zlib.mk
@@ -9,6 +9,7 @@ $(BUILDDIR)/$(ZLIB_SRC_DIR)/build-configured: $(SRCCAC
 ZLIB_BUILD_OPTS += -DCMAKE_POSITION_INDEPENDENT_CODE=ON
 
 $(BUILDDIR)/$(ZLIB_SRC_DIR)/build-configured: $(SRCCACHE)/$(ZLIB_SRC_DIR)/source-extracted
+	sed -i bak -e '/gz_intmax;/d' $(SRCCACHE)/$(ZLIB_SRC_DIR)/zlib.map
 	mkdir -p $(dir $@)
 	cd $(dir $@) && $(CMAKE) $(ZLIB_BUILD_OPTS) $(dir $<)
 	echo 1 > $@
