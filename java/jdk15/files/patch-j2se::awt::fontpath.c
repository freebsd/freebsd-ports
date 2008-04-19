$FreeBSD$

--- ../../j2se/src/solaris/native/sun/awt/fontpath.c.orig	Sun Dec 10 21:57:02 2006
+++ ../../j2se/src/solaris/native/sun/awt/fontpath.c	Sun Dec 10 21:58:43 2006
@@ -98,18 +98,18 @@
  * various flavors of Linux
  */
 static char *fullLinuxFontPath[] = {
-    "/usr/X11R6/lib/X11/fonts/TrueType",  /* RH 7.1+ */
-    "/usr/X11R6/lib/X11/fonts/truetype",  /* SuSE */
-    "/usr/X11R6/lib/X11/fonts/tt",
-    "/usr/X11R6/lib/X11/fonts/TTF",
-    "/usr/X11R6/lib/X11/fonts/OTF",       /* RH 9.0 (but empty!) */
+    "%%LOCALBASE%%/lib/X11/fonts/TrueType",  /* RH 7.1+ */
+    "%%LOCALBASE%%/lib/X11/fonts/truetype",  /* SuSE */
+    "%%LOCALBASE%%/lib/X11/fonts/tt",
+    "%%LOCALBASE%%/lib/X11/fonts/TTF",
+    "%%LOCALBASE%%/lib/X11/fonts/OTF",       /* RH 9.0 (but empty!) */
     "/usr/share/fonts/ja/TrueType",       /* RH 7.2+ */
     "/usr/share/fonts/truetype",
     "/usr/share/fonts/ko/TrueType",       /* RH 9.0 */
     "/usr/share/fonts/zh_CN/TrueType",    /* RH 9.0 */
     "/usr/share/fonts/zh_TW/TrueType",    /* RH 9.0 */
     "/var/lib/defoma/x-ttcidfont-conf.d/dirs/TrueType", /* Debian */
-    "/usr/X11R6/lib/X11/fonts/Type1",
+    "%%LOCALBASE%%/lib/X11/fonts/Type1",
     "/usr/share/fonts/default/Type1",     /* RH 9.0 */
     NULL, /* terminates the list */
 };
