--- boost/program_options/detail/utf8_codecvt_facet.hpp.orig	Mon Dec 13 18:48:58 2004
+++ boost/program_options/detail/utf8_codecvt_facet.hpp	Mon Dec 13 18:49:51 2004
@@ -67,7 +67,7 @@
 #elif defined(BOOST_NO_STDC_NAMESPACE)
     typedef std::mbstate_t mbstate_t;
     namespace std{ 
-        using ::codecvt; 
+        using std::codecvt; 
     } // namespace std
 #endif
 
@@ -81,7 +81,7 @@
 {
 public:
     explicit utf8_codecvt_facet_wchar_t(std::size_t no_locale_manage=0)
-        : std::codecvt<wchar_t, char, mbstate_t>(no_locale_manage) 
+        : std::codecvt<wchar_t, char, mbstate_t>() // FIXME
     {}
 protected:
     virtual std::codecvt_base::result do_in(
