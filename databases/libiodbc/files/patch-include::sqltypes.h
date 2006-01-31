--- include/sqltypes.h.orig	Thu Jan 26 18:50:59 2006
+++ include/sqltypes.h	Tue Jan 31 13:45:45 2006
@@ -398,6 +398,7 @@
       defined(_WCHAR_T)			|| \
       defined(_WCHAR_T_DEFINED)		|| \
       defined(_WCHAR_T_DECLARED)        || \
+      defined(__FreeBSD__)              || \
       defined(_BSD_WCHAR_T_DEFINED_)    || \
       defined(_BSD_WCHAR_T_)
 typedef wchar_t SQLWCHAR;
