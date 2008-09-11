--- Python/mysnprintf.c.orig	2001-12-21 17:32:15.000000000 +0100
+++ Python/mysnprintf.c
@@ -54,18 +54,28 @@ int
 PyOS_vsnprintf(char *str, size_t size, const char  *format, va_list va)
 {
 	int len;  /* # bytes written, excluding \0 */
-#ifndef HAVE_SNPRINTF
+#ifdef HAVE_SNPRINTF
+#define _PyOS_vsnprintf_EXTRA_SPACE 1
+#else
+#define _PyOS_vsnprintf_EXTRA_SPACE 512
 	char *buffer;
 #endif
 	assert(str != NULL);
 	assert(size > 0);
 	assert(format != NULL);
+	/* We take a size_t as input but return an int.  Sanity check
+	 * our input so that it won't cause an overflow in the
+         * vsnprintf return value or the buffer malloc size.  */
+	if (size > INT_MAX - _PyOS_vsnprintf_EXTRA_SPACE) {
+		len = -666;
+		goto Done;
+	}
 
 #ifdef HAVE_SNPRINTF
 	len = vsnprintf(str, size, format, va);
 #else
 	/* Emulate it. */
-	buffer = PyMem_MALLOC(size + 512);
+	buffer = PyMem_MALLOC(size + _PyOS_vsnprintf_EXTRA_SPACE);
 	if (buffer == NULL) {
 		len = -666;
 		goto Done;
@@ -75,7 +85,7 @@ PyOS_vsnprintf(char *str, size_t size, c
 	if (len < 0)
 		/* ignore the error */;
 
-	else if ((size_t)len >= size + 512)
+	else if ((size_t)len >= size + _PyOS_vsnprintf_EXTRA_SPACE)
 		Py_FatalError("Buffer overflow in PyOS_snprintf/PyOS_vsnprintf");
 
 	else {
@@ -86,8 +96,10 @@ PyOS_vsnprintf(char *str, size_t size, c
 		str[to_copy] = '\0';
 	}
 	PyMem_FREE(buffer);
-Done:
 #endif
-	str[size-1] = '\0';
+Done:
+	if (size > 0)
+		str[size-1] = '\0';
 	return len;
+#undef _PyOS_vsnprintf_EXTRA_SPACE
 }
