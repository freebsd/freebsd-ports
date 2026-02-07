--- src/HexEditorCtrl/wxHexCtrl/wxHexCtrl.cpp.orig	2017-12-31 02:15:18 UTC
+++ src/HexEditorCtrl/wxHexCtrl/wxHexCtrl.cpp
@@ -557,7 +557,7 @@ inline wxDC* wxHexCtrl::UpdateDC(wxDC *xdc ){
 
 					//First half of byte
 					RenderedHexByte += CharAt(textLenghtLimit++);
-					chr = RenderedHexByte.ToAscii()[0];
+					chr = RenderedHexByte.ToAscii()[static_cast<size_t>(0)];
 					chrC = atoh( chr ) << 4;
 
 					//Space could be here
@@ -569,7 +569,7 @@ inline wxDC* wxHexCtrl::UpdateDC(wxDC *xdc ){
 
 					//Second half of byte.
 					RenderedHexByte += CharAt(textLenghtLimit++);
-					chr = RenderedHexByte.ToAscii()[1];
+					chr = RenderedHexByte.ToAscii()[static_cast<size_t>(1)];
 					chrC |= atoh( chr );
 					//chrC = (atoh( RenderedHexByte.ToAscii()[0] ) << 4) | atoh( RenderedHexByte.ToAscii()[1] );
 
@@ -2365,7 +2365,7 @@ cpformat(a)
 			else if(i==0x7E)
 				newCP += wxChar(0x203E);//Overline
 			else if(i<0x80)
-				newCP += ((i<0x20 || i==0x7F)	? '.' : wxChar(i));
+				newCP += ((i<0x20 || i==0x7F) ? L'.' : wxChar(i));
 			else if( i>=0xA1 && i<0xE0)
 				newCP += wxChar(i-0xA0+0xFF60);
 			else
