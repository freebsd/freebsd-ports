--- bibfor/third_party_interf/aster_petsc_module.F90.orig	2026-09-11 16:05:37 UTC
+++ bibfor/third_party_interf/aster_petsc_module.F90
@@ -49,6 +49,8 @@ module aster_petsc_module
 !
 ! Mat routines
 !
+! Interfaces already provided by PETSc-3.26
+#if PETSC_VERSION_LT(3,26,0)
     interface
         subroutine PCHPDDMSetAuxiliaryMat(pc, is, mat, func, ctx, ierr)
             use petsckspdef
@@ -82,6 +84,7 @@ module aster_petsc_module
             PetscErrorCode, intent(out) :: ierr
         end subroutine MatShellSetOperation
     end interface
+#endif
 !
 ! PC and KSP routines
 !
@@ -133,6 +136,8 @@ module aster_petsc_module
     !         PetscErrorCode, intent(out) :: ierr
     !     end subroutine PCShellSetDestroy
     ! end interface
+! Interface already provided by PETSc-3.26
+#if PETSC_VERSION_LT(3,26,0)
     interface
         subroutine KSPMonitorSet(ksp, mykspmonitor, vf, mydestroy, ierr)
             use petsckspdef
@@ -142,6 +147,7 @@ module aster_petsc_module
             PetscErrorCode, intent(out) :: ierr
         end subroutine KSPMonitorSet
     end interface
+#endif
     ! interface
     !     subroutine PCShellSetName(pc, myname, ierr)
     !         use petsckspdef
