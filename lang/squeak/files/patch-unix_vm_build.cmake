--- unix/vm/build.cmake.orig	2012-09-17 01:03:14 UTC
+++ unix/vm/build.cmake
@@ -90,4 +90,4 @@ ADD_CUSTOM_TARGET (squeak.1
   COMMAND sh ${bld}/config ${unix}/doc/squeak.1 ${bld}/squeak.1
 )
 ADD_DEPENDENCIES (squeakvm${scriptsuffix} squeak.1)
-INSTALL (FILES ${bld}/squeak.1 DESTINATION share/man/man1)
+INSTALL (FILES ${bld}/squeak.1 DESTINATION man/man1)
