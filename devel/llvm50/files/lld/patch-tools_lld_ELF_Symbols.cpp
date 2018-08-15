--- tools/lld/ELF/Symbols.cpp.orig	2017-07-14 00:22:46 UTC
+++ tools/lld/ELF/Symbols.cpp
@@ -383,17 +383,17 @@ std::string lld::toString(const SymbolBody &B) {
   return B.getName();
 }
 
-template uint32_t SymbolBody::template getSize<ELF32LE>() const;
-template uint32_t SymbolBody::template getSize<ELF32BE>() const;
-template uint64_t SymbolBody::template getSize<ELF64LE>() const;
-template uint64_t SymbolBody::template getSize<ELF64BE>() const;
+template uint32_t SymbolBody::getSize<ELF32LE>() const;
+template uint32_t SymbolBody::getSize<ELF32BE>() const;
+template uint64_t SymbolBody::getSize<ELF64LE>() const;
+template uint64_t SymbolBody::getSize<ELF64BE>() const;
 
-template bool DefinedRegular::template isMipsPIC<ELF32LE>() const;
-template bool DefinedRegular::template isMipsPIC<ELF32BE>() const;
-template bool DefinedRegular::template isMipsPIC<ELF64LE>() const;
-template bool DefinedRegular::template isMipsPIC<ELF64BE>() const;
+template bool DefinedRegular::isMipsPIC<ELF32LE>() const;
+template bool DefinedRegular::isMipsPIC<ELF32BE>() const;
+template bool DefinedRegular::isMipsPIC<ELF64LE>() const;
+template bool DefinedRegular::isMipsPIC<ELF64BE>() const;
 
-template uint32_t SharedSymbol::template getAlignment<ELF32LE>() const;
-template uint32_t SharedSymbol::template getAlignment<ELF32BE>() const;
-template uint32_t SharedSymbol::template getAlignment<ELF64LE>() const;
-template uint32_t SharedSymbol::template getAlignment<ELF64BE>() const;
+template uint32_t SharedSymbol::getAlignment<ELF32LE>() const;
+template uint32_t SharedSymbol::getAlignment<ELF32BE>() const;
+template uint32_t SharedSymbol::getAlignment<ELF64LE>() const;
+template uint32_t SharedSymbol::getAlignment<ELF64BE>() const;
