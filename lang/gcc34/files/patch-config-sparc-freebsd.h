--- gcc/config/sparc/freebsd.h.orig	2004-07-17 21:18:58.000000000 +0000
+++ gcc/config/sparc/freebsd.h	2008-02-15 21:04:17.000000000 +0000
@@ -24,11 +24,21 @@
   { "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }
 
 /* FreeBSD needs the platform name (sparc64) defined.
-   Emacs needs to know if the arch is 64 or 32-bits.  */
+   Emacs needs to know if the arch is 64 or 32-bits.
+   This also selects which targets are available via -mcpu.  */
 
-#undef  CPP_CPU64_DEFAULT_SPEC
-#define CPP_CPU64_DEFAULT_SPEC \
-  "-D__sparc64__ -D__sparc_v9__ -D__sparcv9 -D__arch64__"
+#undef  FBSD_TARGET_CPU_CPP_BUILTINS
+#define FBSD_TARGET_CPU_CPP_BUILTINS()		\
+  do						\
+    {						\
+      builtin_define ("__LP64__");		\
+      builtin_define ("__sparc64__");		\
+      builtin_define ("__sparc_v9__");		\
+      builtin_define ("__sparcv9");		\
+      builtin_define ("__sparc__");		\
+      builtin_define ("__arch64__");		\
+    }						\
+  while (0)
 
 #define LINK_SPEC "%(link_arch)						\
   %{!mno-relax:%{!r:-relax}}						\
