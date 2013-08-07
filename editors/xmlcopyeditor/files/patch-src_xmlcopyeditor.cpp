--- src/xmlcopyeditor.cpp.orig	2013-08-07 15:31:32.000000000 +0200
+++ src/xmlcopyeditor.cpp	2013-08-07 15:35:13.000000000 +0200
@@ -2887,7 +2887,7 @@
 
 		const int arraySize = templateArray.GetCount();
 
-		wxString choiceArray[arraySize + 1];
+		wxString *choiceArray = new wxString[arraySize + 1];
 		for ( int i = 0; i < arraySize; ++i )
 			* ( choiceArray + i ) = templateArray.Item ( i );
 
@@ -2901,6 +2901,7 @@
 			return;
 		}
 		typeSelection = scd.GetStringSelection();
+        delete [] choiceArray;
 	}
 
 	if ( typeSelection == defaultSelection )
@@ -4384,20 +4385,23 @@
 	encodingVector.push_back ( _T ( "ISO-8859-1" ) );
 	encodingVector.push_back ( _T ( "US-ASCII" ) );
 	const int vectorSize = encodingVector.size();
-	wxString choiceArray[vectorSize + 1];
+	wxString *choiceArray = new wxString[vectorSize + 1];
 	for ( int i = 0; i < vectorSize; ++i )
 		* ( choiceArray + i ) = encodingVector.at ( i );
 	wxSingleChoiceDialog scd (
 	    this, _ ( "Choose an encoding:" ), _ ( "Encoding" ), vectorSize, choiceArray );
 
-	if ( scd.ShowModal() == wxID_CANCEL )
+	if ( scd.ShowModal() == wxID_CANCEL ) {
+        delete [] choiceArray;
 		return;
+    }
 
 	wxString selection;
 	std::string selectionUtf8, bufferUtf8;
 
 	selection = scd.GetStringSelection();
 	selectionUtf8 = selection.mb_str ( wxConvUTF8 );
+    delete [] choiceArray;
 
 	getRawText ( doc, bufferUtf8 );
 	XmlEncodingHandler::setUtf8 ( bufferUtf8, true );
