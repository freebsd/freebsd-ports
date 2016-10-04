--- src/scripttabs.cpp.orig	2016-05-07 17:45:17 UTC
+++ src/scripttabs.cpp
@@ -108,7 +108,7 @@ TYPE_SYMBOL asTypeTable[] =
 	{ "",	(INTERP_TYPE)ST_POINTER_STRUCTSTAT, AT_SIMPLE, NULL, NULL },	//for NULLSTRUCTURESTAT
 
 	/* This final entry marks the end of the type list */
-	{ "END OF TYPE LIST", (INTERP_TYPE)NULL,		AT_SIMPLE,	NULL,	NULL },
+	{ "END OF TYPE LIST", (INTERP_TYPE)0,		AT_SIMPLE,	NULL,	NULL },
 };
 
 
