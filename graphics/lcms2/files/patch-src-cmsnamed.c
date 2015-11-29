--- src/cmsnamed.c.orig	2015-03-17 11:19:51 UTC
+++ src/cmsnamed.c
@@ -185,8 +185,19 @@ cmsBool CMSEXPORT cmsMLUsetASCII(cmsMLU*
     cmsUInt32Number i, len = (cmsUInt32Number) strlen(ASCIIString)+1;
     wchar_t* WStr;
     cmsBool  rc;
-    cmsUInt16Number Lang  = _cmsAdjustEndianess16(*(cmsUInt16Number*) LanguageCode);
-    cmsUInt16Number Cntry = _cmsAdjustEndianess16(*(cmsUInt16Number*) CountryCode);
+    union {
+        cmsUInt16Number uint16;
+        char str[2];
+    } code_convert;
+    cmsUInt16Number Lang;
+    cmsUInt16Number Cntry;
+
+    code_convert.str[0] = LanguageCode[0];
+    code_convert.str[1] = LanguageCode[1];
+    Lang = _cmsAdjustEndianess16(code_convert.uint16);
+    code_convert.str[0] = CountryCode[0];
+    code_convert.str[1] = CountryCode[1];
+    Cntry = _cmsAdjustEndianess16(code_convert.uint16);
 
     if (mlu == NULL) return FALSE;
 
@@ -220,10 +231,22 @@ cmsUInt32Number mywcslen(const wchar_t *
 // Add a wide entry
 cmsBool  CMSEXPORT cmsMLUsetWide(cmsMLU* mlu, const char Language[3], const char Country[3], const wchar_t* WideString)
 {
-    cmsUInt16Number Lang  = _cmsAdjustEndianess16(*(cmsUInt16Number*) Language);
-    cmsUInt16Number Cntry = _cmsAdjustEndianess16(*(cmsUInt16Number*) Country);
     cmsUInt32Number len;
 
+    union {
+        cmsUInt16Number uint16;
+        char str[2];
+    } code_convert;
+    cmsUInt16Number Lang;
+    cmsUInt16Number Cntry;
+
+    code_convert.str[0] = Language[0];
+    code_convert.str[1] = Language[1];
+    Lang = _cmsAdjustEndianess16(code_convert.uint16);
+    code_convert.str[0] = Country[0];
+    code_convert.str[1] = Country[1];
+    Cntry = _cmsAdjustEndianess16(code_convert.uint16);
+
     if (mlu == NULL) return FALSE;
     if (WideString == NULL) return FALSE;
 
@@ -350,8 +373,19 @@ cmsUInt32Number CMSEXPORT cmsMLUgetASCII
     cmsUInt32Number  StrLen = 0;
     cmsUInt32Number ASCIIlen, i;
 
-    cmsUInt16Number Lang  = _cmsAdjustEndianess16(*(cmsUInt16Number*) LanguageCode);
-    cmsUInt16Number Cntry = _cmsAdjustEndianess16(*(cmsUInt16Number*) CountryCode);
+    union {
+        cmsUInt16Number uint16;
+        char str[2];
+    } code_convert;
+    cmsUInt16Number Lang;
+    cmsUInt16Number Cntry;
+
+    code_convert.str[0] = LanguageCode[0];
+    code_convert.str[1] = LanguageCode[1];
+    Lang = _cmsAdjustEndianess16(code_convert.uint16);
+    code_convert.str[0] = CountryCode[0];
+    code_convert.str[1] = CountryCode[1];
+    Cntry = _cmsAdjustEndianess16(code_convert.uint16);
 
     // Sanitize
     if (mlu == NULL) return 0;
@@ -394,8 +428,19 @@ cmsUInt32Number CMSEXPORT cmsMLUgetWide(
     const wchar_t *Wide;
     cmsUInt32Number  StrLen = 0;
 
-    cmsUInt16Number Lang  = _cmsAdjustEndianess16(*(cmsUInt16Number*) LanguageCode);
-    cmsUInt16Number Cntry = _cmsAdjustEndianess16(*(cmsUInt16Number*) CountryCode);
+    union {
+        cmsUInt16Number uint16;
+        char str[2];
+    } code_convert;
+    cmsUInt16Number Lang;
+    cmsUInt16Number Cntry;
+
+    code_convert.str[0] = LanguageCode[0];
+    code_convert.str[1] = LanguageCode[1];
+    Lang = _cmsAdjustEndianess16(code_convert.uint16);
+    code_convert.str[0] = CountryCode[0];
+    code_convert.str[1] = CountryCode[1];
+    Cntry = _cmsAdjustEndianess16(code_convert.uint16);
 
     // Sanitize
     if (mlu == NULL) return 0;
@@ -427,10 +472,20 @@ CMSAPI cmsBool CMSEXPORT cmsMLUgetTransl
 {
     const wchar_t *Wide;
 
-    cmsUInt16Number Lang  = _cmsAdjustEndianess16(*(cmsUInt16Number*) LanguageCode);
-    cmsUInt16Number Cntry = _cmsAdjustEndianess16(*(cmsUInt16Number*) CountryCode);
     cmsUInt16Number ObtLang, ObtCode;
 
+    union {
+        cmsUInt16Number uint16;
+        char str[3];
+    } code_convert;
+    cmsUInt16Number Lang;
+    cmsUInt16Number Cntry;
+
+    strcpy(code_convert.str, LanguageCode);
+    Lang = _cmsAdjustEndianess16(code_convert.uint16);
+    strcpy(code_convert.str, CountryCode);
+    Cntry = _cmsAdjustEndianess16(code_convert.uint16);
+
     // Sanitize
     if (mlu == NULL) return FALSE;
 
