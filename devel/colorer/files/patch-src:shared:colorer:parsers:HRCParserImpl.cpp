--- src/shared/colorer/parsers/HRCParserImpl.cpp.orig	Fri Mar 26 11:36:50 2004
+++ src/shared/colorer/parsers/HRCParserImpl.cpp	Fri Mar 26 11:38:05 2004
@@ -366,6 +366,12 @@
 
     if (*tmpel->getName() == "inherit"){
       const String *nqSchemeName = tmpel->getParamValue(DString("scheme"));
+
+      if (nqSchemeName == null || nqSchemeName->length() == 0){
+        if (errorHandler != null) errorHandler->error(StringBuffer("empty scheme name in inheritance operator in scheme '")+scheme->schemeName+"'");
+          continue;
+      };
+
       next->type = SNT_INHERIT;
       next->schemeName = new SString(nqSchemeName);
       String *schemeName = qualifyForeignName(nqSchemeName, QNT_SCHEME, false);
