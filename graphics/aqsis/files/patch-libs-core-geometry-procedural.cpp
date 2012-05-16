--- libs/core/geometry/procedural.cpp.orig	2012-02-20 18:54:32.000000000 +0300
+++ libs/core/geometry/procedural.cpp	2012-02-20 18:54:50.000000000 +0300
@@ -155,7 +155,7 @@
 				          + CqString ("\" in current searchpath");
 				return;
 			}
-			CqString strRealName = dsoPath.file_string();
+			CqString strRealName = dsoPath.string();
 			void *handle = DLOpen( &strRealName );
 
 			if ( ( m_ppvfcts = ( void * ( * ) ( char * ) ) DLSym(handle, &strConver) ) == NULL )
@@ -315,7 +315,7 @@
 		AQSIS_THROW_XQERROR(XqValidation, EqE_BadToken, "program name not present");
 	// Attempt to find the program in the procedural path
 	std::string progName = QGetRenderContext()->poptCurrent()
-		->findRiFileNothrow(argv[0], "procedural").file_string();
+		->findRiFileNothrow(argv[0], "procedural").string();
 	if(progName.empty())
 	{
 		progName = argv[0];
