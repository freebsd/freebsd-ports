--- include/sqltypes.h.orig	Fri Mar 26 08:33:24 2004
+++ include/sqltypes.h	Fri Mar 26 08:33:37 2004
@@ -409,6 +409,7 @@
 #  if defined(_WCHAR_T)			|| \
       defined(_WCHAR_T_DEFINED)		|| \
       defined(_WCHAR_T_DECLARED)	|| \
+      defined(__FreeBSD__)		|| \
       defined(_BSD_WCHAR_T_DEFINED_)
 typedef wchar_t SQLWCHAR;
 #  else
