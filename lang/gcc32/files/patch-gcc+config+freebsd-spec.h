--- gcc/config/freebsd-spec.h.org	Sat Aug 13 10:18:00 2005
+++ gcc/config/freebsd-spec.h	Sat Aug 13 18:40:03 2005
@@ -48,6 +48,11 @@
    || !strcmp ((STR), "soname") || !strcmp ((STR), "defsym") 		\
    || !strcmp ((STR), "assert") || !strcmp ((STR), "dynamic-linker"))
 
+#if FBSD_MAJOR == 7
+#define FBSD_CPP_PREDEFINES \
+  "-D__FreeBSD__=7 -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
+#endif
+
 #if FBSD_MAJOR == 6
 #define FBSD_CPP_PREDEFINES \
   "-D__FreeBSD__=6 -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
