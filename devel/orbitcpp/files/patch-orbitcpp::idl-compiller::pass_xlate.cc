--- orbitcpp/idl-compiler/pass_xlate.cc.orig	Tue Nov 18 12:35:41 2003
+++ orbitcpp/idl-compiler/pass_xlate.cc	Tue Nov 18 12:36:16 2003
@@ -1328,7 +1328,7 @@
 {
 	string array_id = m_dest.get_cpp_typename ();
 	string slice_id = array_id + "_slice";
-	string props_id = m_dest.get_cpp_typename () + "Props";
+	string props_id = m_dest.get_cpp_identifier () + "Props";
 
 	int length = 1;
 	for (IDLArray::const_iterator i = m_array.begin ();
