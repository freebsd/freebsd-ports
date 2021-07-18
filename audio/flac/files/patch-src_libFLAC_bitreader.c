https://github.com/xiph/flac/commit/2e7931c27eb15e387da440a37f12437e35b22dd4

--- src/libFLAC/bitreader.c.orig	2021-05-08 16:06:17 UTC
+++ src/libFLAC/bitreader.c
@@ -864,7 +864,7 @@ incomplete_lsbs:
 			cwords = br->consumed_words;
 			words = br->words;
 			ucbits = FLAC__BITS_PER_WORD - br->consumed_bits;
-			b = br->buffer[cwords] << br->consumed_bits;
+			b = cwords < br->capacity ? br->buffer[cwords] << br->consumed_bits : 0;
 		} while(cwords >= words && val < end);
 	}
 
