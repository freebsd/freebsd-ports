--- unix/vm/build.cmake.bak	2012-04-14 22:26:13.000000000 +0900
+++ unix/vm/build.cmake	2012-04-14 22:26:30.000000000 +0900
@@ -83,4 +83,4 @@
   COMMAND sh ${bld}/config ${unix}/doc/squeak.1 ${bld}/squeak.1
 )
 ADD_DEPENDENCIES (squeakvm squeak.1)
-INSTALL (FILES ${bld}/squeak.1 DESTINATION share/man/man1)
+INSTALL (FILES ${bld}/squeak.1 DESTINATION man/man1)
