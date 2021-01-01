--- deps/blas.mk.orig	2018-08-07 16:34:08 UTC
+++ deps/blas.mk
@@ -94,6 +94,14 @@ OPENBLAS_BUILD_OPTS += MAKE_NB_JOBS=0
 
 $(BUILDDIR)/$(OPENBLAS_SRC_DIR)/build-configured: $(BUILDDIR)/$(OPENBLAS_SRC_DIR)/source-extracted
 	perl -i -ple 's/^\s*(EXTRALIB\s*\+=\s*-lSystemStubs)\s*$$/# $$1/g' $(dir $<)/Makefile.system
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
