commit 3bad0a21b4d13d8d10691f382c836897fa7a7cb9
Author: Breno Leitao <leitao@debian.org>
Date:   Wed Feb 22 16:45:00 2017 -0300

    Drop ppc64-specific workaround for versioned symbols
    
    Currently aserver fails to build when using parameter
    --without-versioned, due to an workaround for ppc64
    (06221f86d207cb33ddd4867ca5301eeb247c4400).  This workaround is
    not required anymore on the ppc64 ABI v2, and, in fact is breaking the
    compilation. Reverting this commit
    
    Signed-off-by: Breno Leitao <leitao@debian.org>
    Signed-off-by: Takashi Iwai <tiwai@suse.de>

--- include/alsa-symbols.h.orig	2016-08-02 17:48:38 UTC
+++ include/alsa-symbols.h
@@ -29,19 +29,10 @@
 #define INTERNAL_CONCAT2_2(Pre, Post) Pre##Post
 #define INTERNAL(Name) INTERNAL_CONCAT2_2(__, Name)
 
-#ifdef __powerpc64__
-# define symbol_version(real, name, version) 			\
-	__asm__ (".symver " ASM_NAME(#real) "," ASM_NAME(#name) "@" #version);	\
-	__asm__ (".symver ." ASM_NAME(#real) ",." ASM_NAME(#name) "@" #version)
-# define default_symbol_version(real, name, version) 		\
-	__asm__ (".symver " ASM_NAME(#real) "," ASM_NAME(#name) "@@" #version);	\
-	__asm__ (".symver ." ASM_NAME(#real) ",." ASM_NAME(#name) "@@" #version)
-#else
 # define symbol_version(real, name, version) \
 	__asm__ (".symver " ASM_NAME(#real) "," ASM_NAME(#name) "@" #version)
 # define default_symbol_version(real, name, version) \
 	__asm__ (".symver " ASM_NAME(#real) "," ASM_NAME(#name) "@@" #version)
-#endif
 
 #ifdef USE_VERSIONED_SYMBOLS
 #define use_symbol_version(real, name, version) \
@@ -50,13 +41,6 @@
 		default_symbol_version(real, name, version)
 #else
 #define use_symbol_version(real, name, version) /* nothing */
-#ifdef __powerpc64__
-#define use_default_symbol_version(real, name, version) \
-	__asm__ (".weak " ASM_NAME(#name)); 			\
-	__asm__ (".weak ." ASM_NAME(#name)); 			\
-	__asm__ (".set " ASM_NAME(#name) "," ASM_NAME(#real));		\
-	__asm__ (".set ." ASM_NAME(#name) ",." ASM_NAME(#real))
-#else
 #if defined(__alpha__) || defined(__mips__)
 #define use_default_symbol_version(real, name, version) \
         __asm__ (".weak " ASM_NAME(#name)); \
@@ -65,7 +49,6 @@
 #define use_default_symbol_version(real, name, version) \
 	__asm__ (".weak " ASM_NAME(#name)); \
 	__asm__ (".set " ASM_NAME(#name) "," ASM_NAME(#real))
-#endif
 #endif
 #endif
 
