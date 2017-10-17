libs/shadervm/shaderexecenv/shadeops_tmap.cpp:257:56: error: ISO C++11 does not allow access declarations; use using declarations instead
                CqSampleOptionExtractorBase<CqTextureSampleOptions>::extractVarying;
                                                                     ^
                using

--- libs/shadervm/shaderexecenv/shadeops_tmap.cpp.orig	2012-08-24 12:26:50 UTC
+++ libs/shadervm/shaderexecenv/shadeops_tmap.cpp
@@ -254,7 +254,7 @@ class CqSampleOptionExtractor
 			extractUniformAndCacheVarying(paramList, numParams, opts);
 		}
 
-		CqSampleOptionExtractorBase<CqTextureSampleOptions>::extractVarying;
+		using CqSampleOptionExtractorBase<CqTextureSampleOptions>::extractVarying;
 };
 
 
