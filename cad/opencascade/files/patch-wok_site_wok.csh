--- wok/site/wok.csh.orig	Fri Mar  5 18:48:47 2004
+++ wok/site/wok.csh	Mon Jul 31 23:07:35 2006
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
