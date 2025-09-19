--- gcc/jit/jit-recording.cc.orig	2025-09-19 17:08:24 UTC
+++ gcc/jit/jit-recording.cc
@@ -4822,7 +4822,7 @@ recording::function::write_reproducer (reproducer &r)
     r.write("  gcc_jit_function_add_integer_array_attribute (%s,\n"
 	    "                                                %s,\n"
 	    "                                                (int[])%s,\n"
-	    "                                                %lu);\n",
+	    "                                                %zu);\n",
 	    id,
 	    fn_attribute_reproducer_strings[std::get<0>(attribute)],
 	    get_vector_int_debug (std::get<1>(attribute)).c_str(),
