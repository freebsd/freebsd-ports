
$FreeBSD$

--- aclocal.m4.orig	Sun Apr 28 07:34:23 2002
+++ aclocal.m4	Sun Jul  7 21:56:31 2002
@@ -853,7 +853,7 @@
   ]
 )
 
-# gettext.m4 serial 13 (gettext-0.11.1)
+# gettext.m4 serial 14 (gettext-0.11.2)
 dnl Copyright (C) 1995-2002 Free Software Foundation, Inc.
 dnl This file is free software, distributed under the terms of the GNU
 dnl General Public License.  As a special exception to the GNU General
@@ -997,14 +997,13 @@
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
@@ -1012,14 +1011,13 @@
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
