--- plugins/builtin/source/content/data_inspector.cpp.orig	2023-04-04 10:04:22 UTC
+++ plugins/builtin/source/content/data_inspector.cpp
@@ -105,7 +105,7 @@ namespace hex::plugin::builtin {
 
         bool negative = number < 0;
 
-        return hex::format(format, negative ? "-" : "", std::abs(number));
+        return hex::format(format, negative ? "-" : "", std::abs((long)number));
     }
 
     template<std::integral T, size_t Size = sizeof(T)>
@@ -277,7 +277,7 @@ namespace hex::plugin::builtin {
 
                 auto number   = hex::crypt::decodeSleb128(buffer);
                 bool negative = number < 0;
-                auto value    = hex::format(format, negative ? "-" : "", std::abs(number));
+                auto value    = hex::format(format, negative ? "-" : "", std::abs((long)number));
 
                 return [value] { ImGui::TextUnformatted(value.c_str()); return value; };
             },
