--- tftpd_pcre.c.orig	2010-10-04 18:24:43.000000000 +0800
+++ tftpd_pcre.c	2010-10-04 18:25:23.000000000 +0800
@@ -211,9 +211,9 @@
                chp++; /* point to value indicating substring */
                rc = pcre_get_substring(str, ovector, matches, *chp - 0x30, &tmpstr);
                /* found string */
-               if (rc > 0)
+               if (rc > 0 && outchp - outstr + rc+1 < outsize)
                {
-                    Strncpy(outchp, tmpstr, rc);
+                    Strncpy(outchp, tmpstr, rc+1);
                     outchp += rc;
                     pcre_free_substring(tmpstr);
                     continue;
