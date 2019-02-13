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
 
