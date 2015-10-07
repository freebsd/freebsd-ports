--- src/libjasper/mif/mif_cod.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/mif/mif_cod.c	2015-08-29 08:07:01.000000000 +0200
@@ -107,7 +107,7 @@
 static int mif_hdr_addcmpt(mif_hdr_t *hdr, int cmptno, mif_cmpt_t *cmpt);
 static mif_cmpt_t *mif_cmpt_create(void);
 static void mif_cmpt_destroy(mif_cmpt_t *cmpt);
-static char *mif_getline(jas_stream_t *jas_stream, char *buf, int bufsize);
+static char *mif_getline(jas_stream_t *jas_stream, char *buf, size_t bufsize);
 static int mif_getc(jas_stream_t *in);
 static mif_hdr_t *mif_makehdrfromimage(jas_image_t *image);
 
@@ -438,8 +438,7 @@
 	int cmptno;
 	mif_cmpt_t **newcmpts;
 	assert(maxcmpts >= hdr->numcmpts);
-	newcmpts = (!hdr->cmpts) ? jas_malloc(maxcmpts * sizeof(mif_cmpt_t *)) :
-	  jas_realloc(hdr->cmpts, maxcmpts * sizeof(mif_cmpt_t *));
+	newcmpts = jas_realloc2(hdr->cmpts, maxcmpts, sizeof(mif_cmpt_t *));
 	if (!newcmpts) {
 		return -1;
 	}
@@ -658,7 +657,7 @@
 * MIF parsing code.
 \******************************************************************************/
 
-static char *mif_getline(jas_stream_t *stream, char *buf, int bufsize)
+static char *mif_getline(jas_stream_t *stream, char *buf, size_t bufsize)
 {
 	int c;
 	char *bufptr;
