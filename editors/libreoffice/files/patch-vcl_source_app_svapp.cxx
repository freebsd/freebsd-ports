--- vcl/source/app/svapp.cxx.orig	2019-02-04 10:17:39.490629000 +0800
+++ vcl/source/app/svapp.cxx	2019-02-04 10:47:26.591172000 +0800
@@ -1103,7 +1103,7 @@
         aDetails.append( VclResId(SV_APP_DEFAULT) );
     aDetails.append( "; " );
 
-#if (defined LINUX || defined _WIN32 || defined MACOSX)
+#if (defined LINUX || defined _WIN32 || defined MACOSX || defined FREEBSD)
     aDetails.append( SV_APP_VCLBACKEND );
     aDetails.append( GetToolkitName() );
     aDetails.append( "; " );
