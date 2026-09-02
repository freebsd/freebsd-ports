--- lib/SPIRV/libSPIRV/SPIRVStream.h.orig	2026-09-02 08:46:59 UTC
+++ lib/SPIRV/libSPIRV/SPIRVStream.h
@@ -97,10 +97,20 @@ class SPIRVNL {
   friend spv_ostream &operator<<(spv_ostream &O, const SPIRVNL &E);
 };
 
+/// Read a single SPIR-V word from a binary stream, byte-swapping from
+/// little-endian on big-endian hosts.
+inline uint32_t readSPIRVWord(std::istream &IS) {
+  uint32_t W;
+  IS.read(reinterpret_cast<char *>(&W), sizeof(W));
+#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+  W = __builtin_bswap32(W);
+#endif
+  return W;
+}
+
 template <typename T>
 const SPIRVDecoder &decodeBinary(const SPIRVDecoder &I, T &V) {
-  uint32_t W;
-  I.IS.read(reinterpret_cast<char *>(&W), sizeof(W));
+  uint32_t W = readSPIRVWord(I.IS);
   V = static_cast<T>(W);
   SPIRVDBG(spvdbgs() << "Read word: W = " << W << " V = " << V << '\n');
   return I;
@@ -185,6 +195,10 @@ const SPIRVEncoder &operator<<(const SPIRVEncoder &O, 
   }
 #endif
   uint32_t W = static_cast<uint32_t>(V);
+#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+  // SPIR-V binary format is little-endian; byte-swap on big-endian hosts.
+  W = __builtin_bswap32(W);
+#endif
   O.OS.write(reinterpret_cast<char *>(&W), sizeof(W));
   return O;
 }
