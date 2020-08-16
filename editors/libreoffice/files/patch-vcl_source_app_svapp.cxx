--- vcl/source/app/svapp.cxx.orig	2020-05-27 12:17:53 UTC
+++ vcl/source/app/svapp.cxx
@@ -1183,7 +1183,7 @@ OUString Application::GetHWOSConfInfo(const int bSelec
 #endif
             appendDetails("", VclResId(SV_APP_DEFAULT));
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined FREEBSD)
         appendDetails("; ", SV_APP_VCLBACKEND + GetToolkitName());
 #endif
     }
