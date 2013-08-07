--- src/xmlschemagenerator.cpp.orig	2013-08-07 15:53:21.000000000 +0200
+++ src/xmlschemagenerator.cpp	2013-08-07 15:54:00.000000000 +0200
@@ -203,7 +203,7 @@
 			continue;
 		for ( attrItr = attrMap.begin(); attrItr != attrMap.end(); attrItr++ )
 		{
-			const static wxMBConvUTF16 conv;
+			static wxMBConvUTF16 conv;
 			if ( attrs->getNamedItem ( ( const XMLCh * ) ( const char * )
 					attrItr->first.mb_str ( conv ) ) == NULL )
 			{
