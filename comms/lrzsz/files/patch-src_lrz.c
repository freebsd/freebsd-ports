--- src/lrz.c.orig	2026-10-04 09:46:20 UTC
+++ src/lrz.c
@@ -399,6 +399,8 @@ main(int argc, char *argv[])
 		usage(2,_("garbage on commandline"));
 	if (protocol!=ZM_XMODEM && npats)
 		usage(2, _("garbage on commandline"));
+	if (protocol==ZM_XMODEM && !npats)
+		usage(2, _("need a file name to receive"));
 	if (Fromcu && !Quiet) {
 		if (Verbose == 0)
 			Verbose = 2;
@@ -923,13 +925,13 @@ do_crc_check(FILE *f, size_t remote_bytes, size_t chec
     if (check_bytes==0 && ((size_t) st.st_size)!=remote_bytes)
         return ZCRC_DIFFERS; /* shortcut */
 
-    crc=0xFFFFFFFFL;
+    crc=0xFFFFFFFFUL;
     n=check_bytes;
     if (n==0)
         n=st.st_size;
     while (n-- && ((c = getc(f)) != EOF))
         crc = UPDC32(c, crc);
-    crc = ~crc;
+    crc = (~crc) & 0xffffffffUL;
     clearerr(f);  /* Clear EOF */
     fseeko(f, 0, 0);
 
