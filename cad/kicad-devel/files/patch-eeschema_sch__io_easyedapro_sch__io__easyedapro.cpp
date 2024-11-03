--- eeschema/sch_io/easyedapro/sch_io_easyedapro.cpp.orig	2024-10-11 09:03:05 UTC
+++ eeschema/sch_io/easyedapro/sch_io_easyedapro.cpp
@@ -105,6 +105,31 @@ int SCH_IO_EASYEDAPRO::GetModifyHash() const
 }
 
 
+// Explicitly define char traits for wxUniChar since it is not standard
+template<>
+struct nlohmann::detail::char_traits<wxUniChar> : std::char_traits<char32_t>
+{
+    using char_type = wxUniChar;
+    using int_type = uint32_t;
+
+    // Redefine to_int_type function
+    static int_type to_int_type(char_type c) noexcept
+    {
+        return static_cast<int_type>(c);
+    }
+
+    static char_type to_char_type(int_type i) noexcept
+    {
+        return static_cast<char_type>(i);
+    }
+
+    static constexpr int_type eof() noexcept
+    {
+        return ~0U;
+    }
+};
+
+
 static LIB_SYMBOL* loadSymbol( nlohmann::json project, const wxString& aLibraryPath,
                                const wxString& aAliasName, const std::map<std::string, UTF8>* aProperties )
 {
