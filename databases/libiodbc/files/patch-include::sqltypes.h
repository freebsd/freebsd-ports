--- include/sqltypes.h.orig	Wed Sep 29 19:14:06 2004
+++ include/sqltypes.h	Sat Nov 13 15:26:42 2004
@@ -387,6 +387,7 @@
 #  if defined(_WCHAR_T)			|| \
       defined(_WCHAR_T_DEFINED)		|| \
       defined(_WCHAR_T_DECLARED)        || \
+      defined(__FreeBSD__)              || \
       defined(_BSD_WCHAR_T_DEFINED_)
 typedef wchar_t SQLWCHAR;
 #  else
