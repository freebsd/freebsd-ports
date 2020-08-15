--- decode.c.orig	2020-06-07 11:02:26 UTC
+++ decode.c
@@ -183,11 +183,7 @@ void decode_init(log_level level, const char *include_
 	if (!strstr(exclude_codecs, "pcm")	&& (!include_codecs || (order_codecs = strstr(include_codecs, "pcm"))))
 		sort_codecs((include_codecs ? order_codecs - include_codecs : i), register_pcm());
 
-	// try mad then mpg for mp3 unless command line option passed
-	if (!(strstr(exclude_codecs, "mp3") || strstr(exclude_codecs, "mad")) &&
-		(!include_codecs || (order_codecs = strstr(include_codecs, "mp3")) || (order_codecs = strstr(include_codecs, "mad"))))
-		sort_codecs((include_codecs ? order_codecs - include_codecs : i), register_mad());
-	else if (!(strstr(exclude_codecs, "mp3") || strstr(exclude_codecs, "mpg")) &&
+	if (!(strstr(exclude_codecs, "mp3") || strstr(exclude_codecs, "mpg")) &&
 		(!include_codecs || (order_codecs = strstr(include_codecs, "mp3")) || (order_codecs = strstr(include_codecs, "mpg"))))
 		sort_codecs((include_codecs ? order_codecs - include_codecs : i), register_mpg());
 
