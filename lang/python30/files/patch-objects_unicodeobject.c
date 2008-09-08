--- Objects/unicodeobject.c.orig	2007-11-02 22:46:38.000000000 +0000
+++ Objects/unicodeobject.c	2008-08-30 10:16:13.000000000 +0100
@@ -239,6 +239,11 @@
         return unicode_empty;
     }
 
+    /* Ensure we won't overflow the size. */
+    if (length > ((PY_SSIZE_T_MAX / sizeof(Py_UNICODE)) - 1)) {
+        return (PyUnicodeObject *)PyErr_NoMemory();
+    }
+
     /* Unicode freelist & memory allocation */
     if (unicode_freelist) {
         unicode = unicode_freelist;
@@ -1091,6 +1096,9 @@
     char * out;
     char * start;
 
+    if (cbAllocated / 5 != size)
+        return PyErr_NoMemory();
+
     if (size == 0)
 		return PyString_FromStringAndSize(NULL, 0);
 
@@ -1689,8 +1697,9 @@
 {
     PyObject *v;
     unsigned char *p;
+    Py_ssize_t nsize, bytesize;
 #ifdef Py_UNICODE_WIDE
-    int i, pairs;
+    Py_ssize_t i, pairs;
 #else
     const int pairs = 0;
 #endif
@@ -1713,8 +1722,15 @@
 	if (s[i] >= 0x10000)
 	    pairs++;
 #endif
-    v = PyString_FromStringAndSize(NULL,
-		  2 * (size + pairs + (byteorder == 0)));
+    /* 2 * (size + pairs + (byteorder == 0)) */
+    if (size > PY_SSIZE_T_MAX ||
+	size > PY_SSIZE_T_MAX - pairs - (byteorder == 0))
+	return PyErr_NoMemory();
+    nsize = (size + pairs + (byteorder == 0));
+    bytesize = nsize * 2;
+    if (bytesize / 2 != nsize)
+	return PyErr_NoMemory();
+    v = PyString_FromStringAndSize(NULL, bytesize);
     if (v == NULL)
         return NULL;
 
@@ -2042,6 +2058,11 @@
     char *p;
 
     static const char *hexdigit = "0123456789abcdef";
+#ifdef Py_UNICODE_WIDE
+    const Py_ssize_t expandsize = 10;
+#else
+    const Py_ssize_t expandsize = 6;
+#endif
 
     /* Initial allocation is based on the longest-possible unichr
        escape.
@@ -2057,13 +2078,12 @@
        escape.
     */
 
+    if (size > (PY_SSIZE_T_MAX - 2 - 1) / expandsize)
+	return PyErr_NoMemory();
+
     repr = PyString_FromStringAndSize(NULL,
         2
-#ifdef Py_UNICODE_WIDE
-        + 10*size
-#else
-        + 6*size
-#endif
+        + expandsize*size
         + 1);
     if (repr == NULL)
         return NULL;
@@ -2304,12 +2324,16 @@
     char *q;
 
     static const char *hexdigit = "0123456789abcdef";
-
 #ifdef Py_UNICODE_WIDE
-    repr = PyString_FromStringAndSize(NULL, 10 * size);
+    const Py_ssize_t expandsize = 10;
 #else
-    repr = PyString_FromStringAndSize(NULL, 6 * size);
+    const Py_ssize_t expandsize = 6;
 #endif
+
+    if (size > PY_SSIZE_T_MAX / expandsize)
+	return PyErr_NoMemory();
+
+    repr = PyString_FromStringAndSize(NULL, expandsize * size);
     if (repr == NULL)
         return NULL;
     if (size == 0)
@@ -4719,6 +4743,11 @@
         return self;
     }
 
+    if (left > PY_SSIZE_T_MAX - self->length ||
+	right > PY_SSIZE_T_MAX - (left + self->length)) {
+        PyErr_SetString(PyExc_OverflowError, "padded string is too long");
+        return NULL;
+    }
     u = _PyUnicode_New(left + self->length + right);
     if (u) {
         if (left)
