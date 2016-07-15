CVE-2016-5875(, dup?)
https://marc.info/?l=oss-security&m=146720235906569&w=2

--- libtiff/tif_pixarlog.c.orig	Sat Aug 29 00:16:22 2015
+++ libtiff/tif_pixarlog.c	Fri Jul  1 13:04:52 2016
@@ -457,6 +457,7 @@ horizontalAccumulate8abgr(uint16 *wp, int n, int strid
 typedef	struct {
 	TIFFPredictorState	predict;
 	z_stream		stream;
+	tmsize_t		tbuf_size; /* only set/used on reading for now */
 	uint16			*tbuf; 
 	uint16			stride;
 	int			state;
@@ -692,6 +693,7 @@ PixarLogSetupDecode(TIFF* tif)
 	sp->tbuf = (uint16 *) _TIFFmalloc(tbuf_size);
 	if (sp->tbuf == NULL)
 		return (0);
+	sp->tbuf_size = tbuf_size;
 	if (sp->user_datafmt == PIXARLOGDATAFMT_UNKNOWN)
 		sp->user_datafmt = PixarLogGuessDataFmt(td);
 	if (sp->user_datafmt == PIXARLOGDATAFMT_UNKNOWN) {
@@ -779,6 +781,12 @@ PixarLogDecode(TIFF* tif, uint8* op, tmsize_t occ, uin
 	if (sp->stream.avail_out != nsamples * sizeof(uint16))
 	{
 		TIFFErrorExt(tif->tif_clientdata, module, "ZLib cannot deal with buffers this size");
+		return (0);
+	}
+	/* Check that we will not fill more than what was allocated */
+	if (sp->stream.avail_out > sp->tbuf_size)
+	{
+		TIFFErrorExt(tif->tif_clientdata, module, "sp->stream.avail_out > sp->tbuf_size");
 		return (0);
 	}
 	do {
