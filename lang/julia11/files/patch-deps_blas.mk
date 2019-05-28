--- deps/blas.mk.orig	2019-01-13 00:25:11 UTC
+++ deps/blas.mk
@@ -95,6 +95,14 @@ OPENBLAS_BUILD_OPTS += MAKE_NB_JOBS=0
 ifneq ($(USE_BINARYBUILDER_OPENBLAS), 1)
 
 $(BUILDDIR)/$(OPENBLAS_SRC_DIR)/build-configured: $(BUILDDIR)/$(OPENBLAS_SRC_DIR)/source-extracted
+	cd $(BUILDDIR)/$(OPENBLAS_SRC_DIR) && \
+		patch -p1 -f < $(SRCDIR)/patches/openblas-fix-arch.patch
+	/usr/bin/sed -i.bak -e "s+(ARCH)+(AR)+" \
+		$(BUILDDIR)/$(OPENBLAS_SRC_DIR)/lapack-netlib/SRC/Makefile \
+		$(BUILDDIR)/$(OPENBLAS_SRC_DIR)/lapack-netlib/SRC/VARIANTS/Makefile \
+		$(BUILDDIR)/$(OPENBLAS_SRC_DIR)/lapack-netlib/TESTING/MATGEN/Makefile \
+		$(BUILDDIR)/$(OPENBLAS_SRC_DIR)/lapack-netlib/LAPACKE/src/Makefile \
+		$(BUILDDIR)/$(OPENBLAS_SRC_DIR)/lapack-netlib/LAPACKE/utils/Makefile
 	echo 1 > $@
 
 $(BUILDDIR)/$(OPENBLAS_SRC_DIR)/build-compiled: $(BUILDDIR)/$(OPENBLAS_SRC_DIR)/build-configured
