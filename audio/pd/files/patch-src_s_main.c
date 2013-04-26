--- src/s_main.c.orig	2011-03-07 10:11:02.000000000 +0900
+++ src/s_main.c	2011-04-06 19:30:04.000000000 +0900
@@ -936,7 +940,11 @@
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
