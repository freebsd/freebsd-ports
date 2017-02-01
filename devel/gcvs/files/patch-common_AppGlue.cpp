--- common/AppGlue.cpp.orig	2002-03-12 18:34:31 UTC
+++ common/AppGlue.cpp
@@ -260,7 +260,7 @@ CVS_EXTERN_C const char *glue_getenv(cha
 		// extract from the cvsroot
 		const char *ccvsroot = gCvsPrefs;
 		ccvsroot = Authen::skiptoken(ccvsroot);
-		char *login = strchr(ccvsroot, '@');
+		const char *login = strchr(ccvsroot, '@');
 		if(login == NULL)
 		{
 			// for WIN32 this means the CVSROOT is local
