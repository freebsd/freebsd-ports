--- boost/detail/utf8_codecvt_facet.hpp.orig	Sun Aug 21 13:59:04 2005
+++ boost/detail/utf8_codecvt_facet.hpp	Sun Aug 21 13:59:34 2005
@@ -117,7 +117,7 @@
 {
 public:
     explicit utf8_codecvt_facet(std::size_t no_locale_manage=0)
-        : std::codecvt<wchar_t, char, std::mbstate_t>(no_locale_manage) 
+        : std::codecvt<wchar_t, char, std::mbstate_t>() // FIXME
     {}
 protected:
     virtual std::codecvt_base::result do_in(
