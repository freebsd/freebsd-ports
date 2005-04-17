--- getbits.c	Wed Aug 20 10:30:21 1997
+++ getbits.c	Wed Apr 13 00:21:47 2005
@@ -91,6 +91,7 @@
  */
 static inline void parse_header(struct AUDIO_HEADER *header) 
 {
+        header->IDex=_getbits(1);
         header->ID=_getbits(1);
         header->layer=_getbits(2);
         header->protection_bit=_getbits(1);
@@ -112,11 +113,17 @@
 		header->bitrate_index==15 ||
 		header->sampling_frequency==3) return -1;
 
+        /* Rule out invalid MPEG 2.5 headers */
+	if (header->IDex==0 && 
+		(header->ID==1 || header->layer!=1 || 
+		 header->bitrate_index > 8)) return -1;
+
 	/* an additional check to make shure that stuffing never gets mistaken
  	 * for a syncword. This rules out some legal layer1 streams, but who
  	 * cares about layer1 anyway :-). I must get this right sometime.
 	 */
 	if ( header->ID==1 && header->layer==3 && header->protection_bit==1) return -1;
+
 	return 0;
 }
 
@@ -132,11 +139,7 @@
 	if ((retval=_fillbfr(4))!=0) return retval;
 
 	for(;;) {
-		while ((s=_getbits(12)) != 0xfff) {
-			if (s==0xffe) {
-				parse_header(&tmp);
-				if (header_sanity_check(&tmp)==0) return GETHDR_NS;
-			}
+		while (_getbits(11) != 0x7ff) {
 			if ((retval=readsync())!=0) return retval;
 		}
 	
