--- deps/suitesparse.mk.orig	2016-09-20 02:54:21 UTC
+++ deps/suitesparse.mk
@@ -93,7 +93,7 @@ install-suitesparse: $(SUITESPARSE_OBJ_T
 # SUITESPARSE WRAPPER
 
 ifeq ($(USE_SYSTEM_SUITESPARSE), 1)
-SUITESPARSE_INC := -I /usr/include/suitesparse
+SUITESPARSE_INC := -I $(LOCALBASE)/include/suitesparse
 SUITESPARSE_LIB := -lumfpack -lcholmod -lamd -lcamd -lcolamd -lspqr
 else
 SUITESPARSE_INC := -I $(BUILDDIR)/SuiteSparse-$(SUITESPARSE_VER)/CHOLMOD/Include -I $(BUILDDIR)/SuiteSparse-$(SUITESPARSE_VER)/SuiteSparse_config -I $(BUILDDIR)/SuiteSparse-$(SUITESPARSE_VER)/SPQR/Include
