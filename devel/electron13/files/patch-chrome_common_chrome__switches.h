--- chrome/common/chrome_switches.h.orig	2021-07-15 19:13:34 UTC
+++ chrome/common/chrome_switches.h
@@ -253,7 +253,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
