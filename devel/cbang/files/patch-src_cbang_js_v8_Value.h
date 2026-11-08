--- src/cbang/js/v8/Value.h.orig	2026-06-01 05:31:12 UTC
+++ src/cbang/js/v8/Value.h
@@ -135,7 +135,7 @@ namespace cb {
       std::string toString() const;
 
       int utf8Length() const {
-        return v8::String::Cast(*value)->Utf8Length(getIso());
+        return v8::String::Cast(*value)->Utf8LengthV2(getIso());
       }
 
       // Object
