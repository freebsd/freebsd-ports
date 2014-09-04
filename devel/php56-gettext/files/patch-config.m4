--- config.m4.orig	Tue Jul 27 23:58:02 2004
+++ config.m4	Tue Jul 27 23:59:44 2004
@@ -30,7 +30,6 @@
 		AC_MSG_ERROR(Unable to find required gettext library)
 	])
   )
-  LDFLAGS=$O_LDFLAGS
 
   AC_DEFINE(HAVE_LIBINTL,1,[ ])
   PHP_NEW_EXTENSION(gettext, gettext.c, $ext_shared)
@@ -46,5 +45,6 @@
   AC_CHECK_LIB($GETTEXT_CHECK_IN_LIB, dngettext,  [AC_DEFINE(HAVE_DNGETTEXT, 1, [ ])])
   AC_CHECK_LIB($GETTEXT_CHECK_IN_LIB, dcngettext,  [AC_DEFINE(HAVE_DCNGETTEXT, 1, [ ])])
   AC_CHECK_LIB($GETTEXT_CHECK_IN_LIB, bind_textdomain_codeset,  [AC_DEFINE(HAVE_BIND_TEXTDOMAIN_CODESET, 1, [ ])])
+  LDFLAGS=$O_LDFLAGS
   
 fi
