--- ./h/FreeBSD.h.orig	Fri Nov  1 04:09:34 2002
+++ ./h/FreeBSD.h	Sun Sep 14 01:51:55 2003
@@ -1,5 +1,5 @@
 /*
- * FreeBSD.h for gcl 1.1
+ * FreeBSD.h for gcl
  *
  * Ported by Jeffrey Hsu (hsu@freebsd.org).
  *  Looked at previous versions by Hsu, Werkowsksi, Tobin, and Mogart.
@@ -8,6 +8,50 @@
 
 #include "bsd.h"
 
+#ifndef __ELF__
+#error FreeBSD systems use ELF
+#endif
+
+#undef HAVE_AOUT
+#define HAVE_AOUT <elf.h>
+#define HAVE_ELF
+
+#if defined(__i386__)
+#define __ELF_NATIVE_CLASS 32
+#endif
+#if defined(__alpha__) || defined(__sparc64__) || defined(__ia64__)
+#define __ELF_NATIVE_CLASS 64
+#endif
+#define mjoin(a,b) a ## b
+#define Mjoin(a,b) mjoin(a,b)
+#if !defined(ElfW)
+#define ElfW(a) Mjoin(Elf,Mjoin(__ELF_NATIVE_CLASS,Mjoin(_,a)))
+#endif
+#define ELFW(a) Mjoin(ELF,Mjoin(__ELF_NATIVE_CLASS,Mjoin(_,a)))
+
+/* Seeking to the end of ELF data is a little messy... */
+#include <link.h>
+#define SEEK_TO_END_OFILE(fp)\
+  do { \
+	long offset = 0, endofelf; int j; \
+	ElfW(Ehdr) eheader; ElfW(Shdr) shdr; \
+        fseek(fp, 0, SEEK_SET); \
+        fread(&eheader, sizeof(eheader), 1, fp); \
+  /* in case the headers themselves come AFTER the actual sections */ \
+	endofelf=offset = eheader.e_shoff+ eheader.e_shentsize *eheader.e_shnum;\
+        fseek(fp, eheader.e_shoff, SEEK_SET); \
+	if ( eheader.e_shentsize != sizeof(ElfW(Shdr)) ) \
+	  { FEerror("Bad ELF section header size",0); } \
+        for ( j = 0; j < eheader.e_shnum; j++ ) \
+	  { fread(&shdr,eheader.e_shentsize,1,fp); \
+            if ( (shdr.sh_offset > offset) && (shdr.sh_type != SHT_NOBITS) ) \
+	      { offset = shdr.sh_offset; endofelf = offset+shdr.sh_size; } \
+	  } \
+	if ( fseek(fp, endofelf, SEEK_SET) ) \
+	    FEerror("Bad ELF file",0); \
+      } while(0)
+
+
 #undef LD_COMMAND
 #define LD_COMMAND(command,main,start,input,ldarg,output) \
   sprintf(command, "ld -dc -N -x -A %s -T %x %s %s -o %s", \
@@ -39,17 +83,9 @@
 #endif
 
 #define DATA_BEGIN (char *) N_DATADDR(header);
-#define A_TEXT_OFFSET(x) (sizeof (struct exec))
-#define A_TEXT_SEEK(hdr) (N_TXTOFF(hdr) + A_TEXT_OFFSET(hdr))
-#define start_of_data() &etext
-#define start_of_text() ((char *)(sizeof(struct exec) + getpagesize()))
 
-#define UNIXSAVE "unexec.c"
-#ifdef UNIXSAVE 
- extern char etext;
-#endif
-
-#define RELOC_FILE "rel_sun3.c"	/* for SFASL - enabled in bsd.h */
+/*#define UNEXEC_USE_MAP_PRIVATE*/
+#define UNIXSAVE "unexelf.c"
 
 #ifdef CLOCKS_PER_SEC
 #define HZ CLOCKS_PER_SEC
@@ -67,7 +103,8 @@
 #define SETUP_SIG_STACK \
 { \
 	static struct sigaltstack estack; \
-	if ((estack.ss_sp = malloc(SIGSTKSZ)) == NULL) \
+	if (estack.ss_sp == NULL && \
+	    (estack.ss_sp = malloc(SIGSTKSZ)) == NULL) \
 	  perror("malloc"); \
 	estack.ss_size = SIGSTKSZ; \
 	estack.ss_flags = 0; \
