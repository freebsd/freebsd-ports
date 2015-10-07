--- src/libjasper/jpc/jpc_qmfb.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_qmfb.c	2015-08-29 08:07:01.000000000 +0200
@@ -305,7 +305,7 @@
 void jpc_qmfb_split_row(jpc_fix_t *a, int numcols, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numcols, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
 #else
@@ -321,7 +321,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -373,7 +373,7 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
 #else
@@ -389,7 +389,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -441,7 +441,7 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
 #else
@@ -460,7 +460,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -530,7 +530,7 @@
   int stride, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
 #else
@@ -549,7 +549,7 @@
 #if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
@@ -618,7 +618,7 @@
 void jpc_qmfb_join_row(jpc_fix_t *a, int numcols, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numcols, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
 #else
@@ -633,7 +633,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
@@ -683,7 +683,7 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
 #else
@@ -698,7 +698,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
@@ -748,7 +748,7 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
 #else
@@ -766,7 +766,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
@@ -834,7 +834,7 @@
   int stride, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 #if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
 #else
@@ -852,7 +852,7 @@
 #if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * numcols * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, numcols, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
