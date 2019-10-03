Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

platform/graphics/SegmentedFontData.cpp:64:43: error: expected ';' after do/while statement
        U16_NEXT(characters, i, length, c)
                                          ^
                                          ;

--- src/qt/qtwebkit/Source/WebCore/platform/graphics/SegmentedFontData.cpp.orig	2016-01-08 10:07:46 UTC
+++ src/qt/qtwebkit/Source/WebCore/platform/graphics/SegmentedFontData.cpp
@@ -61,7 +61,7 @@ bool SegmentedFontData::containsCharacters(const UChar
 {
     UChar32 c;
     for (int i = 0; i < length; ) {
-        U16_NEXT(characters, i, length, c)
+        U16_NEXT(characters, i, length, c);
         if (!containsCharacter(c))
             return false;
     }
