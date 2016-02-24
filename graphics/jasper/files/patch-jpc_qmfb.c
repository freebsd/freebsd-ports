--- src/libjasper/jpc/jpc_qmfb.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_qmfb.c	2016-02-20 13:56:19.711609000 +0100
@@ -305,12 +305,8 @@
 void jpc_qmfb_split_row(jpc_fix_t *a, int numcols, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numcols, 1);
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
@@ -318,15 +314,13 @@
 	register int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numcols >= 2) {
 		hstartcol = (numcols + 1 - parity) >> 1;
@@ -360,12 +354,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -373,12 +365,8 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
@@ -386,15 +374,13 @@
 	register int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -428,12 +414,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -441,12 +425,8 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize * JPC_QMFB_COLGRPSIZE];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -457,15 +437,13 @@
 	int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -517,12 +495,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -530,12 +506,8 @@
   int stride, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize * numcols];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -546,15 +518,13 @@
 	int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -606,39 +576,31 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
 void jpc_qmfb_join_row(jpc_fix_t *a, int numcols, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numcols, 1);
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
 	register int n;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numcols + 1 - parity) >> 1;
 
@@ -670,12 +632,10 @@
 		++srcptr;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -683,27 +643,21 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
 	register int n;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -735,12 +689,10 @@
 		++srcptr;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -748,12 +700,8 @@
   int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize * JPC_QMFB_COLGRPSIZE];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -763,15 +711,13 @@
 	register int i;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc2(bufsize, JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -821,12 +767,10 @@
 		srcptr += JPC_QMFB_COLGRPSIZE;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -834,12 +778,8 @@
   int stride, int parity)
 {
 
-	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
+	size_t bufsize = JPC_CEILDIVPOW2(numrows, 1);
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize * numcols];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -849,15 +789,13 @@
 	register int i;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * numcols * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_malloc3(bufsize, numcols, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -907,12 +845,10 @@
 		srcptr += numcols;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
