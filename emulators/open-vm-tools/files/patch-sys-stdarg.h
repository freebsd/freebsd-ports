diff --git modules/freebsd/vmblock/os.h open-vm-tools/modules/freebsd/vmblock/os.h
index 075fcbaa..36a2e6ee 100644
--- modules/freebsd/vmblock/os.h
+++ modules/freebsd/vmblock/os.h
@@ -43,8 +43,8 @@
 #include <sys/sx.h>
 #include <sys/proc.h>
 #include <sys/condvar.h>
+#include <sys/stdarg.h>
 #include <vm/uma.h>
-#include <machine/stdarg.h>
 
 #include "vm_basic_types.h"
 
diff --git modules/freebsd/vmblock/os_panic.c open-vm-tools/modules/freebsd/vmblock/os_panic.c
index cacf41c0..08e5f8bb 100644
--- modules/freebsd/vmblock/os_panic.c
+++ modules/freebsd/vmblock/os_panic.c
@@ -34,7 +34,7 @@
 
 #include <sys/param.h>
 #include <sys/systm.h>
-#include <machine/stdarg.h>
+#include <sys/stdarg.h>
 
 #include "os.h"
 
diff --git modules/freebsd/vmmemctl/kernelStubsBSD.c open-vm-tools/modules/freebsd/vmmemctl/kernelStubsBSD.c
index b6fb72f5..798021ca 100644
--- modules/freebsd/vmmemctl/kernelStubsBSD.c
+++ modules/freebsd/vmmemctl/kernelStubsBSD.c
@@ -26,7 +26,7 @@
 
 #include <sys/types.h>
 #include <sys/param.h>
-#include <machine/stdarg.h>
+#include <sys/stdarg.h>
 #include <sys/systm.h>
 #include <sys/kernel.h>
 
diff --git modules/freebsd/vmmemctl/os.c open-vm-tools/modules/freebsd/vmmemctl/os.c
index fff7e052..4fc97148 100644
--- modules/freebsd/vmmemctl/os.c
+++ modules/freebsd/vmmemctl/os.c
@@ -42,6 +42,7 @@
 #include <sys/module.h>
 #include <sys/conf.h>
 #include <sys/rwlock.h>
+#include <sys/stdarg.h>
 #include <sys/sysctl.h>
 
 #include <vm/vm.h>
@@ -53,8 +54,6 @@
 #include <vm/vm_param.h>
 #include <sys/vmmeter.h>
 
-#include <machine/stdarg.h>
-
 #include "os.h"
 #include "vmballoon.h"
 
diff --git modules/shared/vmblock/stubs.c open-vm-tools/modules/shared/vmblock/stubs.c
index cc158bc2..7e55b36a 100644
--- modules/shared/vmblock/stubs.c
+++ modules/shared/vmblock/stubs.c
@@ -64,7 +64,7 @@
 
 #if defined(__FreeBSD__)
 #include <sys/cdefs.h>
-#include <machine/stdarg.h>
+#include <sys/stdarg.h>
 #else
 #include <stdarg.h>
 #endif
diff --git modules/shared/vmmemctl/kernelStubs.h open-vm-tools/modules/shared/vmmemctl/kernelStubs.h
index a3bbaf84..4fd2d495 100644
--- modules/shared/vmmemctl/kernelStubs.h
+++ modules/shared/vmmemctl/kernelStubs.h
@@ -143,7 +143,7 @@
 #   include <sys/malloc.h>
 #   include <sys/param.h>
 #   include <sys/kernel.h>
-#   include <machine/stdarg.h>
+#   include <sys/stdarg.h>
 #   include <sys/libkern.h>
 #elif defined(__APPLE__)
 #   include "vm_basic_types.h"
diff --git modules/solaris/vmhgfs/kernelStubs.h open-vm-tools/modules/solaris/vmhgfs/kernelStubs.h
index 0be3c496..1eb7c302 100644
--- modules/solaris/vmhgfs/kernelStubs.h
+++ modules/solaris/vmhgfs/kernelStubs.h
@@ -102,7 +102,7 @@
 #   include <sys/malloc.h>
 #   include <sys/param.h>
 #   include <sys/kernel.h>
-#   include <machine/stdarg.h>
+#   include <sys/stdarg.h>
 #   include <sys/libkern.h>
 #elif defined(__APPLE__)
 #   include "vm_basic_types.h"
