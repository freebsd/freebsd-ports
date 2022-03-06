--- pcbnew/dialogs/dialog_board_reannotate.cpp.orig	2022-03-03 17:16:00 UTC
+++ pcbnew/dialogs/dialog_board_reannotate.cpp
@@ -522,7 +522,7 @@ void DIALOG_BOARD_REANNOTATE::LogChangePlan()
                     (int) m_refDesTypes.size() );
 
     for( RefDesTypeStr Type : m_refDesTypes ) // Show all the types of refdes
-        message += Type.RefDesType + ( 0 == ( i++ % 16 ) ? wxT( "\n" ) : wxS( " " ) );
+        message += Type.RefDesType + ( 0 == ( i++ % 16 ) ? wxT( "\n" ) : wxT( " " ) );
 
     if( !m_excludeArray.empty() )
     {
