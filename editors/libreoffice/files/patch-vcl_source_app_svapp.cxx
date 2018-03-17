--- vcl/source/app/svapp.cxx.orig	2018-03-02 19:30:13.692825000 +0800
+++ vcl/source/app/svapp.cxx	2018-03-02 19:30:48.236688000 +0800
@@ -1153,7 +1153,7 @@
         aDetails.append( VclResId(SV_APP_DEFAULT) );
     aDetails.append( "; " );
 
-#ifdef LINUX
+#if defined UNX && !defined MACOSX && !defined IOS && !defined ANDROID
     // Only linux has different backends, so don't show blank for others.
     aDetails.append( SV_APP_VCLBACKEND );
     aDetails.append( GetToolkitName() );
