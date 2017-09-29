libs/core/texturing_old/shadowmap_old.cpp: In member function 'void Aqsis::CqShadowMapOld::LoadZFile()':
libs/core/texturing_old/shadowmap_old.cpp:179:13: error: no match for 'operator!=' (operand types are 'std::ifstream {aka std::basic_ifstream<char>}' and 'long int')
   if ( file != NULL )
             ^

--- libs/core/texturing_old/shadowmap_old.cpp.orig	2012-08-24 12:26:50 UTC
+++ libs/core/texturing_old/shadowmap_old.cpp
@@ -176,7 +176,7 @@ void CqShadowMapOld::LoadZFile()
 	{
 		std::ifstream file( m_strName.c_str(), std::ios::in | std::ios::binary );
 
-		if ( file != NULL )
+		if ( file )
 		{
 			// Save a file type and version marker
 			TqPchar origHeader = tokenCast(ZFILE_HEADER);
