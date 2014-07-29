
$FreeBSD$

--- ../../src/symbol.c	2003/07/12 11:33:10	1.1
+++ ../../src/symbol.c	2003/07/12 11:33:29
@@ -72,7 +72,7 @@
 #include <ldfcn.h>
 #endif /* SYSTEM */
 #elif FORMAT == FORMAT_ELF32 || FORMAT == FORMAT_ELF64
-#include <libelf.h>
+#include <libelf/libelf.h>
 #elif FORMAT == FORMAT_BFD
 #include <bfd.h>
 #endif /* FORMAT */
@@ -113,7 +113,7 @@
  * symbols from the object files and libraries.  However, we still need the ELF
  * definitions for reading the internal structures of the dynamic linker.
  */
-#include <elf.h>
+/*#include <elf.h>*/
 #elif DYNLINK == DYNLINK_WINDOWS
 /* We use the imagehlp library on Windows platforms to obtain information about
  * the symbols loaded from third-party and system DLLs.  We can also use it to
