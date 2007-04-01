--- ros/src/WOKsite/wok.csh.orig	Fri Mar  5 18:48:47 2004
+++ ros/src/WOKsite/wok.csh	Tue Aug  1 20:43:03 2006
@@ -57,6 +57,9 @@
     case SunOS:
 	setenv WOKSTATION "sun"
 	breaksw
+    case FreeBSD:
+	setenv WOKSTATION "bsd"
+	breaksw
     case Linux:
 	setenv WOKSTATION "lin"
 	breaksw
