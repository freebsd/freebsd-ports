--- src/projection/ossimRpcModel.cpp.orig	2019-03-28 19:14:59 UTC
+++ src/projection/ossimRpcModel.cpp
@@ -920,7 +920,7 @@ bool ossimRpcModel::loadState(const ossimKeywordlist& 
                                           << std::endl;
       return false;
    }
-   thePolyType = (PolynomialType) value[0];
+   thePolyType = (PolynomialType)value.at(0);
       
    keyword = LINE_SCALE_KW;
    value = kwl.find(prefix, keyword);
