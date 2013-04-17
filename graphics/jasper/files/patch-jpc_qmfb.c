--- src/libjasper/jpc/jpc_qmfb.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_qmfb.c	2013-04-17 22:32:23.000000000 +0200
@@ -321,7 +321,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -389,7 +389,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -460,7 +460,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -549,7 +549,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -633,7 +633,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
@@ -698,7 +698,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
@@ -766,7 +766,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
@@ -852,7 +852,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * numcols * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, numcols, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
