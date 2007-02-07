--- build/libtool.m4.orig	Wed Feb  7 16:51:07 2007
+++ build/libtool.m4	Wed Feb  7 16:51:49 2007
@@ -2073,7 +2073,7 @@
   ;;
 
 freebsd*)
-  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
+  objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo elf`
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
