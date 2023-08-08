--- src/Mod/Part/App/OCCError.h.orig	2022-12-06 23:30:48.794152000 +0100
+++ src/Mod/Part/App/OCCError.h	2022-12-06 23:31:40.841019000 +0100
@@ -50,7 +50,9 @@
 # include <Standard_Overflow.hxx>
 # include <Standard_ProgramError.hxx>
 # include <Standard_RangeError.hxx>
+# if OCC_VERSION_HEX <= 0x070600
 # include <Standard_TooManyUsers.hxx>
+# endif
 # include <Standard_TypeMismatch.hxx>
 # include <Standard_Underflow.hxx>
 
