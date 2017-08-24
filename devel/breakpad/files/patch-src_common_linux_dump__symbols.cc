--- src/common/linux/dump_symbols.cc.orig	2017-07-12 17:53:15 UTC
+++ src/common/linux/dump_symbols.cc
@@ -53,6 +53,10 @@
 #include <utility>
 #include <vector>
 
+#if __FreeBSD__
+#include <libgen.h>
+#endif
+
 #include "common/dwarf/bytereader-inl.h"
 #include "common/dwarf/dwarf2diehandler.h"
 #include "common/dwarf_cfi_to_module.h"
