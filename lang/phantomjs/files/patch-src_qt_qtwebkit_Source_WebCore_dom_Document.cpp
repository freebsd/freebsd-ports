Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

In file included from dom/DOMAllInOne.cpp:62:
dom/Document.cpp:3849:39: error: expected ';' after do/while statement
    U16_NEXT(characters, i, length, c)
                                      ^
                                      ;
dom/Document.cpp:3854:43: error: expected ';' after do/while statement
        U16_NEXT(characters, i, length, c)
                                          ^
                                          ;
dom/Document.cpp:3917:34: error: expected ';' after do/while statement
        U16_NEXT(s, i, length, c)
                                 ^
                                 ;

--- src/qt/qtwebkit/Source/WebCore/dom/Document.cpp.orig	2016-01-08 10:07:46 UTC
+++ src/qt/qtwebkit/Source/WebCore/dom/Document.cpp
@@ -3846,12 +3846,12 @@ static bool isValidNameNonASCII(const UChar* character
     unsigned i = 0;
 
     UChar32 c;
-    U16_NEXT(characters, i, length, c)
+    U16_NEXT(characters, i, length, c);
     if (!isValidNameStart(c))
         return false;
 
     while (i < length) {
-        U16_NEXT(characters, i, length, c)
+        U16_NEXT(characters, i, length, c);
         if (!isValidNamePart(c))
             return false;
     }
@@ -3914,7 +3914,7 @@ bool Document::parseQualifiedName(const String& qualif
     const UChar* s = qualifiedName.characters();
     for (unsigned i = 0; i < length;) {
         UChar32 c;
-        U16_NEXT(s, i, length, c)
+        U16_NEXT(s, i, length, c);
         if (c == ':') {
             if (sawColon) {
                 ec = NAMESPACE_ERR;
