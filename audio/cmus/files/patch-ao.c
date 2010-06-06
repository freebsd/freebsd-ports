--- ao.c.orig	2010-06-05 20:09:57.000000000 +0200
+++ ao.c	2010-06-05 20:10:36.000000000 +0200
@@ -71,6 +71,7 @@ static int op_ao_open(sample_format_t sf
 		return -OP_ERROR_ERRNO;
 	}
 
+	memset(&format, 0, sizeof(format));
 	format.bits = sf_get_bits(sf);
 	format.rate = sf_get_rate(sf);
 	format.channels = sf_get_channels(sf);
