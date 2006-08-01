--- boost/regex/v4/cpp_regex_traits.hpp.orig	Wed Sep 14 14:20:41 2005
+++ boost/regex/v4/cpp_regex_traits.hpp	Tue Aug  1 20:58:55 2006
@@ -407,12 +407,12 @@
    typedef charT char_type;
    //cpp_regex_traits_implementation();
    cpp_regex_traits_implementation(const std::locale& l)
-      : cpp_regex_traits_char_layer<charT>(l), m_is(&m_sbuf)
+      : cpp_regex_traits_char_layer<charT>(l)
    {
       init();
    }
    cpp_regex_traits_implementation(const cpp_regex_traits_base<charT>& l)
-      : cpp_regex_traits_char_layer<charT>(l), m_is(&m_sbuf)
+      : cpp_regex_traits_char_layer<charT>(l)
    {
       init();
    }
@@ -439,8 +439,6 @@
    string_type lookup_collatename(const charT* p1, const charT* p2) const;
    string_type transform_primary(const charT* p1, const charT* p2) const;
    string_type transform(const charT* p1, const charT* p2) const;
-   re_detail::parser_buf<charT>   m_sbuf;            // buffer for parsing numbers.
-   std::basic_istream<charT>      m_is;              // stream for parsing numbers.
 private:
    std::map<int, std::string>     m_error_strings;   // error messages indexed by numberic ID
    std::map<string_type, char_class_type>  m_custom_class_names; // character class names
@@ -816,7 +814,7 @@
 
 
 template <class charT>
-inline boost::shared_ptr<cpp_regex_traits_implementation<charT> > create_cpp_regex_traits(const std::locale& l BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(charT))
+inline boost::shared_ptr<const cpp_regex_traits_implementation<charT> > create_cpp_regex_traits(const std::locale& l BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(charT))
 {
    cpp_regex_traits_base<charT> key(l);
    return ::boost::object_cache<cpp_regex_traits_base<charT>, cpp_regex_traits_implementation<charT> >::get(key, 5);
@@ -954,7 +952,7 @@
    static std::string get_catalog_name();
 
 private:
-   boost::shared_ptr<re_detail::cpp_regex_traits_implementation<charT> > m_pimpl;
+   boost::shared_ptr<const re_detail::cpp_regex_traits_implementation<charT> > m_pimpl;
    //
    // catalog name handler:
    //
@@ -969,17 +967,21 @@
 template <class charT>
 int cpp_regex_traits<charT>::toi(const charT*& first, const charT* last, int radix)const
 {
+   re_detail::parser_buf<charT>   sbuf;            // buffer for parsing numbers.
+   std::basic_istream<charT>      is(&sbuf);       // stream for parsing numbers.
+
    // we do NOT want to parse any thousands separators inside the stream:
-   last = std::find(first, last, BOOST_USE_FACET(std::numpunct<charT>, m_pimpl->m_is.getloc()).thousands_sep());
-   m_pimpl->m_sbuf.pubsetbuf(const_cast<charT*>(static_cast<const charT*>(first)), static_cast<std::streamsize>(last-first));
-   m_pimpl->m_is.clear();
-   if(std::abs(radix) == 16) m_pimpl->m_is >> std::hex;
-   else if(std::abs(radix) == 8) m_pimpl->m_is >> std::oct;
-   else m_pimpl->m_is >> std::dec;
+   last = std::find(first, last, BOOST_USE_FACET(std::numpunct<charT>, is.getloc()).thousands_sep());
+
+   sbuf.pubsetbuf(const_cast<charT*>(static_cast<const charT*>(first)), static_cast<std::streamsize>(last-first));
+   is.clear();
+   if(std::abs(radix) == 16) is >> std::hex;
+   else if(std::abs(radix) == 8) is >> std::oct;
+   else is >> std::dec;
    int val;
-   if(m_pimpl->m_is >> val)
+   if(is >> val)
    {
-      first = first + ((last - first) - m_pimpl->m_sbuf.in_avail());
+      first = first + ((last - first) - sbuf.in_avail());
       return val;
    }
    else
