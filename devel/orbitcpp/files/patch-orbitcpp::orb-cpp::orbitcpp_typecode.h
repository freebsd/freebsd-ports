--- orbitcpp/orb-cpp/orbitcpp_typecode.h	2 Jul 2003 23:47:23 -0000	1.7
+++ orbitcpp/orb-cpp/orbitcpp_typecode.h	15 Mar 2004 00:58:59 -0000	1.9
@@ -137,6 +137,7 @@
 	typedef TypeCode *TypeCode_ptr;
 	typedef ::_orbitcpp::ObjectPtr_var<TypeCode>
 		TypeCode_var;
+	typedef TypeCode_var TypeCode_mgr;
 
 	class TypeCode
 	{
@@ -207,6 +208,16 @@
 		}
 
 		static TypeCode_ptr _orbitcpp_wrap (CORBA_TypeCode tc, bool take_copy = false);
+		static void unpack_elem(TypeCode_mgr& cpp_elem, CORBA_TypeCode c_elem)
+		{
+			cpp_elem = _orbitcpp_wrap(c_elem, true);
+		}
+
+		static void pack_elem(TypeCode_mgr const& cpp_elem, CORBA_TypeCode& c_elem)
+		{
+			c_elem = _orbitcpp::duplicate_guarded(cpp_elem->_orbitcpp_cobj ());
+				
+		}
 	};
 
 	inline void release(TypeCode_ptr o) {
