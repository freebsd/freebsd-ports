--- libxsd-frontend/types.hxx.orig	2022-08-19 06:30:48 UTC
+++ libxsd-frontend/types.hxx
@@ -13,38 +13,13 @@ namespace XSDFrontend
 {
   using std::size_t;
 
-  namespace Bits
-  {
-    struct None {};
-
-    template <typename C>
-    struct NarrowerChar
-    {
-      typedef None Type;
-    };
-
-    template <>
-    struct NarrowerChar<wchar_t>
-    {
-      typedef char Type;
-    };
-  }
-
   struct LIBXSD_FRONTEND_SYMEXPORT NonRepresentable: std::exception
   {
     virtual char const*
     what () const throw ();
   };
 
-  template <typename C, typename NC = typename Bits::NarrowerChar<C>::Type>
-  class StringTemplate;
-
-  template <>
-  class StringTemplate<Bits::None, Bits::None>
-  {
-  };
-
-  template <typename C, typename NC>
+  template <typename C, typename NC = char>
   class StringTemplate : public std::basic_string<C>
   {
     typedef std::basic_string<C> Base;
@@ -114,16 +89,19 @@ namespace XSDFrontend
 
     // Conversion from the Narrower type. Experimental.
     //
+    template<typename WC = C, typename = std::enable_if_t<std::is_same_v<WC, wchar_t>>>
     StringTemplate (NC const* s)
     {
       from_narrow (s);
     }
 
+    template<typename WC = C, typename = std::enable_if_t<std::is_same_v<WC, wchar_t>>>
     StringTemplate (StringTemplate<NC> const& other)
     {
       from_narrow (other.c_str ());
     }
 
+    template<typename WC = C, typename = std::enable_if_t<std::is_same_v<WC, wchar_t>>>
     StringTemplate (NarrowerBase const& other)
     {
       from_narrow (other.c_str ());
