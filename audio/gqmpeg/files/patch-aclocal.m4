
$FreeBSD$

--- aclocal.m4.orig	Wed Jul 17 20:48:30 2002
+++ aclocal.m4	Thu Jul 18 16:38:49 2002
@@ -545,7 +545,7 @@
   rm -f conf.gdk_pixbuftest
 ])
 
-# gettext.m4 serial 13 (gettext-0.11.1)
+# gettext.m4 serial 14 (gettext-0.11.2)
 dnl Copyright (C) 1995-2002 Free Software Foundation, Inc.
 dnl This file is free software, distributed under the terms of the GNU
 dnl General Public License.  As a special exception to the GNU General
@@ -689,14 +689,13 @@
             dnl Now see whether libintl exists and does not depend on libiconv.
             AC_TRY_LINK([#include <libintl.h>
 extern int _nl_msg_cat_cntr;
-extern int *_nl_domain_bindings;
 extern
 #ifdef __cplusplus
 "C"
 #endif
 const char *_nl_expand_alias ();],
               [bindtextdomain ("", "");
-return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_domain_bindings + *_nl_expand_alias (0)],
+return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
               gt_cv_func_gnugettext_libintl=yes,
               gt_cv_func_gnugettext_libintl=no)
             dnl Now see whether libintl exists and depends on libiconv.
@@ -704,14 +703,13 @@
               LIBS="$LIBS $LIBICONV"
               AC_TRY_LINK([#include <libintl.h>
 extern int _nl_msg_cat_cntr;
-extern int *_nl_domain_bindings;
 extern
 #ifdef __cplusplus
 "C"
 #endif
 const char *_nl_expand_alias ();],
                 [bindtextdomain ("", "");
-return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_domain_bindings + *_nl_expand_alias (0)],
+return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
                [LIBINTL="$LIBINTL $LIBICONV"
                 LTLIBINTL="$LTLIBINTL $LTLIBICONV"
                 gt_cv_func_gnugettext_libintl=yes
