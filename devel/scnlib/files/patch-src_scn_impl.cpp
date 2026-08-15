--- src/scn/impl.cpp.orig	2024-11-03 23:00:07 UTC
+++ src/scn/impl.cpp
@@ -721,15 +721,18 @@ struct fast_float_impl_base : impl_base {
 struct fast_float_impl_base : impl_base {
     fast_float::chars_format get_flags() const
     {
-        unsigned format_flags{};
+         // Patch from https://github.com/eliaskosunen/scnlib/pull/136
+        fast_float::chars_format format_flags{};
         if ((m_options & float_reader_base::allow_fixed) != 0) {
-            format_flags |= fast_float::fixed;
+            format_flags =
+                static_cast<fast_float::chars_format>(format_flags | fast_float::chars_format::fixed);
         }
         if ((m_options & float_reader_base::allow_scientific) != 0) {
-            format_flags |= fast_float::scientific;
+            format_flags =
+                static_cast<fast_float::chars_format>(format_flags | fast_float::chars_format::scientific);
         }
 
-        return static_cast<fast_float::chars_format>(format_flags);
+        return format_flags;
     }
 };
 
