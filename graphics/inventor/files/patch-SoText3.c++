*** lib/database/src/so/nodes/SoText3.c++.orig	Mon Dec 23 13:37:59 2002
--- lib/database/src/so/nodes/SoText3.c++	Mon Dec 23 13:38:15 2002
***************
*** 2291,2297 ****
  	size_t outbytes = 2*inbytes+2;
  	char* output = (char*)UCSStrings[i];
      
! 	if ((iconv(conversionCode, &input, &inbytes, &output, &outbytes) == (size_t)-1)){
  #ifdef DEBUG
  	    SoDebugError::post("SoOutlineFontCache::convertToUCS", 
  		"Error converting text to UCS-2");
--- 2291,2297 ----
  	size_t outbytes = 2*inbytes+2;
  	char* output = (char*)UCSStrings[i];
      
! 	if ((iconv(conversionCode, (const char **)&input, &inbytes, &output, &outbytes) == (size_t)-1)){
  #ifdef DEBUG
  	    SoDebugError::post("SoOutlineFontCache::convertToUCS", 
  		"Error converting text to UCS-2");
