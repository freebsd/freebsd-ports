--- src/wx-config.c.orig	2020-12-01 19:49:05 UTC
+++ src/wx-config.c
@@ -1807,7 +1807,7 @@ static int hdnew_dlgproc(void* hdlg, int message, INT_
 
                         if (hd_format == 0) /* Raw .img */
                         {
-                                f = fopen64(hd_new_name, "wb");
+                                f = fopen(hd_new_name, "wb");
                                 if (!f)
                                 {
                                         wx_messagebox(hdlg, "Can't open file for write", "PCem error", WX_MB_OK);
@@ -2219,7 +2219,7 @@ static int hd_file(void *hdlg, int drive)
         if (!getfile(hdlg, "Hard disc image (*.img;*.vhd)|*.img;*.vhd|All files (*.*)|*.*", ""))
         {
                 off64_t sz;
-                FILE *f = fopen64(openfilestring, "rb");
+                FILE *f = fopen(openfilestring, "rb");
                 if (!f)
                 {
                         wx_messagebox(hdlg,"Can't open file for read","PCem error",WX_MB_OK);
@@ -2271,8 +2271,8 @@ static int hd_file(void *hdlg, int drive)
                 }
                 else
                 {
-                        fseeko64(f, -1, SEEK_END);
-                        sz = ftello64(f) + 1;
+                        fseek(f, -1, SEEK_END);
+                        sz = ftell(f) + 1;
                         fclose(f);
                         check_hd_type(hdlg, sz);
                 }
