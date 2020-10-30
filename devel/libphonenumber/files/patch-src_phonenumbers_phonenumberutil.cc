--- src/phonenumbers/phonenumberutil.cc.orig	2020-10-30 16:00:44 UTC
+++ src/phonenumbers/phonenumberutil.cc
@@ -114,10 +114,6 @@ const char kValidAlpha[] = "a-z";
 // prefix. This can be overridden by region-specific preferences.
 const char kDefaultExtnPrefix[] = " ext. ";
 
-// One-character symbols that can be used to indicate an extension.
-const char kSingleExtnSymbolsForMatching[] =
-    "x\xEF\xBD\x98#\xEF\xBC\x83~\xEF\xBD\x9E";
-
 const char kPossibleSeparatorsBetweenNumberAndExtLabel[] =
     "[ \xC2\xA0\\t,]*";
 
