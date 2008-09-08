--- Objects/obmalloc.c.orig	2008-02-14 11:26:18.000000000 +0000
+++ Objects/obmalloc.c	2008-08-30 10:39:43.000000000 +0100
@@ -727,6 +727,15 @@
 	uint size;
 
 	/*
+	 * Limit ourselves to PY_SSIZE_T_MAX bytes to prevent security holes.
+	 * Most python internals blindly use a signed Py_ssize_t to track
+	 * things without checking for overflows or negatives.
+	 * As size_t is unsigned, checking for nbytes < 0 is not required.
+	 */
+	if (nbytes > PY_SSIZE_T_MAX)
+		return NULL;
+
+	/*
 	 * This implicitly redirects malloc(0).
 	 */
 	if ((nbytes - 1) < SMALL_REQUEST_THRESHOLD) {
@@ -1130,6 +1139,15 @@
 	if (p == NULL)
 		return PyObject_Malloc(nbytes);
 
+	/*
+	 * Limit ourselves to PY_SSIZE_T_MAX bytes to prevent security holes.
+	 * Most python internals blindly use a signed Py_ssize_t to track
+	 * things without checking for overflows or negatives.
+	 * As size_t is unsigned, checking for nbytes < 0 is not required.
+	 */
+	if (nbytes > PY_SSIZE_T_MAX)
+		return NULL;
+
 	pool = POOL_ADDR(p);
 	if (Py_ADDRESS_IN_RANGE(p, pool)) {
 		/* We're in charge of this block */
