--- folly/debugging/symbolizer/Symbolizer.cpp.orig	2025-11-05 09:24:00 UTC
+++ folly/debugging/symbolizer/Symbolizer.cpp
@@ -348,7 +348,7 @@ void ElfCache::Symbolizer::symbolize(
       // Get the unrelocated, ELF-relative address by normalizing via the
       // address at which the object is loaded.
       auto const eaddr = static_cast<ElfAddr>(addr);
-      auto const maddr = lmap->l_addr;
+      auto const maddr = reinterpret_cast<ElfAddr>(lmap->l_addr);
       auto const adjusted = eaddr < maddr ? ~ElfAddr(0) : eaddr - maddr;
       size_t numInlined = 0;
       if (containedInExecutableSegment(*elfFile, adjusted)) {
