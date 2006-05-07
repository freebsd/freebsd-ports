--- ode-0.5/configurator.c	Sun May  7 12:12:01 2006
+++ ode-0.5/configurator.c	Sun May  7 12:12:52 2006
@@ -222,7 +222,7 @@
   write_header_comment (file,"is this a pentium on a gcc-based platform?");
   write_to_file ("ctest.cpp",
 		 "int main() {\n"
-		 "  asm (\"mov $0,%%eax\\n cpuid\\n\" : : : \"%eax\");\n"
+		 "  asm (\"mov $0,%%eax\\n mov %%eax,(%%esi)\\n cpuid\\n\" : : : \"%eax\");\n"
 		 "  return 0;\n"
 		 "}\n");
   delete_file ("ctest.exe");
