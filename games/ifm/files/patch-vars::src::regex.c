--- vars/src/regex.c.orig	Fri Dec  3 16:43:02 2004
+++ vars/src/regex.c	Fri Jan 14 23:10:53 2005
@@ -57,7 +57,7 @@
 
 /* For platform which support the ISO C amendement 1 functionality we
    support user defined character classes.  */
-#if defined _LIBC || (defined HAVE_WCTYPE_H && defined HAVE_WCHAR_H)
+#if !defined(__FreeBSD__) && (defined _LIBC || (defined HAVE_WCTYPE_H && defined HAVE_WCHAR_H))
 # include <wctype.h>
 # include <wchar.h>
 #endif
@@ -1690,7 +1690,7 @@
        } 								\
     }
 
-#if defined _LIBC || (defined HAVE_WCTYPE_H && defined HAVE_WCHAR_H)
+#if !defined(__FreeBSD__) && (defined _LIBC || (defined HAVE_WCTYPE_H && defined HAVE_WCHAR_H))
 /* The GNU C library provides support for user-defined character classes
    and the functions from ISO C amendement 1.  */
 # ifdef CHARCLASS_NAME_MAX
@@ -2190,7 +2190,7 @@
                        the leading `:' and `[' (but set bits for them).  */
                     if (c == ':' && *p == ']')
                       {
-#if defined _LIBC || (defined HAVE_WCTYPE_H && defined HAVE_WCHAR_H)
+#if !defined(__FreeBSD__) && (defined _LIBC || (defined HAVE_WCTYPE_H && defined HAVE_WCHAR_H))
                         boolean is_lower = STREQ (str, "lower");
                         boolean is_upper = STREQ (str, "upper");
 			wctype_t wt;
