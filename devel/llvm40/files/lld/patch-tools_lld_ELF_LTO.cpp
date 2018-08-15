--- tools/lld/ELF/LTO.cpp.orig	2017-01-04 09:45:45 UTC
+++ tools/lld/ELF/LTO.cpp
@@ -158,7 +158,7 @@ std::vector<InputFile *> BitcodeCompiler::compile() {
   return Ret;
 }
 
-template void BitcodeCompiler::template add<ELF32LE>(BitcodeFile &);
-template void BitcodeCompiler::template add<ELF32BE>(BitcodeFile &);
-template void BitcodeCompiler::template add<ELF64LE>(BitcodeFile &);
-template void BitcodeCompiler::template add<ELF64BE>(BitcodeFile &);
+template void BitcodeCompiler::add<ELF32LE>(BitcodeFile &);
+template void BitcodeCompiler::add<ELF32BE>(BitcodeFile &);
+template void BitcodeCompiler::add<ELF64LE>(BitcodeFile &);
+template void BitcodeCompiler::add<ELF64BE>(BitcodeFile &);
