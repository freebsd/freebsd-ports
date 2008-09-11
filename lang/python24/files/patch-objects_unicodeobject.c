--- Objects/unicodeobject.c.orig	2006-10-05 20:08:58.000000000 +0200
+++ Objects/unicodeobject.c
@@ -186,6 +186,11 @@ PyUnicodeObject *_PyUnicode_New(int leng
         return unicode_empty;
     }
 
+    /* Ensure we won't overflow the size. */
+    if (length > ((INT_MAX / sizeof(Py_UNICODE)) - 1)) {
+        return (PyUnicodeObject *)PyErr_NoMemory();
+    }
+
     /* Unicode freelist & memory allocation */
     if (unicode_freelist) {
         unicode = unicode_freelist;
@@ -1040,6 +1045,9 @@ PyObject *PyUnicode_EncodeUTF7(const Py_
     char * out;
     char * start;
 
+    if (cbAllocated / 5 != size)
+        return PyErr_NoMemory();
+
     if (size == 0)
 		return PyString_FromStringAndSize(NULL, 0);
 
@@ -1638,6 +1646,7 @@ PyUnicode_EncodeUTF16(const Py_UNICODE *
 {
     PyObject *v;
     unsigned char *p;
+    int nsize, bytesize;
 #ifdef Py_UNICODE_WIDE
     int i, pairs;
 #else
@@ -1662,8 +1671,15 @@ PyUnicode_EncodeUTF16(const Py_UNICODE *
 	if (s[i] >= 0x10000)
 	    pairs++;
 #endif
-    v = PyString_FromStringAndSize(NULL,
-		  2 * (size + pairs + (byteorder == 0)));
+    /* 2 * (size + pairs + (byteorder == 0)) */
+    if (size > INT_MAX ||
+	size > INT_MAX - pairs - (byteorder == 0))
+	return PyErr_NoMemory();
+    nsize = (size + pairs + (byteorder == 0));
+    bytesize = nsize * 2;
+    if (bytesize / 2 != nsize)
+	return PyErr_NoMemory();
+    v = PyString_FromStringAndSize(NULL, bytesize);
     if (v == NULL)
         return NULL;
 
@@ -1977,6 +1993,11 @@ PyObject *unicodeescape_string(const Py_
     char *p;
 
     static const char *hexdigit = "0123456789abcdef";
+#ifdef Py_UNICODE_WIDE
+    const int expandsize = 10;
+#else
+    const int expandsize = 6;
+#endif
 
     /* Initial allocation is based on the longest-possible unichr
        escape.
@@ -1992,13 +2013,12 @@ PyObject *unicodeescape_string(const Py_
        escape.
     */
 
+    if (size > (INT_MAX - 2 - 1) / expandsize)
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
@@ -2239,12 +2259,16 @@ PyObject *PyUnicode_EncodeRawUnicodeEsca
     char *q;
 
     static const char *hexdigit = "0123456789abcdef";
-
 #ifdef Py_UNICODE_WIDE
-    repr = PyString_FromStringAndSize(NULL, 10 * size);
+    const int expandsize = 10;
 #else
-    repr = PyString_FromStringAndSize(NULL, 6 * size);
+    const int expandsize = 6;
 #endif
+    
+    if (size > INT_MAX / expandsize)
+	return PyErr_NoMemory();
+    
+    repr = PyString_FromStringAndSize(NULL, expandsize * size);
     if (repr == NULL)
         return NULL;
     if (size == 0)
@@ -4289,6 +4313,11 @@ PyUnicodeObject *pad(PyUnicodeObject *se
         return self;
     }
 
+    if (left > INT_MAX - self->length ||
+	right > INT_MAX - (left + self->length)) {
+        PyErr_SetString(PyExc_OverflowError, "padded string is too long");
+        return NULL;
+    }
     u = _PyUnicode_New(left + self->length + right);
     if (u) {
         if (left)
