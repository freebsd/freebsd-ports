--- src/atomic/gcc_x86.c.orig	2016-04-03 10:11:30 UTC
+++ src/atomic/gcc_x86.c
@@ -51,7 +51,7 @@ parrot_i386_cmpxchg(ARGMOD(void *volatil
                                         ARGIN_NULLOK(void *update))
 {
     ASSERT_ARGS(parrot_i386_cmpxchg)
-#if defined(PARROT_HAS_AMD64_GCC_CMPXCHG) || __WORDSIZE == 64
+#if defined(PARROT_HAS_AMD64_GCC_CMPXCHG)
     __asm__ __volatile__("lock\n"
                          "cmpxchgq %1,%2":"=a"(expect):"q"(update), "m"(*ptr),
                          "0"(expect)
@@ -85,7 +85,7 @@ parrot_i386_xadd(ARGIN(volatile long *l)
 {
     ASSERT_ARGS(parrot_i386_xadd)
     long result = amount;
-#if defined(PARROT_HAS_AMD64_GCC_CMPXCHG) || __WORDSIZE == 64
+#if defined(PARROT_HAS_AMD64_GCC_CMPXCHG)
     __asm__ __volatile__("lock\n" "xaddq %0, %1" : "=r"(result), "=m"(*l) :
             "0"(result), "m"(*l));
 #elif defined(PARROT_HAS_I386_GCC_CMPXCHG)
