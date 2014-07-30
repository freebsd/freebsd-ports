--- unix/vm/build.cmake.orig	2013-06-09 22:54:13.000000000 +0200
+++ unix/vm/build.cmake	2013-06-09 22:55:18.000000000 +0200
@@ -90,4 +90,4 @@
   COMMAND sh ${bld}/config ${unix}/doc/squeak.1 ${bld}/squeak.1
 )
 ADD_DEPENDENCIES (squeakvm${scriptsuffix} squeak.1)
-INSTALL (FILES ${bld}/squeak.1 DESTINATION share/man/man1)
+INSTALL (FILES ${bld}/squeak.1 DESTINATION man/man1)
