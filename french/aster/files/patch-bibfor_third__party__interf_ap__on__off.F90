--- bibfor/third_party_interf/ap_on_off.F90.orig	2026-09-11 16:05:37 UTC
+++ bibfor/third_party_interf/ap_on_off.F90
@@ -56,7 +56,10 @@ subroutine ap_on_off(action, option)
 !     Variables PETSc
     PetscErrorCode :: ierr
     PetscScalar :: sbid
+#if PETSC_VERSION_LT(3,26,0)
+! PetscOffset removed in PETSc-3.26 (maybe before?)
     PetscOffset :: offbid
+#endif
     PetscReal :: rbid
     PetscBool :: done
 
@@ -82,7 +85,10 @@ subroutine ap_on_off(action, option)
 !        -- quelques verifications sur la coherence Aster / Petsc :
         ASSERT(kind(rbid) .eq. kind(r8))
         ASSERT(kind(sbid) .eq. kind(r8))
+#if PETSC_VERSION_LT(3,26,0)
+! No more PetscOffset in 3.26
         ASSERT(kind(offbid) .eq. kind(np))
+#endif
 !
         ier2 = 0
         call aster_petsc_initialize(option, ier2)
