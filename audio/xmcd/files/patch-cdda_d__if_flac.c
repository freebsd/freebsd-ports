--- cdda_d/if_flac.c.orig	2008-04-06 21:14:40.000000000 +0200
+++ cdda_d/if_flac.c	2008-04-06 22:11:17.000000000 +0200
@@ -57,7 +57,6 @@ typedef float			FLAC__real;
 #include <FLAC/format.h>
 #include <FLAC/metadata.h>
 #include <FLAC/stream_encoder.h>
-#include <FLAC/seekable_stream_encoder.h>
 
 
 extern appdata_t		app_data;
@@ -86,7 +85,6 @@ extern char			*tagcomment;	/* Tag commen
 /* Container union for encoder instance pointers */
 typedef union {
 	FLAC__StreamEncoder		*st;	/* Stream encoder */
-	FLAC__SeekableStreamEncoder	*sk;	/* Seekable stream encoder */
 } flac_desc_t;
 
 
@@ -153,76 +151,10 @@ if_flac_write_callback(
 
 
 /*
- * if_flac_seekable_write_callback
- *	FLAC seekable stream encoder write callback function
- *
- * Args:
- *	skp - Seekable stream encoder instance descriptor
- *	buf - Output data buffer
- *	len - data length
- *	samples - number of samples
- *	frame - Current frame
- *	client_data - Callback data
- *
- * Return:
- *	FLAC__STREAM_ENCODER_WRITE_STATUS_OK - success
- *	FLAC__STREAM_ENCODER_WRITE_STATUS_FATAL_ERROR - failure
- */
-/*ARGSUSED*/
-STATIC FLAC__StreamEncoderWriteStatus
-if_flac_seekable_write_callback(
-	const FLAC__SeekableStreamEncoder	*skp,
-	const FLAC__byte			*buf,
-	unsigned int				len,
-	unsigned int				samples,
-	unsigned int				frame,
-	void					*client_data
-)
-{
-	gen_desc_t	*gdp = (gen_desc_t *) client_data;
-
-	if (buf == NULL || len == 0)
-		/* Nothing to do */
-		return FLAC__STREAM_ENCODER_WRITE_STATUS_OK;
-
-	/* Write out the encoded data */
-	gdp->flags |= GDESC_WRITEOUT;
-	if (!gen_write_chunk(gdp, (byte_t *) buf, (size_t) len))
-		return FLAC__STREAM_ENCODER_WRITE_STATUS_FATAL_ERROR;
-
-	return FLAC__STREAM_ENCODER_WRITE_STATUS_OK;
-}
-
-
-/*
  * if_flac_metadata_callback
  *	FLAC stream encoder metadata callback function
  *
  * Args:
- *	stp - Encoder instance descriptor
- *	data - Metadata buffer
- *	client_data - Callback data
- *
- * Return:
- *	Nothing.
- */
-/*ARGSUSED*/
-STATIC void
-if_flac_metadata_callback(
-	const FLAC__StreamEncoder	*stp,
-	const FLAC__StreamMetadata	*meta,
-	void				*client_data
-)
-{
-	/* Do nothing: can't seek on a pipe */
-}
-
-
-/*
- * if_flac_seek_callback
- *	FLAC seekable stream encoder seek callback function
- *
- * Args:
  *	skp - Encoder instance descriptor
  *	data - Metadata buffer
  *	client_data - Callback data
@@ -231,9 +163,9 @@ if_flac_metadata_callback(
  *	Nothing.
  */
 /*ARGSUSED*/
-STATIC FLAC__SeekableStreamEncoderSeekStatus
-if_flac_seek_callback(
-	const FLAC__SeekableStreamEncoder	*skp,
+STATIC FLAC__StreamEncoderSeekStatus
+if_flac_metadata_callback(
+	const FLAC__StreamEncoder		*skp,
 	FLAC__uint64				offset,
 	void					*client_data
 )
@@ -244,9 +176,9 @@ if_flac_seek_callback(
 	val = (off_t) ASSIGN32(offset);
 
 	if (gen_seek(gdp, val, SEEK_SET))
-		return FLAC__SEEKABLE_STREAM_ENCODER_SEEK_STATUS_OK;
+		return FLAC__STREAM_ENCODER_SEEK_STATUS_OK;
 	else
-		return FLAC__SEEKABLE_STREAM_ENCODER_SEEK_STATUS_ERROR;
+		return FLAC__STREAM_ENCODER_SEEK_STATUS_ERROR;
 }
 
 
@@ -635,16 +567,9 @@ if_flac_addmeta(gen_desc_t *gdp, flac_de
 	if (flac_mblks == 0)
 		return;	/* No metadata to set */
 
-	if ((gdp->flags & GDESC_ISPIPE) != 0) {
-		ret = FLAC__stream_encoder_set_metadata(
-			ufdp->st, flac_mlist, flac_mblks
-		);
-	}
-	else {
-		ret = FLAC__seekable_stream_encoder_set_metadata(
-			ufdp->sk, flac_mlist, flac_mblks
-		);
-	}
+	ret = FLAC__stream_encoder_set_metadata(
+		ufdp->st, flac_mlist, flac_mblks
+	);
 	if (!ret) {
 		(void) strcpy(gdp->cdp->i->msgbuf,
 			    "if_flac_addmeta: Failed setting metadata.");
@@ -655,7 +580,7 @@ if_flac_addmeta(gen_desc_t *gdp, flac_de
 
 /*
  * if_flac_encoder_setup
- *	Create and set up the FLAC stream encoder (used for pipe output).
+ *	Create and set up the FLAC stream encoder.
  *
  * Args:
  *	gdp  - Pointer to the gen_desc_t structure
@@ -836,43 +761,12 @@ if_flac_encoder_setup(
 	/* Initialize and add metadata to FLAC output */
 	if_flac_addmeta(gdp, ufdp);
 
-	/* Register write callback function */
-	ret = FLAC__stream_encoder_set_write_callback(
-		stp, if_flac_write_callback
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_encoder_setup: "
-			    "Failed setting write callback.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Register metadata callback function */
-	ret = FLAC__stream_encoder_set_metadata_callback(
-		stp, if_flac_metadata_callback
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_encoder_setup: "
-			    "Failed setting metadata callback.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Set callback argument */
-	ret = FLAC__stream_encoder_set_client_data(stp, gdp);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_encoder_setup: "
-			    "Failed setting client data.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
 	/* Initialize FLAC encoder */
-	enc_state = FLAC__stream_encoder_init(stp);
-	if (enc_state != FLAC__STREAM_ENCODER_OK) {
+	enc_state = FLAC__stream_encoder_init_stream(
+		stp, if_flac_write_callback, NULL, NULL,
+		if_flac_metadata_callback, gdp
+	);
+	if (enc_state != FLAC__STREAM_ENCODER_INIT_STATUS_OK) {
 		(void) sprintf(gdp->cdp->i->msgbuf,
 			"if_flac_encoder_setup: Encoder init error: %s",
 			FLAC__stream_encoder_get_resolved_state_string(stp)
@@ -908,271 +802,6 @@ if_flac_encoder_setup(
 
 
 /*
- * if_flac_seekable_encoder_setup
- *	Create and set up the FLAC seekable stream encoder (used for file
- *	output).
- *
- * Args:
- *	gdp  - Pointer to the gen_desc_t structure
- *	ufdp - Pointer to the flac_desc_t structure
- *	pp   - Pointer to the flac_parms_t structure
- *
- * Return:
- *	TRUE  - success
- *	FALSE - failure
- */
-STATIC bool_t
-if_flac_seekable_encoder_setup(
-	gen_desc_t	*gdp,
-	flac_desc_t	*ufdp,
-	flac_parms_t	*pp
-)
-{
-	FLAC__SeekableStreamEncoder		*skp;
-	FLAC__SeekableStreamEncoderState	enc_state;
-	FLAC__uint64				val;
-	FLAC__bool				ret;
-
-	ufdp->sk = skp = FLAC__seekable_stream_encoder_new();
-	if (skp == NULL) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "FLAC encoder instantiation failed.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Set some basic parameters */
-
-	ret = FLAC__seekable_stream_encoder_set_channels(skp, 2);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting channels.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_bits_per_sample(skp, 16);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting bits per sample.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_sample_rate(skp, 44100);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting sample rate.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	val = ASSIGN64(gdp->datalen >> 2);
-	ret = FLAC__seekable_stream_encoder_set_total_samples_estimate(
-		skp, val
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting samples estimate.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_streamable_subset(skp, TRUE);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting streamable subset.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_do_qlp_coeff_prec_search(
-		skp, pp->qlp_srch
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			"if_flac_seekable_encoder_setup: "
-			"Failed setting LP coefficient quantization search."
-		);
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Just use default for now
-	ret = FLAC__seekable_stream_encoder_set_qlp_coeff_precision(skp, 0);
-	*/
-
-	ret = FLAC__seekable_stream_encoder_set_verify(skp, pp->vfy_mode);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting verify mode.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_max_lpc_order(
-		skp, pp->lpc_order
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting max LPC order.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_blocksize(skp, pp->block_sz);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting block size.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_do_mid_side_stereo(
-		skp, pp->mid_side
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting M/S stereo.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_loose_mid_side_stereo(
-		skp, pp->adap_ms
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting adaptive M/S stereo.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	if (pp->min_rpo >= 0) {
-		ret = FLAC__seekable_stream_encoder_set_min_residual_partition_order(
-			skp, (unsigned int) pp->min_rpo
-		);
-		if (!ret) {
-			(void) strcpy(gdp->cdp->i->msgbuf,
-				    "if_flac_seekable_encoder_setup: "
-				    "Failed setting minimum RPO.");
-			DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-			return FALSE;
-		}
-	}
-
-	if (pp->max_rpo >= 0) {
-		ret = FLAC__seekable_stream_encoder_set_max_residual_partition_order(
-			skp, (unsigned int) pp->max_rpo
-		);
-		if (!ret) {
-			(void) strcpy(gdp->cdp->i->msgbuf,
-				    "if_flac_seekable_encoder_setup: "
-				    "Failed setting maximum RPO.");
-			DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-			return FALSE;
-		}
-	}
-
-	ret = FLAC__seekable_stream_encoder_set_do_exhaustive_model_search(
-		skp, pp->exh_srch
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting exhaustive model search.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Initialize and add metadata to FLAC output */
-	if_flac_addmeta(gdp, ufdp);
-
-	/* Register write callback function */
-	ret = FLAC__seekable_stream_encoder_set_write_callback(
-		skp, if_flac_seekable_write_callback
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting write callback.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Register seek callback function */
-	ret = FLAC__seekable_stream_encoder_set_seek_callback(
-		skp, if_flac_seek_callback
-	);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting seek callback.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Set callback argument */
-	ret = FLAC__seekable_stream_encoder_set_client_data(skp, gdp);
-	if (!ret) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-			    "if_flac_seekable_encoder_setup: "
-			    "Failed setting client data.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Initialize FLAC encoder */
-	enc_state = FLAC__seekable_stream_encoder_init(skp);
-	if (enc_state != FLAC__SEEKABLE_STREAM_ENCODER_OK) {
-		(void) sprintf(gdp->cdp->i->msgbuf,
-		   "if_flac_seekable_encoder_setup: Encoder init error: %s",
-		   FLAC__seekable_stream_encoder_get_resolved_state_string(skp)
-		);
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	/* Allocate wide samples buffers for the two channels */
-	fenc_buf[0] = (FLAC__int32 *) MEM_ALLOC(
-		"fenc_buf0",
-		(size_t) gdp->cdp->cds->chunk_bytes
-	);
-	if (fenc_buf[0] == NULL) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-				"if_flac_seekable_encoder_setup: "
-				"Out of memory.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-	fenc_buf[1] = (FLAC__int32 *) MEM_ALLOC(
-		"fenc_buf1",
-		(size_t) gdp->cdp->cds->chunk_bytes
-	);
-	if (fenc_buf[1] == NULL) {
-		(void) strcpy(gdp->cdp->i->msgbuf,
-				"if_flac_seekable_encoder_setup: "
-				"Out of memory.");
-		DBGPRN(DBG_SND)(errfp, "%s\n", gdp->cdp->i->msgbuf);
-		return FALSE;
-	}
-
-	return TRUE;
-}
-
-
-/*
  * if_flac_init
  *	Initialize FLAC encoder and set up encoding parameters
  *
@@ -1300,10 +929,7 @@ if_flac_init(gen_desc_t *gdp)
 	}
 
 	/* Set up encoder */
-	if ((gdp->flags & GDESC_ISPIPE) != 0)
-		ret = if_flac_encoder_setup(gdp, ufdp, &parms);
-	else
-		ret = if_flac_seekable_encoder_setup(gdp, ufdp, &parms);
+	ret = if_flac_encoder_setup(gdp, ufdp, &parms);
 
 	return (ret);
 }
@@ -1351,16 +977,9 @@ if_flac_encode_chunk(gen_desc_t *gdp, by
 
 	DBGPRN(DBG_SND)(errfp, "\nEncoding %d samples\n", samples);
 
-	if ((gdp->flags & GDESC_ISPIPE) != 0) {
-		ret = FLAC__stream_encoder_process(
-			ufdp->st, (void *) fenc_buf, (unsigned int) samples
-		);
-	}
-	else {
-		ret = FLAC__seekable_stream_encoder_process(
-			ufdp->sk, (void *) fenc_buf, (unsigned int) samples
-		);
-	}
+	ret = FLAC__stream_encoder_process(
+		ufdp->st, (void *) fenc_buf, (unsigned int) samples
+	);
 	if (!ret) {
 		(void) strcpy(gdp->cdp->i->msgbuf,
 			"if_flac_encode_chunk: Process encoding failed.");
@@ -1393,14 +1012,8 @@ if_flac_halt(gen_desc_t *gdp)
 
 	ufdp = (flac_desc_t *) gdp->aux;
 
-	if ((gdp->flags & GDESC_ISPIPE) != 0) {
-		FLAC__stream_encoder_finish(ufdp->st);
-		FLAC__stream_encoder_delete(ufdp->st);
-	}
-	else {
-		FLAC__seekable_stream_encoder_finish(ufdp->sk);
-		FLAC__seekable_stream_encoder_delete(ufdp->sk);
-	}
+	FLAC__stream_encoder_finish(ufdp->st);
+	FLAC__stream_encoder_delete(ufdp->st);
 
 	MEM_FREE(ufdp);
 	gdp->aux = NULL;
