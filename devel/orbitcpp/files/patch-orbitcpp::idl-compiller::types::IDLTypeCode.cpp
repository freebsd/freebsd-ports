--- orbitcpp/idl-compiler/types/IDLTypeCode.cc	14 Sep 2002 13:13:10 -0000	1.1
+++ orbitcpp/idl-compiler/types/IDLTypeCode.cc	15 Mar 2004 01:01:28 -0000	1.2
@@ -54,3 +54,14 @@
 {
     return get_cpp_typename ();
 }
+
+void
+IDLTypeCode::member_pack_to_c (ostream          &ostr,
+				Indent           &indent,
+				const string     &cpp_id,
+				const string     &c_id,
+				const IDLTypedef *active_typedef) const
+{
+	ostr << indent << c_id << " = ((" << cpp_id << ".in() != 0) ? ::_orbitcpp::duplicate_guarded("
+	     << cpp_id << ".in()->_orbitcpp_cobj ()) : CORBA_OBJECT_NIL)" << ';' << endl;
+}
