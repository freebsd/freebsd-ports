Index: h/notcomp.h
===================================================================
RCS file: /cvsroot/gcl/gcl/h/notcomp.h,v
retrieving revision 1.15.6.3
diff -u -d -b -B -r1.15.6.3 notcomp.h
--- h/notcomp.h	12 Feb 2004 05:23:13 -0000	1.15.6.3
+++ h/notcomp.h	19 Jul 2004 13:19:38 -0000
@@ -81,9 +81,21 @@
    pack == LISP ? LISP_makefun(string,fname,argd) : \
    error("Bad pack variable in MAKEFUN\n"))
 
+#if defined(__i386__)
+#define __ELF_NATIVE_CLASS 32
+#endif
+#if defined(__alpha__) || defined(__sparc64__) || defined(__ia64__)
+#define __ELF_NATIVE_CLASS 64
+#endif
+
 #define mjoin(a_,b_) a_ ## b_
 #define Mjoin(a_,b_) mjoin(a_,b_)
 
+#if !defined(ElfW)
+#define ElfW(a) Mjoin(Elf,Mjoin(__ELF_NATIVE_CLASS,Mjoin(_,a)))
+#endif
+#define ELFW(a) Mjoin(ELF,Mjoin(__ELF_NATIVE_CLASS,Mjoin(_,a)))
+
 #define SI 0
 #define LISP 1
 
