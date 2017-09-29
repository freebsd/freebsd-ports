In file included from libs/tex/filtering/dummytexturesampler.cpp:38:
In file included from libs/tex/filtering/dummytexturesampler.h:41:
In file included from include/aqsis/tex/filtering/itexturesampler.h:46:
include/aqsis/tex/filtering/texturesampleoptions.h:239:31: error: ISO C++11 does not allow access declarations; use using declarations instead
                CqTextureSampleOptionsBase::sBlur;
                                            ^
                using
include/aqsis/tex/filtering/texturesampleoptions.h:240:31: error: ISO C++11 does not allow access declarations; use using declarations instead
                CqTextureSampleOptionsBase::tBlur;
                                            ^
                using
include/aqsis/tex/filtering/texturesampleoptions.h:241:31: error: ISO C++11 does not allow access declarations; use using declarations instead
                CqTextureSampleOptionsBase::sWidth;
                                            ^
                using
[...]

--- include/aqsis/tex/filtering/texturesampleoptions.h.orig	2012-08-24 12:26:50 UTC
+++ include/aqsis/tex/filtering/texturesampleoptions.h
@@ -236,37 +236,37 @@ class CqTextureSampleOptions : private CqTextureSample
 		CqTextureSampleOptions();
 
 		// Accessors from CqTextureSampleOptionsBase
-		CqTextureSampleOptionsBase::sBlur;
-		CqTextureSampleOptionsBase::tBlur;
-		CqTextureSampleOptionsBase::sWidth;
-		CqTextureSampleOptionsBase::tWidth;
-		CqTextureSampleOptionsBase::minWidth;
-		CqTextureSampleOptionsBase::truncAmount;
-		CqTextureSampleOptionsBase::logTruncAmount;
-		CqTextureSampleOptionsBase::filterType;
-		CqTextureSampleOptionsBase::startChannel;
-		CqTextureSampleOptionsBase::numChannels;
-		CqTextureSampleOptionsBase::sWrapMode;
-		CqTextureSampleOptionsBase::tWrapMode;
+		using CqTextureSampleOptionsBase::sBlur;
+		using CqTextureSampleOptionsBase::tBlur;
+		using CqTextureSampleOptionsBase::sWidth;
+		using CqTextureSampleOptionsBase::tWidth;
+		using CqTextureSampleOptionsBase::minWidth;
+		using CqTextureSampleOptionsBase::truncAmount;
+		using CqTextureSampleOptionsBase::logTruncAmount;
+		using CqTextureSampleOptionsBase::filterType;
+		using CqTextureSampleOptionsBase::startChannel;
+		using CqTextureSampleOptionsBase::numChannels;
+		using CqTextureSampleOptionsBase::sWrapMode;
+		using CqTextureSampleOptionsBase::tWrapMode;
 
 		// Modifiers from CqTextureSampleOptionsBase
-		CqTextureSampleOptionsBase::setBlur;
-		CqTextureSampleOptionsBase::setSBlur;
-		CqTextureSampleOptionsBase::setTBlur;
-		CqTextureSampleOptionsBase::setWidth;
-		CqTextureSampleOptionsBase::setSWidth;
-		CqTextureSampleOptionsBase::setTWidth;
-		CqTextureSampleOptionsBase::setMinWidth;
-		CqTextureSampleOptionsBase::setTruncAmount;
-		CqTextureSampleOptionsBase::setFilterType;
-		CqTextureSampleOptionsBase::setStartChannel;
-		CqTextureSampleOptionsBase::setNumChannels;
-		CqTextureSampleOptionsBase::setWrapMode;
-		CqTextureSampleOptionsBase::setSWrapMode;
-		CqTextureSampleOptionsBase::setTWrapMode;
+		using CqTextureSampleOptionsBase::setBlur;
+		using CqTextureSampleOptionsBase::setSBlur;
+		using CqTextureSampleOptionsBase::setTBlur;
+		using CqTextureSampleOptionsBase::setWidth;
+		using CqTextureSampleOptionsBase::setSWidth;
+		using CqTextureSampleOptionsBase::setTWidth;
+		using CqTextureSampleOptionsBase::setMinWidth;
+		using CqTextureSampleOptionsBase::setTruncAmount;
+		using CqTextureSampleOptionsBase::setFilterType;
+		using CqTextureSampleOptionsBase::setStartChannel;
+		using CqTextureSampleOptionsBase::setNumChannels;
+		using CqTextureSampleOptionsBase::setWrapMode;
+		using CqTextureSampleOptionsBase::setSWrapMode;
+		using CqTextureSampleOptionsBase::setTWrapMode;
 
 		// Other stuff from CqTextureSampleOptionsBase
-		CqTextureSampleOptionsBase::fillFromFileHeader;
+		using CqTextureSampleOptionsBase::fillFromFileHeader;
 
 		//--------------------------------------------------
 		// Plain-texture specific sample options
@@ -307,37 +307,37 @@ class CqShadowSampleOptions : private CqTextureSampleO
 		CqShadowSampleOptions();
 
 		// Accessors from CqTextureSampleOptionsBase
-		CqTextureSampleOptionsBase::sBlur;
-		CqTextureSampleOptionsBase::tBlur;
-		CqTextureSampleOptionsBase::sWidth;
-		CqTextureSampleOptionsBase::tWidth;
-		CqTextureSampleOptionsBase::minWidth;
-		CqTextureSampleOptionsBase::truncAmount;
-		CqTextureSampleOptionsBase::logTruncAmount;
-		CqTextureSampleOptionsBase::filterType;
-		CqTextureSampleOptionsBase::startChannel;
-		CqTextureSampleOptionsBase::numChannels;
-		CqTextureSampleOptionsBase::sWrapMode;
-		CqTextureSampleOptionsBase::tWrapMode;
+		using CqTextureSampleOptionsBase::sBlur;
+		using CqTextureSampleOptionsBase::tBlur;
+		using CqTextureSampleOptionsBase::sWidth;
+		using CqTextureSampleOptionsBase::tWidth;
+		using CqTextureSampleOptionsBase::minWidth;
+		using CqTextureSampleOptionsBase::truncAmount;
+		using CqTextureSampleOptionsBase::logTruncAmount;
+		using CqTextureSampleOptionsBase::filterType;
+		using CqTextureSampleOptionsBase::startChannel;
+		using CqTextureSampleOptionsBase::numChannels;
+		using CqTextureSampleOptionsBase::sWrapMode;
+		using CqTextureSampleOptionsBase::tWrapMode;
 
 		// Modifiers from CqTextureSampleOptionsBase
-		CqTextureSampleOptionsBase::setBlur;
-		CqTextureSampleOptionsBase::setSBlur;
-		CqTextureSampleOptionsBase::setTBlur;
-		CqTextureSampleOptionsBase::setWidth;
-		CqTextureSampleOptionsBase::setSWidth;
-		CqTextureSampleOptionsBase::setTWidth;
-		CqTextureSampleOptionsBase::setMinWidth;
-		CqTextureSampleOptionsBase::setTruncAmount;
-		CqTextureSampleOptionsBase::setFilterType;
-		CqTextureSampleOptionsBase::setStartChannel;
-		CqTextureSampleOptionsBase::setNumChannels;
-		CqTextureSampleOptionsBase::setWrapMode;
-		CqTextureSampleOptionsBase::setSWrapMode;
-		CqTextureSampleOptionsBase::setTWrapMode;
+		using CqTextureSampleOptionsBase::setBlur;
+		using CqTextureSampleOptionsBase::setSBlur;
+		using CqTextureSampleOptionsBase::setTBlur;
+		using CqTextureSampleOptionsBase::setWidth;
+		using CqTextureSampleOptionsBase::setSWidth;
+		using CqTextureSampleOptionsBase::setTWidth;
+		using CqTextureSampleOptionsBase::setMinWidth;
+		using CqTextureSampleOptionsBase::setTruncAmount;
+		using CqTextureSampleOptionsBase::setFilterType;
+		using CqTextureSampleOptionsBase::setStartChannel;
+		using CqTextureSampleOptionsBase::setNumChannels;
+		using CqTextureSampleOptionsBase::setWrapMode;
+		using CqTextureSampleOptionsBase::setSWrapMode;
+		using CqTextureSampleOptionsBase::setTWrapMode;
 
 		// Other stuff from CqTextureSampleOptionsBase
-		CqTextureSampleOptionsBase::fillFromFileHeader;
+		using CqTextureSampleOptionsBase::fillFromFileHeader;
 
 		//--------------------------------------------------
 		// Shadow-specific sample options
