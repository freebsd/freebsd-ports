Fix build with FOX 1.7.80

--- src/GMFilename.cpp.orig	2022-10-28 03:22:22 UTC
+++ src/GMFilename.cpp
@@ -102,7 +102,11 @@ FXString TextConverter::apply_filters(const FXString &
       else if (modifiers&UPPERCASE)
         n+=wc2utf(Unicode::toUpper(src.wc(i)));
       else
+#if FOXVERSION >= FXVERSION(1,7, 80)
+        n+=lenUTF8(src[i]);
+#else
         n+=src.extent(i);
+#endif
       }
     }
 
@@ -167,7 +171,11 @@ FXString TextConverter::apply_codec(const FXString & s
     else if (Unicode::isPrint(src.wc(i))) {
       if (codec->wc2mb(&c,1,src.wc(i))==1) {
         if (c==undefined_character) {
+#if FOXVERSION >= FXVERSION(1,7,80)
+          FXString dcm = FXString::decompose(src.mid(i,lenUTF8(src[i])),false);
+#else
           FXString dcm = FXString::decompose(src.mid(i,src.extent(i)),false);
+#endif
           for (FXint j=0;j<dcm.length();j+=dcm.inc(j)) {
             if (Unicode::isPrint(dcm.wc(j)) && codec->wc2mb(&c,1,dcm.wc(j)) && c!=0x1a) {
               n++;
@@ -190,7 +198,11 @@ FXString TextConverter::apply_codec(const FXString & s
         if (c==undefined_character) {
           /* If codec didn't contain a mapping to the required character,
              do a compatibility decomposition and try mapping those */
+#if FOXVERSION >= FXVERSION(1,7,80)
+          FXString dcm = FXString::decompose(src.mid(i,lenUTF8(src[i])),false);
+#else
           FXString dcm = FXString::decompose(src.mid(i,src.extent(i)),false);
+#endif
           for (FXint j=0;j<dcm.length();j+=dcm.inc(j)) {
             if (Unicode::isPrint(dcm.wc(j)) && codec->wc2mb(&c,1,dcm.wc(j)) && c!=undefined_character) {
               dst[n++]=c;
