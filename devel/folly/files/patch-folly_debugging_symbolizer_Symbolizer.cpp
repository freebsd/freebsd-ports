--- folly/debugging/symbolizer/Symbolizer.cpp.orig	2026-05-11 14:37:10 UTC
+++ folly/debugging/symbolizer/Symbolizer.cpp
@@ -357,7 +357,7 @@ size_t Symbolizer::symbolize(
       // Get the unrelocated, ELF-relative address by normalizing via the
       // address at which the object is loaded.
       auto const eaddr = static_cast<ElfAddr>(addr);
-      auto const maddr = lmap->l_addr;
+      auto const maddr = reinterpret_cast<ElfAddr>(lmap->l_addr);
       auto const adjusted = eaddr < maddr ? ~ElfAddr(0) : eaddr - maddr;
       size_t numInlined = 0;
       if (containedInExecutableSegment(*elfFile, adjusted)) {
