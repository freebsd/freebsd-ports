--- ginclude/stddef.h.orig	Sat Aug 19 13:39:22 1995
+++ ginclude/stddef.h	Mon Mar 20 13:29:13 2000
@@ -257,7 +257,7 @@
 
 /*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
     are already defined.  */
-#ifdef _ANSI_H_
+#if defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_)
 /*  The references to _GCC_PTRDIFF_T_, _GCC_SIZE_T_, and _GCC_WCHAR_T_
     are probably typos and should be removed before 2.8 is released.  */
 #ifdef _GCC_PTRDIFF_T_
@@ -285,7 +285,7 @@
 #undef _WCHAR_T_
 #undef _BSD_WCHAR_T_
 #endif
-#endif /* _ANSI_H_ */
+#endif /* defined(_ANSI_H_) || defined(_MACHINE_ANSI_H_) */
 
 #endif /* __sys_stdtypes_h */
 
