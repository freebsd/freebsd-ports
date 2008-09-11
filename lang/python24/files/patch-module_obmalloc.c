--- Objects/obmalloc.c.orig	2005-07-11 07:57:11.000000000 +0200
+++ Objects/obmalloc.c
@@ -585,6 +585,15 @@ PyObject_Malloc(size_t nbytes)
 	uint size;
 
 	/*
+	 * Limit ourselves to INT_MAX bytes to prevent security holes.
+	 * Most python internals blindly use a signed Py_ssize_t to track
+	 * things without checking for overflows or negatives.
+	 * As size_t is unsigned, checking for nbytes < 0 is not required.
+	 */
+	if (nbytes > INT_MAX)
+		return NULL;
+
+	/*
 	 * This implicitly redirects malloc(0).
 	 */
 	if ((nbytes - 1) < SMALL_REQUEST_THRESHOLD) {
@@ -814,6 +823,15 @@ PyObject_Realloc(void *p, size_t nbytes)
 	if (p == NULL)
 		return PyObject_Malloc(nbytes);
 
+	/*
+	 * Limit ourselves to INT_MAX bytes to prevent security holes.
+	 * Most python internals blindly use a signed Py_ssize_t to track
+	 * things without checking for overflows or negatives.
+	 * As size_t is unsigned, checking for nbytes < 0 is not required.
+	 */
+	if (nbytes > INT_MAX)
+		return NULL;
+
 	pool = POOL_ADDR(p);
 	if (Py_ADDRESS_IN_RANGE(p, pool)) {
 		/* We're in charge of this block */
