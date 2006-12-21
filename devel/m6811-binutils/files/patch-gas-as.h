--- gas/as.h.orig	Sun Nov 23 15:14:21 2003
+++ gas/as.h	Mon Dec 18 11:25:54 2006
@@ -622,9 +622,6 @@
 
 #include "expr.h"		/* Before targ-*.h */
 
-/* this one starts the chain of target dependant headers */
-#include "targ-env.h"
-
 #ifdef OBJ_MAYBE_ELF
 #define IS_ELF (OUTPUT_FLAVOR == bfd_target_elf_flavour)
 #else
@@ -639,10 +636,14 @@
 #include "frags.h"
 #include "hash.h"
 #include "read.h"
-#include "symbols.h"
 
 #include "tc.h"
 #include "obj.h"
+
+/* this one starts the chain of target dependant headers */
+#include "targ-env.h"
+
+#include "symbols.h"
 
 #ifdef USE_EMULATIONS
 #include "emul.h"


