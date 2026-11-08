--- folly/debugging/symbolizer/Symbolizer.cpp.orig	2026-08-30 06:04:38 UTC
+++ folly/debugging/symbolizer/Symbolizer.cpp
@@ -380,7 +380,7 @@ size_t Symbolizer::symbolize(
         // Get the unrelocated, ELF-relative address by normalizing via the
         // address at which the object is loaded.
         auto const eaddr = static_cast<ElfAddr>(addr);
-        auto const maddr = lmap->l_addr;
+        auto const maddr = reinterpret_cast<ElfAddr>(lmap->l_addr);
         auto const adjusted = eaddr < maddr ? ~ElfAddr(0) : eaddr - maddr;
         if (!containedInExecutableSegment(*elfFile, adjusted)) {
           continue; // Not in this object, retry against the next one.
