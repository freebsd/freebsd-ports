--- src/im/account.cpp.orig	2011-12-04 14:24:51 UTC
+++ src/im/account.cpp
@@ -18,6 +18,7 @@
 
 #include <cassert>
 #include <cstring>
+#include <unistd.h>
 #ifdef HAVE_IMLIB
 	#include <Imlib2.h>
 #endif /* HAVE_IMLIB */
@@ -272,7 +273,7 @@ void Account::setBuddyIcon(string filena
 				else
 				{
 					char** prpl_formats = g_strsplit(prplinfo->icon_spec.format,",",0);
-					ImlibLoadError err = IMLIB_LOAD_ERROR_UNKNOWN;
+					Imlib_Load_Error err = IMLIB_LOAD_ERROR_UNKNOWN;
 
 					close(temp_fd);
 					/* Try to encode in a supported format. */
