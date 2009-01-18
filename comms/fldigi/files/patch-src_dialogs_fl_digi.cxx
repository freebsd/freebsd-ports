--- src/dialogs/fl_digi.cxx.orig	2009-01-17 09:32:22.000000000 -0500
+++ src/dialogs/fl_digi.cxx	2009-01-17 14:53:39.000000000 -0500
@@ -1288,7 +1288,7 @@
 	Fl::repeat_timeout(st, ztimer);
 
 	struct tm tm;
-	gmtime_r(&tv.tv_sec, &tm);
+	gmtime_r((const time_t *)&tv.tv_sec, &tm);
 	if (!strftime(ztbuf, sizeof(ztbuf), "%Y%m%d %H%M", &tm))
 		memset(ztbuf, 0, sizeof(ztbuf));
 	else
@@ -2727,7 +2727,7 @@
 
 #if defined (__CYGWIN__)
 	fl_digi_main->icon((char*)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));
-#elif defined (__linux__)
+#elif defined (__linux__) || defined (__FreeBSD__)
 	make_pixmap(&fldigi_icon_pixmap, fldigi_icon);
 	fl_digi_main->icon((char *)fldigi_icon_pixmap);
 #endif
