--- src/MemoryX.h.orig	2019-03-09 11:55:09 UTC
+++ src/MemoryX.h
@@ -628,7 +628,7 @@ make_iterator_range( const Container &container )
 // For using std::unordered_map on wxString
 namespace std
 {
-   template<typename T> struct hash;
+   //template<typename T> struct hash;
    template<> struct hash< wxString > {
       size_t operator () (const wxString &str) const // noexcept
       {
