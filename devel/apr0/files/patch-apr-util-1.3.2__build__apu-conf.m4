--- apr-util-1.3.2/build/apu-conf.m4	2008/06/16 21:34:50	668323
+++ apr-util-1.3.2/build/apu-conf.m4	2008/07/08 22:31:59	675009
@@ -357,6 +357,12 @@
   ])
 
 if test "$apu_has_ldap_openldap" = "1"; then
+    save_cppflags="$CPPFLAGS"
+    save_ldflags="$LDFLAGS"
+    save_libs="$LIBS"
+
+    CPPFLAGS="$CPPFLAGS $APRUTIL_INCLUDES"
+    LDFLAGS="$LDFLAGS $APRUTIL_LDFLAGS"
     AC_CACHE_CHECK([style of ldap_set_rebind_proc routine], ac_cv_ldap_set_rebind_proc_style,
     APR_TRY_COMPILE_NO_WARNING([
     #ifdef HAVE_LBER_H
@@ -374,6 +380,10 @@
     if test "$ac_cv_ldap_set_rebind_proc_style" = "three"; then
         AC_DEFINE(LDAP_SET_REBIND_PROC_THREE, 1, [Define if ldap_set_rebind_proc takes three arguments])
     fi
+
+    CPPFLAGS="$save_cppflags"
+    LDFLAGS="$save_ldflags"
+    LIBS="$save_libs"
 fi
 
 AC_SUBST(ldap_h)
