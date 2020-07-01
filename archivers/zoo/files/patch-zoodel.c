--- zoodel.c.orig	1991-07-16 15:58:46 UTC
+++ zoodel.c
@@ -138,7 +138,11 @@ if (*option == 'g') {
    
    /* read archive header */
    frd_zooh (&zoo_header, zoo_file);
+#ifdef __LP64__
+   if ((int)(zoo_header.zoo_start + zoo_header.zoo_minus) != 0)
+#else
    if ((zoo_header.zoo_start + zoo_header.zoo_minus) != 0L)
+#endif
       prterror ('f', failed_consistency);
    if (ver_too_high (&zoo_header))
       prterror ('f', wrong_version, zoo_header.major_ver, zoo_header.minor_ver);
