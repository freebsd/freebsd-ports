--- acspecific.m4.orig	2000-02-27 16:18:10 UTC
+++ acspecific.m4
@@ -2681,7 +2681,7 @@ else
   if AC_TRY_EVAL(ac_link); then
     for file in conftest.*; do
       case $file in
-      *.c | *.o | *.obj | *.ilk | *.pdb) ;;
+      *.c | *.C | *.o | *.obj | *.ilk | *.pdb) ;;
       *) ac_cv_exeext=`echo $file | sed -e s/conftest//` ;;
       esac
     done
