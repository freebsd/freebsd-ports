-- Add SNITCH_EXPORT to abort_exception struct.
-- This ensures that the exception can be correctly caught across shared library boundaries
-- on ELF systems (like FreeBSD) when built with -fvisibility=hidden.
-- This fixes "unexpected unknown exception caught" errors in tests.

--- include/snitch/snitch_registry.hpp.orig	2026-05-31 20:22:28 UTC
+++ include/snitch/snitch_registry.hpp
@@ -61,7 +61,7 @@ constexpr test_ptr to_test_case_ptr(const F&) noexcept
     return []() { F{}.template operator()<T>(); };
 }
 
-struct abort_exception {};
+struct SNITCH_EXPORT abort_exception {};
 
 SNITCH_EXPORT bool parse_colour_mode_option(registry& reg, std::string_view color_option) noexcept;
 SNITCH_EXPORT bool parse_color_option(registry& reg, std::string_view color_option) noexcept;
