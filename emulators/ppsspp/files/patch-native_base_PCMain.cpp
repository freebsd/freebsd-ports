--- native/base/PCMain.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/base/PCMain.cpp
@@ -243,53 +243,53 @@ void System_SendMessage(const char *comm
 }
 
 void LaunchBrowser(const char *url) {
-#ifdef _WIN32
+#if defined(MOBILE_DEVICE)
+	ILOG("Would have gone to %s but LaunchBrowser is not implemented on this platform", url);
+#elif defined(_WIN32)
 	ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
-#elif __linux__
+#elif defined(__APPLE__)
+	std::string command = std::string("open ") + url;
+	system(command.c_str());
+#else
 	std::string command = std::string("xdg-open ") + url;
 	int err = system(command.c_str());
 	if (err) {
 		ILOG("Would have gone to %s but xdg-utils seems not to be installed", url)
 	}
-#elif __APPLE__
-	std::string command = std::string("open ") + url;
-	system(command.c_str());
-#else
-	ILOG("Would have gone to %s but LaunchBrowser is not implemented on this platform", url);
 #endif
 }
 
 void LaunchMarket(const char *url) {
-#ifdef _WIN32
+#if defined(MOBILE_DEVICE)
+	ILOG("Would have gone to %s but LaunchMarket is not implemented on this platform", url);
+#elif defined(_WIN32)
 	ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
-#elif __linux__
+#elif defined(__APPLE__)
+	std::string command = std::string("open ") + url;
+	system(command.c_str());
+#else
 	std::string command = std::string("xdg-open ") + url;
 	int err = system(command.c_str());
 	if (err) {
 		ILOG("Would have gone to %s but xdg-utils seems not to be installed", url)
 	}
-#elif __APPLE__
-	std::string command = std::string("open ") + url;
-	system(command.c_str());
-#else
-	ILOG("Would have gone to %s but LaunchMarket is not implemented on this platform", url);
 #endif
 }
 
 void LaunchEmail(const char *email_address) {
-#ifdef _WIN32
+#if defined(MOBILE_DEVICE)
+	ILOG("Would have opened your email client for %s but LaunchEmail is not implemented on this platform", email_address);
+#elif defined(_WIN32)
 	ShellExecute(NULL, "open", (std::string("mailto:") + email_address).c_str(), NULL, NULL, SW_SHOWNORMAL);
-#elif __linux__
+#elif defined(__APPLE__)
+	std::string command = std::string("open mailto:") + email_address;
+	system(command.c_str());
+#else
 	std::string command = std::string("xdg-email ") + email_address;
 	int err = system(command.c_str());
 	if (err) {
 		ILOG("Would have gone to %s but xdg-utils seems not to be installed", email_address)
 	}
-#elif __APPLE__
-	std::string command = std::string("open mailto:") + email_address;
-	system(command.c_str());
-#else
-	ILOG("Would have opened your email client for %s but LaunchEmail is not implemented on this platform", email_address);
 #endif
 }
 
