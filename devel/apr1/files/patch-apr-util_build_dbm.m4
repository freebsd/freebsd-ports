--- apr-util-1.2.2/build/dbm.m4-orig	Wed Dec  7 09:02:23 2005
+++ apr-util-1.2.2/build/dbm.m4	Wed Dec 23 09:07:34 2005
@@ -588,6 +588,8 @@
     elif test "$withval" = "no"; then
       apu_have_gdbm=0
     else
+      saved_cppflags="$CPPFLAGS"
+      saved_libs="$LIBS"
       CPPFLAGS="-I$withval/include"
       LIBS="-L$withval/lib "
 
@@ -597,6 +599,9 @@
         APR_ADDTO(APRUTIL_LDFLAGS, [-L$withval/lib])
         APR_ADDTO(APRUTIL_INCLUDES, [-I$withval/include])
       fi
+
+      CPPFLAGS="$saved_cppflags"
+      LIBS="$saved_libs"
     fi
   ], [
     apu_have_gdbm=0
