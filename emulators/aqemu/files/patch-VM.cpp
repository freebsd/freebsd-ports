--- VM.cpp.orig	2011-07-26 19:36:32 UTC
+++ VM.cpp
@@ -4563,7 +4563,7 @@ bool Virtual_Machine::Load_VM( const QSt
 				else
 					AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )", "SPICE image compression type invalid!" );
 				
-				SPICE.Use_Video_Stream_Compression( Second_Element.firstChildElement( ! "Use_Video_Stream_Compression" ).text() == "false" );
+				SPICE.Use_Video_Stream_Compression( ! (Second_Element.firstChildElement( "Use_Video_Stream_Compression" ).text() == "false") );
 				
 				SPICE.Use_Renderer( Second_Element.firstChildElement( "Use_Renderer" ).text() == "true" );
 				
@@ -4595,7 +4595,7 @@ bool Virtual_Machine::Load_VM( const QSt
 						SPICE.Set_Renderer_List( rendererList );
 				}
 				
-				SPICE.Use_Playback_Compression( Second_Element.firstChildElement( ! "Use_Playback_Compression" ).text() == "false" );
+				SPICE.Use_Playback_Compression( ! (Second_Element.firstChildElement( "Use_Playback_Compression" ).text() == "false") );
 				
 				SPICE.Use_Password( Second_Element.firstChildElement( "Use_Password" ).text() == "true" );
 				
