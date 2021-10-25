--- src/main.cc.orig	2021-10-25 11:31:24 UTC
+++ src/main.cc
@@ -1249,8 +1249,12 @@ int main(int argc, char* argv[])
 }
 
 #if defined(__ELF__)
-asm(R"(
-.pushsection ".debug_gdb_scripts", "MS",@progbits,1
+#ifdef __arm__
+# define PROGBITS "%progbits"
+#else
+# define PROGBITS "@progbits"
+#endif
+asm(".pushsection \".debug_gdb_scripts\", \"MS\"," PROGBITS ",1" R"(
 .byte 4
 .ascii "kakoune-inline-gdb.py\n"
 .ascii "import os.path\n"
