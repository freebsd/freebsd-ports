*** lib/database/src/so/nodes/SoText2.c++.orig	Tue Sep 25 00:45:41 2001
--- lib/database/src/so/nodes/SoText2.c++	Mon Dec 23 13:28:11 2002
***************
*** 778,784 ****
  	size_t outbytes = 2*inbytes+2;
  	char* output = (char*)UCSStrings[i];
      
! 	if ((iconv(conversionCode, &input, &inbytes, &output, &outbytes) == (size_t)-1)){
  #ifdef DEBUG
  	    SoDebugError::post("SoBitmapFontCache::convertToUCS", 
  		"Error converting text to UCS-2");
--- 778,784 ----
  	size_t outbytes = 2*inbytes+2;
  	char* output = (char*)UCSStrings[i];
      
! 	if ((iconv(conversionCode, (const char **)&input, &inbytes, &output, &outbytes) == (size_t)-1)){
  #ifdef DEBUG
  	    SoDebugError::post("SoBitmapFontCache::convertToUCS", 
  		"Error converting text to UCS-2");
***************
*** 1498,1503 ****
--- 1498,1504 ----
      // And some font library stuff:
      static FLcontext	flContext;
      FLfontNumber	fontId;
+     GLubyte* fontNumList;
  };
      
  SO_NODE_SOURCE(SoText2);
