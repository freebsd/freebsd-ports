--- orbitcpp/idl-compiler/types/IDLTypeCode.h	14 Sep 2002 13:13:10 -0000	1.1
+++ orbitcpp/idl-compiler/types/IDLTypeCode.h	15 Mar 2004 01:01:28 -0000	1.2
@@ -40,6 +40,12 @@
 	string get_cpp_typename () const;
 
 	string get_cpp_stub_typename () const;
+
+	void member_pack_to_c (ostream          &ostr,
+			       Indent           &indent,
+			       const string     &cpp_id,
+			       const string     &c_id,
+			       const IDLTypedef *active_typedef = 0) const;
 };
 
 #endif //ORBITCPP_TYPES_IDLTYPECODE
