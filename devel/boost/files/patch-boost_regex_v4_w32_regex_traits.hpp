--- boost/regex/v4/w32_regex_traits.hpp.orig	Tue Jul 12 11:49:11 2005
+++ boost/regex/v4/w32_regex_traits.hpp	Tue Aug  1 20:58:55 2006
@@ -166,7 +166,7 @@
    {
       return ::boost::re_detail::w32_tolower(c, this->m_locale);
    }
-   bool isctype(boost::uint32_t mask, charT c)
+   bool isctype(boost::uint32_t mask, charT c)const
    {
       return ::boost::re_detail::w32_is(this->m_locale, mask, c);
    }
@@ -263,7 +263,7 @@
    {
       return m_lower_map[static_cast<unsigned char>(c)];
    }
-   bool isctype(boost::uint32_t mask, char c)
+   bool isctype(boost::uint32_t mask, char c)const
    {
       return m_type_map[static_cast<unsigned char>(c)] & mask;
    }
@@ -539,7 +539,7 @@
 
 
 template <class charT>
-boost::shared_ptr<w32_regex_traits_implementation<charT> > create_w32_regex_traits(::boost::re_detail::lcid_type l BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(charT))
+boost::shared_ptr<const w32_regex_traits_implementation<charT> > create_w32_regex_traits(::boost::re_detail::lcid_type l BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(charT))
 {
    // TODO: create a cache for previously constructed objects.
    return boost::object_cache< ::boost::re_detail::lcid_type, w32_regex_traits_implementation<charT> >::get(l, 5);
@@ -653,7 +653,7 @@
    static std::string get_catalog_name();
 
 private:
-   boost::shared_ptr<re_detail::w32_regex_traits_implementation<charT> > m_pimpl;
+   boost::shared_ptr<const re_detail::w32_regex_traits_implementation<charT> > m_pimpl;
    //
    // catalog name handler:
    //
