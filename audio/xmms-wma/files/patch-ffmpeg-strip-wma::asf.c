--- ffmpeg-strip-wma/asf.c	Fri Feb 20 03:21:31 2004
+++ ffmpeg-strip-wma/asf.c	Thu Mar 11 18:46:59 2004
@@ -847,7 +847,7 @@
        {
            return;
        }
-       result = iconv(frt, &ansbptr, &len, &ansaptr, &len1);
+       result = iconv(frt, (const char **)&ansbptr, &len, &ansaptr, &len1);
        if (result == (size_t) - 1)
        {
            return;
