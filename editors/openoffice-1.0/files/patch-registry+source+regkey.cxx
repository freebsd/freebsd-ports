--- registry/source/regkey.cxx.orig	Mon Mar 11 01:27:56 2002
+++ registry/source/regkey.cxx	Mon Mar 11 01:28:51 2002
@@ -228,6 +228,9 @@
 {
 	RegError _ret = REG_NO_ERROR;
 
+       if (!nSubKeys)
+		return REG_NO_ERROR;
+
 	if (phSubKeys)
 	{
 		ORegistry* pReg = NULL;
