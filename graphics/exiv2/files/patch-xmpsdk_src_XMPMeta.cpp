XMP code is not dealing with format types properly. Cast argument to match format string.

filed as https://github.com/Exiv2/exiv2/pull/2671

--- xmpsdk/src/XMPMeta.cpp.orig	2023-05-08 16:01:13 UTC
+++ xmpsdk/src/XMPMeta.cpp
@@ -87,7 +87,7 @@ static const char * kTenSpaces = "          ";
 #define OutProcHexInt(num)	{ snprintf ( buffer, sizeof(buffer), "%X", (num) ); /* AUDIT: Using sizeof for snprintf length is safe */	\
 							  status = (*outProc) ( refCon, buffer, strlen(buffer) );  if ( status != 0 ) goto EXIT; }
 #else
-#define OutProcHexInt(num)	{ snprintf ( buffer, sizeof(buffer), "%lX", (num) ); /* AUDIT: Using sizeof for snprintf length is safe */	\
+#define OutProcHexInt(num)	{ snprintf ( buffer, sizeof(buffer), "%lX", (long)(num) ); /* AUDIT: Using sizeof for snprintf length is safe */	\
 							  status = (*outProc) ( refCon, buffer, strlen(buffer) );  if ( status != 0 ) goto EXIT; }
 #endif
 
