--- cmake_admin/CreateManpages.cmake.orig	2015-12-29 15:59:13 UTC
+++ cmake_admin/CreateManpages.cmake
@@ -31,5 +31,5 @@ MACRO(CREATE_MANPAGES)
     ENDFOREACH (it)
     ADD_CUSTOM_TARGET(manpages ALL DEPENDS ${outfiles})
     INSTALL ( FILES ${outfiles}
-              DESTINATION share/man/man1 )
+              DESTINATION man/man1 )
 ENDMACRO(CREATE_MANPAGES)
