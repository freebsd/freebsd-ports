--- ./src/plugins/android/androidconfigurations.h.orig	2012-09-10 07:29:16.000000000 -0700
+++ ./src/plugins/android/androidconfigurations.h	2012-09-15 16:15:01.085988267 -0700
@@ -52,8 +52,12 @@
 #  ifdef Q_OS_WIN32
     const QLatin1String ToolchainHost("windows");
 #  else
-#  warning No Android supported OSs found
+#   ifdef Q_OS_FREEBSD
+    const QLatin1String ToolchainHost("freebsd-x86");
+#   else
+#   warning No Android supported OSs found
     const QLatin1String ToolchainHost("linux-x86");
+#   endif
 #  endif
 # endif
 #endif
