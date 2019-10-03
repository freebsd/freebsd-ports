Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

In file included from modules/web/build/bsd/Release/DerivedSources/WebCore/unified-sources/UnifiedSource220.cpp:4:
modules/web/src/main/native/Source/WebCore/dom/Document.cpp:4707:39: error: expected ';' after do/while statement
    U16_NEXT(characters, i, length, c)
                                      ^
                                      ;
modules/web/src/main/native/Source/WebCore/dom/Document.cpp:4712:43: error: expected ';' after do/while statement
        U16_NEXT(characters, i, length, c)
                                          ^
                                          ;
modules/web/src/main/native/Source/WebCore/dom/Document.cpp:4772:46: error: expected ';' after do/while statement
        U16_NEXT(qualifiedName, i, length, c)
                                             ^
                                             ;

--- modules/web/src/main/native/Source/WebCore/dom/Document.cpp.orig	2018-12-10 16:30:22 UTC
+++ modules/web/src/main/native/Source/WebCore/dom/Document.cpp
@@ -4704,12 +4704,12 @@ static bool isValidNameNonASCII(const UChar* character
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
@@ -4769,7 +4769,7 @@ ExceptionOr<std::pair<AtomicString, AtomicString>> Doc
 
     for (unsigned i = 0; i < length; ) {
         UChar32 c;
-        U16_NEXT(qualifiedName, i, length, c)
+        U16_NEXT(qualifiedName, i, length, c);
         if (c == ':') {
             if (sawColon)
                 return Exception { InvalidCharacterError };
