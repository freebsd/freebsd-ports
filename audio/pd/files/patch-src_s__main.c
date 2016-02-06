--- src/s_main.c.orig	2015-09-09 23:08:21 UTC
+++ src/s_main.c
@@ -1137,7 +1137,11 @@ static void sys_afterargparse(void)
             /* add "doc/5.reference" library to helppath */
     strncpy(sbuf, sys_libdir->s_name, MAXPDSTRING-30);
     sbuf[MAXPDSTRING-30] = 0;
+#if defined(__FreeBSD__)
+    strcat(sbuf, "/share/doc/pd/5.reference");
+#else
     strcat(sbuf, "/doc/5.reference");
+#endif
     sys_helppath = namelist_append_files(sys_helppath, sbuf);
         /* correct to make audio and MIDI device lists zero based.  On
         MMIO, however, "1" really means the second device (the first one
