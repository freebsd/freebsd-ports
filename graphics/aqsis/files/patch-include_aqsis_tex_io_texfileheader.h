In file included from libs/tex/io/tiffoutputfile.cpp:38:
In file included from libs/tex/io/tiffoutputfile.h:43:
In file included from include/aqsis/tex/io/itexoutputfile.h:46:
In file included from include/aqsis/tex/buffers/mixedimagebuffer.h:44:
/usr/include/c++/v1/map:629:15: error: object of type
      'std::__1::pair<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>' cannot be assigned
      because its copy assignment operator is implicitly deleted
        {__nc = __v.__cc; return *this;}
              ^
/usr/include/c++/v1/__tree:1645:35: note: in instantiation of member function
      'std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>::operator='
      requested here
                __cache->__value_ = *__first;
                                  ^
/usr/include/c++/v1/__tree:1575:9: note: in instantiation of function template specialization
      'std::__1::__tree<std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>,
      std::__1::__map_value_compare<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>,
      std::__1::less<Aqsis::CqTexFileHeader::CqTypeInfoHolder>, true>,
      std::__1::allocator<std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      boost::any> >
      >::__assign_multi<std::__1::__tree_const_iterator<std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      boost::any>,
      std::__1::__tree_node<std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      boost::any>, void *> *, long> >' requested here
        __assign_multi(__t.begin(), __t.end());
        ^
/usr/include/c++/v1/map:912:21: note: in instantiation of member function
      'std::__1::__tree<std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>,
      std::__1::__map_value_compare<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>,
      std::__1::less<Aqsis::CqTexFileHeader::CqTypeInfoHolder>, true>,
      std::__1::allocator<std::__1::__value_type<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      boost::any> > >::operator=' requested here
            __tree_ = __m.__tree_;
                    ^
include/aqsis/tex/io/texfileheader.h:74:7: note:
      in instantiation of member function 'std::__1::map<Aqsis::CqTexFileHeader::CqTypeInfoHolder,
      boost::any, std::__1::less<Aqsis::CqTexFileHeader::CqTypeInfoHolder>,
      std::__1::allocator<std::__1::pair<const Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>
      > >::operator=' requested here
class CqTexFileHeader
      ^
/usr/include/c++/v1/utility:325:5: note: copy assignment operator is implicitly deleted because
      'pair<Aqsis::CqTexFileHeader::CqTypeInfoHolder, boost::any>' has a user-declared move
      constructor
    pair(pair&&) = default;
    ^

--- include/aqsis/tex/io/texfileheader.h.orig	2012-08-24 12:26:50 UTC
+++ include/aqsis/tex/io/texfileheader.h
@@ -43,6 +43,9 @@
 
 #include <iostream>
 #include <map>
+#if __cplusplus >= 201103L
+#include <typeindex>
+#endif
 
 #include <boost/any.hpp>
 #include <boost/shared_ptr.hpp>
@@ -74,9 +77,13 @@ namespace Aqsis {
 class CqTexFileHeader
 {
 	private:
+#if __cplusplus < 201103L
 		class CqTypeInfoHolder;
 		/// Underlying map type.
 		typedef std::map<CqTypeInfoHolder, boost::any> TqAttributeMap;
+#else
+		typedef std::map<std::type_index, boost::any> TqAttributeMap;
+#endif
 		typedef TqAttributeMap::const_iterator const_iterator;
 	public:
 
@@ -180,6 +187,7 @@ class CqTexFileHeader
 };
 
 
+#if __cplusplus < 201103L
 //==============================================================================
 // Implementation details
 //==============================================================================
@@ -200,6 +208,7 @@ class CqTexFileHeader::CqTypeInfoHolder
 			return m_typeInfo.before(rhs.m_typeInfo) != 0;
 		}
 };
+#endif
 
 //------------------------------------------------------------------------------
 // CqTexFileHeader
@@ -261,13 +270,21 @@ inline void CqTexFileHeader::setTimestamp()
 template<typename AttrTagType>
 inline void CqTexFileHeader::set(const typename AttrTagType::type& value)
 {
+#if __cplusplus < 201103L
 	m_attributeMap[CqTypeInfoHolder(typeid(AttrTagType))] = value;
+#else
+	m_attributeMap[std::type_index(typeid(AttrTagType))] = value;
+#endif
 }
 
 template<typename AttrTagType>
 void CqTexFileHeader::erase()
 {
+#if __cplusplus < 201103L
 	m_attributeMap.erase(CqTypeInfoHolder(typeid(AttrTagType)));
+#else
+	m_attributeMap.erase(std::type_index(typeid(AttrTagType)));
+#endif
 }
 
 template<typename AttrTagType>
@@ -280,7 +297,11 @@ inline typename AttrTagType::type& CqTexFileHeader::fi
 template<typename AttrTagType>
 inline const typename AttrTagType::type& CqTexFileHeader::find() const
 {
+#if __cplusplus < 201103L
 	const_iterator iter = m_attributeMap.find(CqTypeInfoHolder(typeid(AttrTagType)));
+#else
+	const_iterator iter = m_attributeMap.find(std::type_index(typeid(AttrTagType)));
+#endif
 	if(iter == m_attributeMap.end())
 	{
 		AQSIS_THROW_XQERROR(XqInternal, EqE_BadFile, "Requested attribute \""
@@ -310,7 +331,11 @@ inline typename AttrTagType::type* CqTexFileHeader::fi
 template<typename AttrTagType>
 inline const typename AttrTagType::type* CqTexFileHeader::findPtr() const
 {
+#if __cplusplus < 201103L
 	const_iterator iter = m_attributeMap.find(CqTypeInfoHolder(typeid(AttrTagType)));
+#else
+	const_iterator iter = m_attributeMap.find(std::type_index(typeid(AttrTagType)));
+#endif
 	if(iter == m_attributeMap.end())
 		return 0;
 	return & boost::any_cast<const typename AttrTagType::type&>(iter->second);
