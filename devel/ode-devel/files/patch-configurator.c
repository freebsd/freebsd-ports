--- configurator.c.orig	Sat May 29 21:46:03 2004
+++ configurator.c	Tue Dec  6 03:48:15 2005
@@ -222,7 +222,7 @@
   write_header_comment (file,"is this a pentium on a gcc-based platform?");
   write_to_file ("ctest.cpp",
 		 "int main() {\n"
-		 "  asm (\"mov $0,%%eax\\n cpuid\\n\" : : : \"%eax\");\n"
+		 "  asm (\"mov $0,%%eax\\n mov %%eax,(%%esi)\\n cpuid\\n\" : : : \"%eax\");\n"
 		 "  return 0;\n"
 		 "}\n");
   delete_file ("ctest.exe");
