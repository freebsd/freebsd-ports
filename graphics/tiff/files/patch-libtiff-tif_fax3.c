--- libtiff/tif_fax3.c.orig	Thu Feb  5 09:02:26 2004
+++ libtiff/tif_fax3.c	Thu Feb  5 09:05:07 2004
@@ -451,7 +451,7 @@
 	Fax3BaseState* sp = Fax3State(tif);
 	long rowbytes, rowpixels;
 	int needsRefLine;
-	Fax3CodecState* dsp = DecoderState(tif);
+	Fax3CodecState* dsp = (Fax3CodecState*) Fax3State(tif);
 	uint32 nruns;
 
 	if (td->td_bitspersample != 1) {
@@ -1284,7 +1284,8 @@
 	sp->recvparams = 0;
 	sp->subaddress = NULL;
 
-	tif->tif_flags |= TIFF_NOBITREV;	/* decoder does bit reversal */
+	if (sp->rw_mode == O_RDONLY)			/* FIXME: improve for in place update */
+		tif->tif_flags |= TIFF_NOBITREV;	/* decoder does bit reversal */
 	DecoderState(tif)->runs = NULL;
 	TIFFSetField(tif, TIFFTAG_FAXFILLFUNC, _TIFFFax3fillruns);
 	EncoderState(tif)->refline = NULL;
