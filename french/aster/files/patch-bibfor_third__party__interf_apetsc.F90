--- bibfor/third_party_interf/apetsc.F90.orig	2026-09-11 16:05:37 UTC
+++ bibfor/third_party_interf/apetsc.F90
@@ -103,7 +103,10 @@ subroutine apetsc(action, solvez, matasz, rsolu, vcine
 !     Variables PETSc
     PetscErrorCode :: ierr
     PetscScalar :: sbid
+#if PETSC_VERSION_LT(3,26,0)
+! PetscOffset removed in PETSc-3.26 (maybe before?)
     PetscOffset :: offbid
+#endif
     PetscReal :: rbid
     PetscBool :: initialized
     blas_int :: b_incx, b_incy, b_n
@@ -157,7 +160,10 @@ subroutine apetsc(action, solvez, matasz, rsolu, vcine
 !        -- quelques verifications sur la coherence Aster / Petsc :
         ASSERT(kind(rbid) .eq. kind(r8))
         ASSERT(kind(sbid) .eq. kind(r8))
+#if PETSC_VERSION_LT(3,26,0)
+! No more PetscOffset in 3.26
         ASSERT(kind(offbid) .eq. kind(np))
+#endif
 !
         ier2 = 0
         call aster_petsc_initialize(myopt, ier2)
