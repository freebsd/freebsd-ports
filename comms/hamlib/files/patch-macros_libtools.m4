--- macros/libtool.m4.orig	Sun Apr  3 16:25:10 2005
+++ macros/libtool.m4	Thu Feb 22 14:24:59 2007
@@ -1300,8 +1300,8 @@
   ;;
 
 freebsd*)
-  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
-  version_type=freebsd-$objformat
+#  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
+  version_type=freebsd-elf
   case $version_type in
     freebsd-elf*)
       library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
