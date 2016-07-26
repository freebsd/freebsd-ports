--- lib/compat/gettext.h.orig	2015-11-25 21:45:14 UTC
+++ lib/compat/gettext.h
@@ -53,7 +53,6 @@
    <libintl.h>, which chokes if dcgettext is defined as a macro.  So include
    it now, to make later inclusions of <libintl.h> a NOP.  */
 #if defined(__cplusplus) && defined(__GNUG__) && (__GNUC__ >= 3)
-# include <cstdlib>
 # if (__GLIBC__ >= 2 && !defined __UCLIBC__) || _GLIBCXX_HAVE_LIBINTL_H
 #  include <libintl.h>
 # endif
