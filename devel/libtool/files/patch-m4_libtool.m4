--- m4/libtool.m4.orig	2013-10-25 23:37:46 UTC
+++ m4/libtool.m4
@@ -2547,7 +2547,8 @@ freebsd* | dragonfly*)
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
-      library_names_spec='$libname$release$shared_ext$versuffix $libname$release$shared_ext $libname$shared_ext'
+      library_names_spec='$libname$release$shared_ext$versuffix $libname$release$shared_ext$major $libname$shared_ext'
+      soname_spec='$libname$release$shared_ext$major'
       need_version=no
       need_lib_prefix=no
       ;;
