--- include/Inventor/SbBasic.h.orig	2010-03-02 13:20:09 UTC
+++ include/Inventor/SbBasic.h
@@ -88,17 +88,24 @@ inline Type SbSqr(const Type val) {
 // warning if so for debug builds.  inlined like this to not take much
 // screenspace in inline functions.
 
-// cc_debugerror_post() is not attempted resolved before the template is
-// used, hence the missing Inventor/errors/SoDebugError.h #include. This
-// "trick" does only work *portably* for functions in the global namespace.
+// Missing include for cc_debugerror_post() added here. The previous "trick"
+// for not needing to resolve symbols in global namespace no longer works
+// with newer compilers.
+#ifndef NDEBUG
+#include <Inventor/C/errors/debugerror.h>
+#endif // !NDEBUG
 
+
+#ifndef NDEBUG
 template <typename Type>
 inline void SbDividerChk(const char * funcname, Type divider) {
-#ifndef NDEBUG
   if (!(divider != static_cast<Type>(0)))
     cc_debugerror_post(funcname, "divide by zero error.", divider);
-#endif // !NDEBUG
 }
+#else
+template <typename Type>
+inline void SbDividerChk(const char *, Type) {}
+#endif // !NDEBUG
 
 /* ********************************************************************** */
 
