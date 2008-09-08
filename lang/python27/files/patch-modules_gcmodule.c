--- Include/pymem.h.orig	2008-02-14 11:26:18.000000000 +0000
+++ Include/pymem.h	2008-08-30 10:39:43.000000000 +0100
@@ -67,8 +67,12 @@
    for malloc(0), which would be treated as an error. Some platforms
    would return a pointer with no memory behind it, which would break
    pymalloc. To solve these problems, allocate an extra byte. */
-#define PyMem_MALLOC(n)         malloc((n) ? (n) : 1)
-#define PyMem_REALLOC(p, n)     realloc((p), (n) ? (n) : 1)
+/* Returns NULL to indicate error if a negative size or size larger than
+   Py_ssize_t can represent is supplied.  Helps prevents security holes. */
+#define PyMem_MALLOC(n)		(((n) < 0 || (n) > PY_SSIZE_T_MAX) ? NULL \
+				: malloc((n) ? (n) : 1))
+#define PyMem_REALLOC(p, n)	(((n) < 0 || (n) > PY_SSIZE_T_MAX) ? NULL \
+				: realloc((p), (n) ? (n) : 1))
 #define PyMem_FREE		free
 
 #endif	/* PYMALLOC_DEBUG */
@@ -77,24 +81,31 @@
  * Type-oriented memory interface
  * ==============================
  *
- * These are carried along for historical reasons.  There's rarely a good
- * reason to use them anymore (you can just as easily do the multiply and
- * cast yourself).
+ * Allocate memory for n objects of the given type.  Returns a new pointer
+ * or NULL if the request was too large or memory allocation failed.  Use
+ * these macros rather than doing the multiplication yourself so that proper
+ * overflow checking is always done.
  */
 
 #define PyMem_New(type, n) \
-  ( assert((n) <= PY_SIZE_MAX / sizeof(type)) , \
+  ( ((n) > PY_SSIZE_T_MAX / sizeof(type)) ? NULL : \
 	( (type *) PyMem_Malloc((n) * sizeof(type)) ) )
 #define PyMem_NEW(type, n) \
-  ( assert((n) <= PY_SIZE_MAX / sizeof(type)) , \
+  ( ((n) > PY_SSIZE_T_MAX / sizeof(type)) ? NULL : \
 	( (type *) PyMem_MALLOC((n) * sizeof(type)) ) )
 
+/*
+ * The value of (p) is always clobbered by this macro regardless of success.
+ * The caller MUST check if (p) is NULL afterwards and deal with the memory
+ * error if so.  This means the original value of (p) MUST be saved for the
+ * caller's memory error handler to not lose track of it.
+ */
 #define PyMem_Resize(p, type, n) \
-  ( assert((n) <= PY_SIZE_MAX / sizeof(type)) , \
-	( (p) = (type *) PyMem_Realloc((p), (n) * sizeof(type)) ) )
+  ( (p) = ((n) > PY_SSIZE_T_MAX / sizeof(type)) ? NULL : \
+	(type *) PyMem_Realloc((p), (n) * sizeof(type)) )
 #define PyMem_RESIZE(p, type, n) \
-  ( assert((n) <= PY_SIZE_MAX / sizeof(type)) , \
-	( (p) = (type *) PyMem_REALLOC((p), (n) * sizeof(type)) ) )
+  ( (p) = ((n) > PY_SSIZE_T_MAX / sizeof(type)) ? NULL : \
+	(type *) PyMem_REALLOC((p), (n) * sizeof(type)) )
 
 /* PyMem{Del,DEL} are left over from ancient days, and shouldn't be used
  * anymore.  They're just confusing aliases for PyMem_{Free,FREE} now.
