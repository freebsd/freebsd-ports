--- src/misc/configuration.cxx.orig	2013-03-28 08:57:53.000000000 -0500
+++ src/misc/configuration.cxx	2013-03-28 08:59:54.000000000 -0500
@@ -901,8 +901,6 @@
 
 void configuration::testCommPorts()
 {
-	int retval;
-
 	inpTTYdev->clear();
 	inpRIGdev->clear();
 	inpXmlRigDevice->clear();
@@ -919,6 +917,7 @@
 #endif
 
 #ifdef __linux__
+	int retval;
 	bool ret = false;
 	DIR* sys = NULL;
 	char cwd[PATH_MAX] = { '.', '\0' };
@@ -965,9 +964,7 @@
 		"/dev/ttyS%u",
 		"/dev/ttyUSB%u",
 		"/dev/usb/ttyUSB%u"
-#elif defined(__FreeBSD__)
-		"/dev/ttyd%u"
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		"/dev/tty%2.2u"
 #elif defined(__CYGWIN__)
 		"/dev/ttyS%u"
