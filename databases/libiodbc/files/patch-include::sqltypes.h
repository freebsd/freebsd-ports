--- include/sqltypes.h.orig	Sun Oct  7 22:44:49 2007
+++ include/sqltypes.h	Sat Oct 20 01:06:36 2007
@@ -399,6 +399,7 @@
       defined(_WCHAR_T_DEFINED)		|| \
       defined(_WCHAR_T_DEFINED_)	|| \
       defined(_WCHAR_T_DECLARED)	|| \
+      defined(__FreeBSD__)		|| \
       defined(_BSD_WCHAR_T_DEFINED_)	|| \
       defined(_BSD_WCHAR_T_)		|| \
       defined(_BSD_CT_RUNE_T_)
