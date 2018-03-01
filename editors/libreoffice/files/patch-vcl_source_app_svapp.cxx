--- vcl/source/app/svapp.cxx.orig	2017-10-25 14:25:39 UTC
+++ vcl/source/app/svapp.cxx
@@ -1212,7 +1212,7 @@ OUString Application::GetHWOSConfInfo()
         aDetails.append( VclResId(SV_APP_DEFAULT).toString() );
     aDetails.append( "; " );
 
-#ifdef LINUX
+#if defined UNX && !defined MACOSX && !defined IOS && !defined ANDROID
     // Only linux has different backends, so don't show blank for others.
     aDetails.append( VclResId(SV_APP_VCLBACKEND).toString() );
     aDetails.append( GetToolkitName() );
