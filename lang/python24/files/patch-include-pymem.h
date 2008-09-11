--- Include/pymem.h.orig	2008-03-02 20:20:32.000000000 +0100
+++ Include/pymem.h
@@ -66,8 +66,12 @@ PyAPI_FUNC(void) PyMem_Free(void *);
    for malloc(0), which would be treated as an error. Some platforms
    would return a pointer with no memory behind it, which would break
    pymalloc. To solve these problems, allocate an extra byte. */
-#define PyMem_MALLOC(n)         malloc((n) ? (n) : 1)
-#define PyMem_REALLOC(p, n)     realloc((p), (n) ? (n) : 1)
+/* Returns NULL to indicate error if a negative size or size larger than
+   Py_ssize_t can represent is supplied.  Helps prevents security holes. */
+#define PyMem_MALLOC(n)		(((n) < 0 || (n) > INT_MAX) ? NULL \
+				: malloc((n) ? (n) : 1))
+#define PyMem_REALLOC(p, n)	(((n) < 0 || (n) > INT_MAX) ? NULL \
+				: realloc((p), (n) ? (n) : 1))
 
 #endif	/* PYMALLOC_DEBUG */
 
@@ -80,24 +84,31 @@ PyAPI_FUNC(void) PyMem_Free(void *);
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
+  ( ((n) > INT_MAX / sizeof(type)) ? NULL : \
 	( (type *) PyMem_Malloc((n) * sizeof(type)) ) )
 #define PyMem_NEW(type, n) \
-  ( assert((n) <= PY_SIZE_MAX / sizeof(type)) , \
+  ( ((n) > INT_MAX / sizeof(type)) ? NULL : \
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
+  ( (p) = ((n) > INT_MAX / sizeof(type)) ? NULL : \
+	(type *) PyMem_Realloc((p), (n) * sizeof(type)) )
 #define PyMem_RESIZE(p, type, n) \
-  ( assert((n) <= PY_SIZE_MAX / sizeof(type)) , \
-	( (p) = (type *) PyMem_REALLOC((p), (n) * sizeof(type)) ) )
+  ( (p) = ((n) > INT_MAX / sizeof(type)) ? NULL : \
+	(type *) PyMem_REALLOC((p), (n) * sizeof(type)) )
 
 /* In order to avoid breaking old code mixing PyObject_{New, NEW} with
    PyMem_{Del, DEL} and PyMem_{Free, FREE}, the PyMem "release memory"
