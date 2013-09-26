--- source/simulation2/system/ParamNode.cpp.orig	2013-09-26 18:21:33.000000000 +0200
+++ source/simulation2/system/ParamNode.cpp	2013-09-26 18:22:57.000000000 +0200
@@ -37,6 +37,10 @@
 #include <boost/algorithm/string.hpp>
 #include <boost/algorithm/string/join.hpp>	// this isn't in string.hpp in old Boosts
 
+/* we need to force the instantiation of the wchar_t specialization of std::basic_string's empty() 
+ * method in order to get a reference to it through std::mem_fun_ref on lines 122 and 123 */
+template bool std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::empty() const;
+
 static CParamNode g_NullNode(false);
 
 CParamNode::CParamNode(bool isOk) :
