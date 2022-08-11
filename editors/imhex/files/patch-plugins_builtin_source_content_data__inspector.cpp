--- plugins/builtin/source/content/data_inspector.cpp.orig	2022-08-05 19:30:19 UTC
+++ plugins/builtin/source/content/data_inspector.cpp
@@ -102,7 +102,7 @@ namespace hex::plugin::builtin {
         auto number   = hex::signExtend(Size * 8, hex::changeEndianess(value, Size, endian));
         bool negative = number < 0;
 
-        return hex::format(format, negative ? "-" : "", std::abs(number));
+        return hex::format(format, negative ? "-" : "", std::abs((long)number));
     }
 
     template<std::integral T, size_t Size = sizeof(T)>
@@ -282,7 +282,7 @@ namespace hex::plugin::builtin {
 
                 auto number   = hex::crypt::decodeSleb128(buffer);
                 bool negative = number < 0;
-                auto value    = hex::format(format, negative ? "-" : "", std::abs(number));
+                auto value    = hex::format(format, negative ? "-" : "", std::abs((long)number));
 
                 return [value] { ImGui::TextUnformatted(value.c_str()); return value; };
             },
