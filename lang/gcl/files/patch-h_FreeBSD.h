--- h/FreeBSD.h	2004-06-12 12:28:15.000000000 -0400
+++ h/FreeBSD.h	2009-12-07 12:07:37.000000000 -0500
@@ -11,9 +11,12 @@
 #endif
 
 #if defined(__i386__)
+#define RELOC_H "elf32_i386_reloc.h"
 #define __ELF_NATIVE_CLASS 32
 #endif
-#if defined(__alpha__) || defined(__sparc64__) || defined(__ia64__)
+#if defined(__amd64__) || defined(__sparc64__) || defined(__ia64__)
+#define C_GC_OFFSET 4
+#define RELOC_H "elf64_i386_reloc.h"
 #define __ELF_NATIVE_CLASS 64
 #endif
 
@@ -32,7 +35,12 @@
 #endif
 #include "linux.h"
 
-#if defined(__i386__)
+#if defined(SET_SESSION_ID)
+#undef SET_SESSION_ID
+#endif
+#define SET_SESSION_ID() (setpgrp(0,0) ? -1 : 0)
+
+#if defined(__i386__) || defined(__amd64__)
 #define I386
 #endif
 
@@ -48,7 +56,7 @@
 	int c = 0;						\
 								\
 	if (							\
-		(fp)->_r <= 0 &&				\
+		((FILE *)fp)->_r <= 0 &&				\
 		(ioctl(((FILE *)fp)->_file, FIONREAD, &c), c <= 0)	\
 	)							\
 		return(FALSE);					\
@@ -68,7 +76,11 @@
 #ifdef CLOCKS_PER_SEC
 #define HZ CLOCKS_PER_SEC
 #else
-#define HZ 128
+#	ifdef _SC_CLK_TCK	/* Define HZ properly: */
+#		define HZ	sysconf(_SC_CLK_TCK)
+#	elif	!defined(HZ)
+#		define HZ	128
+#	endif
 #endif
 /* #define ss_base ss_sp */
 
