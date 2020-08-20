--- icd_generator.rb.orig	2020-08-19 22:03:46 UTC
+++ icd_generator.rb
@@ -189,7 +189,7 @@ EOF
     }
     libdummy_icd_structures += "};\n\n"
     libdummy_icd_structures += "#pragma GCC visibility push(hidden)\n\n"
-    libdummy_icd_structures += "struct _cl_icd_dispatch master_dispatch; \n\n"
+    libdummy_icd_structures += "extern struct _cl_icd_dispatch master_dispatch; \n\n"
     $use_name_in_test.each { |k, f|
       libdummy_icd_structures += "typeof(#{f}) INT#{f};\n"
     }
