--- ../stoc/source/implementationregistration/implreg.cxx.orig	Mon Mar 11 20:08:04 2002
+++ ../stoc/source/implementationregistration/implreg.cxx	Mon Mar 11 19:55:02 2002
@@ -192,7 +192,7 @@
         tmpPath = buf.makeStringAndClear();
     }
     // I am the only one to own tmpPath here, so the cast is tolerateable.
-    OSL_VERIFY( tmpPath.getStr() == mktemp( (sal_Char * ) tmpPath.getStr() ) );
+    OSL_VERIFY( (sal_Char * ) tmpPath.getStr() == (sal_Char * ) mktemp( (sal_Char * ) tmpPath.getStr() ) );
 	return OStringToOUString( tmpPath, osl_getThreadTextEncoding());
 }
 
