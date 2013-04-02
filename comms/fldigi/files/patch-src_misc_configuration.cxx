--- src/misc/configuration.cxx.orig	2013-02-08 21:00:53.000000000 -0500
+++ src/misc/configuration.cxx	2013-04-01 08:06:29.000000000 -0500
@@ -891,8 +891,6 @@
 
 void configuration::testCommPorts()
 {
-	int retval;
-
 	inpTTYdev->clear();
 	inpRIGdev->clear();
 	inpXmlRigDevice->clear();
@@ -909,6 +907,7 @@
 #endif
 
 #ifdef __linux__
+	int retval;
 	bool ret = false;
 	DIR* sys = NULL;
 	char cwd[PATH_MAX] = { '.', '\0' };
@@ -955,9 +954,7 @@
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
