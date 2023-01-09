--- plugins/builtin/source/content/views/view_find.cpp.orig	2023-01-05 08:53:49 UTC
+++ plugins/builtin/source/content/views/view_find.cpp
@@ -153,34 +153,86 @@ namespace hex::plugin::builtin {
     }
 
     template<typename Type, typename StorageType>
-    static std::tuple<bool, std::variant<u64, i64, float, double>, size_t> parseNumericValue(const std::string &string) {
+    static std::tuple<bool, u64, size_t> parseNumericValue_u(const std::string &string) {
         static_assert(sizeof(StorageType) >= sizeof(Type));
 
         StorageType value = 0x00;
-        auto result = std::from_chars(string.data(), string.data() + string.size(), value);
-        if (result.ec != std::errc() || result.ptr != string.data() + string.size())
+        try {
+            value = std::stoull(string.data());
+        } catch (...) {
             return { false, { }, 0 };
+        }
+        if (value < std::numeric_limits<Type>::lowest() || value > std::numeric_limits<Type>::max())
+            return { false, { }, 0 };
 
+        return { true, value, sizeof(Type) };
+    }
+
+    template<typename Type, typename StorageType>
+    static std::tuple<bool, i64, size_t> parseNumericValue_i(const std::string &string) {
+        static_assert(sizeof(StorageType) >= sizeof(Type));
+
+        StorageType value = 0x00;
+        try {
+            value = std::stoll(string.data());
+        } catch (...) {
+            return { false, { }, 0 };
+        }
+
         if (value < std::numeric_limits<Type>::lowest() || value > std::numeric_limits<Type>::max())
             return { false, { }, 0 };
 
         return { true, value, sizeof(Type) };
     }
 
+    template<typename Type, typename StorageType>
+    static std::tuple<bool, float, size_t> parseNumericValue_f(const std::string &string) {
+        static_assert(sizeof(StorageType) >= sizeof(Type));
+
+        StorageType value = 0x00;
+        try {
+            value = std::stof(string.data());
+        } catch (...) {
+            return { false, { }, 0 };
+        }
+
+        if (value < std::numeric_limits<Type>::lowest() || value > std::numeric_limits<Type>::max())
+            return { false, { }, 0 };
+
+        return { true, value, sizeof(float) };
+    }
+
+    template<typename Type, typename StorageType>
+    static std::tuple<bool, double, size_t> parseNumericValue_d(const std::string &string) {
+        static_assert(sizeof(StorageType) >= sizeof(Type));
+
+        StorageType value = 0x00;
+        try {
+            value = std::stod(string.data());
+        } catch (...) {
+            return { false, { }, 0 };
+        }
+
+        if (value < std::numeric_limits<Type>::lowest() || value > std::numeric_limits<Type>::max())
+            return { false, { }, 0 };
+
+        return { true, value, sizeof(Type) };
+    }
+
     std::tuple<bool, std::variant<u64, i64, float, double>, size_t> ViewFind::parseNumericValueInput(const std::string &input, SearchSettings::Value::Type type) {
         switch (type) {
             using enum SearchSettings::Value::Type;
 
-            case U8:    return parseNumericValue<u8,  u64>(input);
-            case U16:   return parseNumericValue<u16, u64>(input);
-            case U32:   return parseNumericValue<u32, u64>(input);
-            case U64:   return parseNumericValue<u64, u64>(input);
-            case I8:    return parseNumericValue<i8,  i64>(input);
-            case I16:   return parseNumericValue<i16, i64>(input);
-            case I32:   return parseNumericValue<i32, i64>(input);
-            case I64:   return parseNumericValue<i64, i64>(input);
-            case F32:   return parseNumericValue<float, float>(input);
-            case F64:   return parseNumericValue<double, double>(input);
+            case U8:    return parseNumericValue_u<u8,  u64>(input);
+            case U16:   return parseNumericValue_u<u16, u64>(input);
+            case U32:   return parseNumericValue_u<u32, u64>(input);
+            case U64:   return parseNumericValue_u<u64, u64>(input);
+            case I8:    return parseNumericValue_i<i8,  i64>(input);
+            case I16:   return parseNumericValue_i<i16, i64>(input);
+            case I32:   return parseNumericValue_i<i32, i64>(input);
+            case I64:   return parseNumericValue_i<i64, i64>(input);
+            case F32:   return parseNumericValue_f<float, float>(input);
+            case F64:   return parseNumericValue_d<double, double>(input);
             default:    return { false, { }, 0 };
         }
     }
@@ -293,7 +345,7 @@ namespace hex::plugin::builtin {
 
         auto occurrence = reader.begin();
         while (true) {
-            occurrence = std::search(reader.begin(), reader.end(), std::boyer_moore_horspool_searcher(bytes.begin(), bytes.end()));
+            occurrence = std::search(reader.begin(), reader.end(), bytes.begin(), bytes.end());
             if (occurrence == reader.end())
                 break;
 
@@ -377,8 +429,12 @@ namespace hex::plugin::builtin {
         reader.seek(searchRegion.getStartAddress());
         reader.setEndAddress(searchRegion.getEndAddress());
 
-        const auto [validMin, min, sizeMin] = parseNumericValueInput(settings.inputMin, settings.type);
-        const auto [validMax, max, sizeMax] = parseNumericValueInput(settings.inputMax, settings.type);
+        const auto validMin = std::get<0>(parseNumericValueInput(settings.inputMin, settings.type));
+        const auto min = std::get<1>(parseNumericValueInput(settings.inputMin, settings.type));
+        const auto sizeMin = std::get<2>(parseNumericValueInput(settings.inputMin, settings.type));
+        const auto validMax = std::get<0>(parseNumericValueInput(settings.inputMax, settings.type));
+        const auto max = std::get<1>(parseNumericValueInput(settings.inputMax, settings.type));
+        const auto sizeMax = std::get<2>(parseNumericValueInput(settings.inputMax, settings.type));
 
         if (!validMin || !validMax || sizeMin != sizeMax)
             return { };
