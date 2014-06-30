--- lv_defines.h.orig	2006-01-22 13:23:37.000000000 +0000
+++ libvisual/lv_defines.h	2014-06-24 19:56:46.961214708 +0100
@@ -39,14 +39,13 @@
 #endif /* __cplusplus */
 
 #ifdef NULL
-#undef NULL
+# ifndef __cplusplus
+#   define NULL ((void *) 0)
+# else
+#   define NULL 0
+# endif
 #endif
 
-/**
- * NULL define.
- */
-#define NULL	((void *) 0)
-
 #ifndef FALSE
 /**
  * FALSE define.
@@ -63,17 +62,21 @@
 
 /* Compiler specific optimalization macros */
 #if __GNUC__ >= 3
-# define inline			inline __attribute__ ((always_inline))
-# define __malloc		__attribute__ ((malloc))
-# define __packed		__attribute__ ((packed))
-# define VIS_LIKELY(x)		__builtin_expect (!!(x), 1)
-# define VIS_UNLIKELY(x)	__builtin_expect (!!(x), 0)
+# ifndef __cplusplus
+#  define inline            inline __attribute__ ((always_inline))
+# endif
+# define VIS_ATTR_MALLOC    __attribute__ ((malloc))
+# define VIS_ATTR_PACKED    __attribute__ ((packed))
+# define VIS_LIKELY(x)      __builtin_expect (!!(x), 1)
+# define VIS_UNLIKELY(x)    __builtin_expect (!!(x), 0)
 #else
-# define inline			/* no inline */
-# define __malloc		/* no malloc */
-# define __packed		/* no packed */
-# define VIS_LIKELY(x)		(x)
-# define VIS_UNLIKELY(x)	(x)
-#endif
+# ifndef __cplusplus
+#  define inline            /* no inline */
+# endif
+# define VIS_ATTR_MALLOC    /* no malloc */
+# define VIS_ATTR_PACKED    /* no packed */
+# define VIS_LIKELY(x)      (x)
+# define VIS_UNLIKELY(x)    (x)
+#endif /* __GNUC__ >= 3 */
 
 #endif /* _LV_DEFINES_H */
