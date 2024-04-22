https://gitlab.haskell.org/ghc/ghc/-/merge_requests/12227

https://gitlab.haskell.org/ghc/ghc/-/issues/24580

--- rts/ARMOutlineAtomicsSymbols.h.orig	2024-01-08 13:24:59 UTC
+++ rts/ARMOutlineAtomicsSymbols.h
@@ -10,583 +10,583 @@
 #include <stdint.h>
 #include <stdatomic.h>
 
-uint8_t ghc___aarch64_cas1_relax(uint8_t old, uint8_t new, uint8_t* p);
-uint8_t ghc___aarch64_cas1_relax(uint8_t old, uint8_t new, uint8_t* p) {
+uint8_t ghc___aarch64_cas1_relax(uint8_t old, uint8_t new, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_cas1_relax(uint8_t old, uint8_t new, _Atomic uint8_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_relaxed, memory_order_relaxed); return old;
 }
 
-uint8_t ghc___aarch64_cas1_acq(uint8_t old, uint8_t new, uint8_t* p);
-uint8_t ghc___aarch64_cas1_acq(uint8_t old, uint8_t new, uint8_t* p) {
+uint8_t ghc___aarch64_cas1_acq(uint8_t old, uint8_t new, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_cas1_acq(uint8_t old, uint8_t new, _Atomic uint8_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acquire, memory_order_acquire); return old;
 }
 
-uint8_t ghc___aarch64_cas1_acq_rel(uint8_t old, uint8_t new, uint8_t* p);
-uint8_t ghc___aarch64_cas1_acq_rel(uint8_t old, uint8_t new, uint8_t* p) {
+uint8_t ghc___aarch64_cas1_acq_rel(uint8_t old, uint8_t new, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_cas1_acq_rel(uint8_t old, uint8_t new, _Atomic uint8_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acq_rel, memory_order_acquire); return old;
 }
 
-uint8_t ghc___aarch64_cas1_sync(uint8_t old, uint8_t new, uint8_t* p);
-uint8_t ghc___aarch64_cas1_sync(uint8_t old, uint8_t new, uint8_t* p) {
+uint8_t ghc___aarch64_cas1_sync(uint8_t old, uint8_t new, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_cas1_sync(uint8_t old, uint8_t new, _Atomic uint8_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_seq_cst, memory_order_seq_cst); return old;
 }
 
-uint16_t ghc___aarch64_cas2_relax(uint16_t old, uint16_t new, uint16_t* p);
-uint16_t ghc___aarch64_cas2_relax(uint16_t old, uint16_t new, uint16_t* p) {
+uint16_t ghc___aarch64_cas2_relax(uint16_t old, uint16_t new, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_cas2_relax(uint16_t old, uint16_t new, _Atomic uint16_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_relaxed, memory_order_relaxed); return old;
 }
 
-uint16_t ghc___aarch64_cas2_acq(uint16_t old, uint16_t new, uint16_t* p);
-uint16_t ghc___aarch64_cas2_acq(uint16_t old, uint16_t new, uint16_t* p) {
+uint16_t ghc___aarch64_cas2_acq(uint16_t old, uint16_t new, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_cas2_acq(uint16_t old, uint16_t new, _Atomic uint16_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acquire, memory_order_acquire); return old;
 }
 
-uint16_t ghc___aarch64_cas2_acq_rel(uint16_t old, uint16_t new, uint16_t* p);
-uint16_t ghc___aarch64_cas2_acq_rel(uint16_t old, uint16_t new, uint16_t* p) {
+uint16_t ghc___aarch64_cas2_acq_rel(uint16_t old, uint16_t new, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_cas2_acq_rel(uint16_t old, uint16_t new, _Atomic uint16_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acq_rel, memory_order_acquire); return old;
 }
 
-uint16_t ghc___aarch64_cas2_sync(uint16_t old, uint16_t new, uint16_t* p);
-uint16_t ghc___aarch64_cas2_sync(uint16_t old, uint16_t new, uint16_t* p) {
+uint16_t ghc___aarch64_cas2_sync(uint16_t old, uint16_t new, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_cas2_sync(uint16_t old, uint16_t new, _Atomic uint16_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_seq_cst, memory_order_seq_cst); return old;
 }
 
-uint32_t ghc___aarch64_cas4_relax(uint32_t old, uint32_t new, uint32_t* p);
-uint32_t ghc___aarch64_cas4_relax(uint32_t old, uint32_t new, uint32_t* p) {
+uint32_t ghc___aarch64_cas4_relax(uint32_t old, uint32_t new, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_cas4_relax(uint32_t old, uint32_t new, _Atomic uint32_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_relaxed, memory_order_relaxed); return old;
 }
 
-uint32_t ghc___aarch64_cas4_acq(uint32_t old, uint32_t new, uint32_t* p);
-uint32_t ghc___aarch64_cas4_acq(uint32_t old, uint32_t new, uint32_t* p) {
+uint32_t ghc___aarch64_cas4_acq(uint32_t old, uint32_t new, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_cas4_acq(uint32_t old, uint32_t new, _Atomic uint32_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acquire, memory_order_acquire); return old;
 }
 
-uint32_t ghc___aarch64_cas4_acq_rel(uint32_t old, uint32_t new, uint32_t* p);
-uint32_t ghc___aarch64_cas4_acq_rel(uint32_t old, uint32_t new, uint32_t* p) {
+uint32_t ghc___aarch64_cas4_acq_rel(uint32_t old, uint32_t new, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_cas4_acq_rel(uint32_t old, uint32_t new, _Atomic uint32_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acq_rel, memory_order_acquire); return old;
 }
 
-uint32_t ghc___aarch64_cas4_sync(uint32_t old, uint32_t new, uint32_t* p);
-uint32_t ghc___aarch64_cas4_sync(uint32_t old, uint32_t new, uint32_t* p) {
+uint32_t ghc___aarch64_cas4_sync(uint32_t old, uint32_t new, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_cas4_sync(uint32_t old, uint32_t new, _Atomic uint32_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_seq_cst, memory_order_seq_cst); return old;
 }
 
-uint64_t ghc___aarch64_cas8_relax(uint64_t old, uint64_t new, uint64_t* p);
-uint64_t ghc___aarch64_cas8_relax(uint64_t old, uint64_t new, uint64_t* p) {
+uint64_t ghc___aarch64_cas8_relax(uint64_t old, uint64_t new, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_cas8_relax(uint64_t old, uint64_t new, _Atomic uint64_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_relaxed, memory_order_relaxed); return old;
 }
 
-uint64_t ghc___aarch64_cas8_acq(uint64_t old, uint64_t new, uint64_t* p);
-uint64_t ghc___aarch64_cas8_acq(uint64_t old, uint64_t new, uint64_t* p) {
+uint64_t ghc___aarch64_cas8_acq(uint64_t old, uint64_t new, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_cas8_acq(uint64_t old, uint64_t new, _Atomic uint64_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acquire, memory_order_acquire); return old;
 }
 
-uint64_t ghc___aarch64_cas8_acq_rel(uint64_t old, uint64_t new, uint64_t* p);
-uint64_t ghc___aarch64_cas8_acq_rel(uint64_t old, uint64_t new, uint64_t* p) {
+uint64_t ghc___aarch64_cas8_acq_rel(uint64_t old, uint64_t new, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_cas8_acq_rel(uint64_t old, uint64_t new, _Atomic uint64_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_acq_rel, memory_order_acquire); return old;
 }
 
-uint64_t ghc___aarch64_cas8_sync(uint64_t old, uint64_t new, uint64_t* p);
-uint64_t ghc___aarch64_cas8_sync(uint64_t old, uint64_t new, uint64_t* p) {
+uint64_t ghc___aarch64_cas8_sync(uint64_t old, uint64_t new, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_cas8_sync(uint64_t old, uint64_t new, _Atomic uint64_t* p) {
   atomic_compare_exchange_strong_explicit(p, &old, new, memory_order_seq_cst, memory_order_seq_cst); return old;
 }
 
-uint8_t ghc___aarch64_swp1_relax(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_swp1_relax(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_swp1_relax(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_swp1_relax(uint8_t v, _Atomic uint8_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_relaxed);
 }
 
-uint8_t ghc___aarch64_swp1_acq(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_swp1_acq(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_swp1_acq(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_swp1_acq(uint8_t v, _Atomic uint8_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acquire);
 }
 
-uint8_t ghc___aarch64_swp1_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_swp1_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_swp1_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_swp1_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_release);
 }
 
-uint8_t ghc___aarch64_swp1_acq_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_swp1_acq_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_swp1_acq_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_swp1_acq_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acq_rel);
 }
 
-uint8_t ghc___aarch64_swp1_sync(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_swp1_sync(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_swp1_sync(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_swp1_sync(uint8_t v, _Atomic uint8_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_seq_cst);
 }
 
-uint16_t ghc___aarch64_swp2_relax(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_swp2_relax(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_swp2_relax(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_swp2_relax(uint16_t v, _Atomic uint16_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_relaxed);
 }
 
-uint16_t ghc___aarch64_swp2_acq(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_swp2_acq(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_swp2_acq(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_swp2_acq(uint16_t v, _Atomic uint16_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acquire);
 }
 
-uint16_t ghc___aarch64_swp2_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_swp2_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_swp2_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_swp2_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_release);
 }
 
-uint16_t ghc___aarch64_swp2_acq_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_swp2_acq_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_swp2_acq_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_swp2_acq_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acq_rel);
 }
 
-uint16_t ghc___aarch64_swp2_sync(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_swp2_sync(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_swp2_sync(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_swp2_sync(uint16_t v, _Atomic uint16_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_seq_cst);
 }
 
-uint32_t ghc___aarch64_swp4_relax(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_swp4_relax(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_swp4_relax(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_swp4_relax(uint32_t v, _Atomic uint32_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_relaxed);
 }
 
-uint32_t ghc___aarch64_swp4_acq(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_swp4_acq(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_swp4_acq(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_swp4_acq(uint32_t v, _Atomic uint32_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acquire);
 }
 
-uint32_t ghc___aarch64_swp4_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_swp4_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_swp4_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_swp4_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_release);
 }
 
-uint32_t ghc___aarch64_swp4_acq_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_swp4_acq_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_swp4_acq_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_swp4_acq_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acq_rel);
 }
 
-uint32_t ghc___aarch64_swp4_sync(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_swp4_sync(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_swp4_sync(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_swp4_sync(uint32_t v, _Atomic uint32_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_seq_cst);
 }
 
-uint64_t ghc___aarch64_swp8_relax(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_swp8_relax(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_swp8_relax(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_swp8_relax(uint64_t v, _Atomic uint64_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_relaxed);
 }
 
-uint64_t ghc___aarch64_swp8_acq(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_swp8_acq(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_swp8_acq(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_swp8_acq(uint64_t v, _Atomic uint64_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acquire);
 }
 
-uint64_t ghc___aarch64_swp8_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_swp8_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_swp8_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_swp8_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_release);
 }
 
-uint64_t ghc___aarch64_swp8_acq_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_swp8_acq_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_swp8_acq_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_swp8_acq_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_acq_rel);
 }
 
-uint64_t ghc___aarch64_swp8_sync(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_swp8_sync(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_swp8_sync(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_swp8_sync(uint64_t v, _Atomic uint64_t* p) {
   return atomic_exchange_explicit(p, v, memory_order_seq_cst);
 }
 
-uint8_t ghc___aarch64_ldadd1_relax(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldadd1_relax(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldadd1_relax(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldadd1_relax(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_relaxed);
 }
 
-uint8_t ghc___aarch64_ldadd1_acq(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldadd1_acq(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldadd1_acq(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldadd1_acq(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acquire);
 }
 
-uint8_t ghc___aarch64_ldadd1_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldadd1_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldadd1_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldadd1_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_release);
 }
 
-uint8_t ghc___aarch64_ldadd1_acq_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldadd1_acq_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldadd1_acq_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldadd1_acq_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acq_rel);
 }
 
-uint8_t ghc___aarch64_ldadd1_sync(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldadd1_sync(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldadd1_sync(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldadd1_sync(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_seq_cst);
 }
 
-uint16_t ghc___aarch64_ldadd2_relax(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldadd2_relax(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldadd2_relax(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldadd2_relax(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_relaxed);
 }
 
-uint16_t ghc___aarch64_ldadd2_acq(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldadd2_acq(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldadd2_acq(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldadd2_acq(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acquire);
 }
 
-uint16_t ghc___aarch64_ldadd2_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldadd2_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldadd2_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldadd2_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_release);
 }
 
-uint16_t ghc___aarch64_ldadd2_acq_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldadd2_acq_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldadd2_acq_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldadd2_acq_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acq_rel);
 }
 
-uint16_t ghc___aarch64_ldadd2_sync(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldadd2_sync(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldadd2_sync(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldadd2_sync(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_seq_cst);
 }
 
-uint32_t ghc___aarch64_ldadd4_relax(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldadd4_relax(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldadd4_relax(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldadd4_relax(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_relaxed);
 }
 
-uint32_t ghc___aarch64_ldadd4_acq(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldadd4_acq(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldadd4_acq(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldadd4_acq(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acquire);
 }
 
-uint32_t ghc___aarch64_ldadd4_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldadd4_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldadd4_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldadd4_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_release);
 }
 
-uint32_t ghc___aarch64_ldadd4_acq_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldadd4_acq_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldadd4_acq_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldadd4_acq_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acq_rel);
 }
 
-uint32_t ghc___aarch64_ldadd4_sync(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldadd4_sync(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldadd4_sync(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldadd4_sync(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_seq_cst);
 }
 
-uint64_t ghc___aarch64_ldadd8_relax(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldadd8_relax(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldadd8_relax(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldadd8_relax(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_relaxed);
 }
 
-uint64_t ghc___aarch64_ldadd8_acq(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldadd8_acq(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldadd8_acq(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldadd8_acq(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acquire);
 }
 
-uint64_t ghc___aarch64_ldadd8_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldadd8_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldadd8_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldadd8_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_release);
 }
 
-uint64_t ghc___aarch64_ldadd8_acq_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldadd8_acq_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldadd8_acq_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldadd8_acq_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_acq_rel);
 }
 
-uint64_t ghc___aarch64_ldadd8_sync(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldadd8_sync(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldadd8_sync(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldadd8_sync(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_add_explicit(p, v, memory_order_seq_cst);
 }
 
-uint8_t ghc___aarch64_ldclr1_relax(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldclr1_relax(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldclr1_relax(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldclr1_relax(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_relaxed);
 }
 
-uint8_t ghc___aarch64_ldclr1_acq(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldclr1_acq(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldclr1_acq(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldclr1_acq(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acquire);
 }
 
-uint8_t ghc___aarch64_ldclr1_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldclr1_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldclr1_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldclr1_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_release);
 }
 
-uint8_t ghc___aarch64_ldclr1_acq_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldclr1_acq_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldclr1_acq_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldclr1_acq_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acq_rel);
 }
 
-uint8_t ghc___aarch64_ldclr1_sync(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldclr1_sync(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldclr1_sync(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldclr1_sync(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_seq_cst);
 }
 
-uint16_t ghc___aarch64_ldclr2_relax(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldclr2_relax(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldclr2_relax(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldclr2_relax(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_relaxed);
 }
 
-uint16_t ghc___aarch64_ldclr2_acq(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldclr2_acq(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldclr2_acq(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldclr2_acq(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acquire);
 }
 
-uint16_t ghc___aarch64_ldclr2_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldclr2_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldclr2_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldclr2_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_release);
 }
 
-uint16_t ghc___aarch64_ldclr2_acq_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldclr2_acq_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldclr2_acq_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldclr2_acq_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acq_rel);
 }
 
-uint16_t ghc___aarch64_ldclr2_sync(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldclr2_sync(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldclr2_sync(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldclr2_sync(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_seq_cst);
 }
 
-uint32_t ghc___aarch64_ldclr4_relax(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldclr4_relax(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldclr4_relax(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldclr4_relax(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_relaxed);
 }
 
-uint32_t ghc___aarch64_ldclr4_acq(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldclr4_acq(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldclr4_acq(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldclr4_acq(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acquire);
 }
 
-uint32_t ghc___aarch64_ldclr4_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldclr4_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldclr4_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldclr4_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_release);
 }
 
-uint32_t ghc___aarch64_ldclr4_acq_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldclr4_acq_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldclr4_acq_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldclr4_acq_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acq_rel);
 }
 
-uint32_t ghc___aarch64_ldclr4_sync(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldclr4_sync(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldclr4_sync(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldclr4_sync(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_seq_cst);
 }
 
-uint64_t ghc___aarch64_ldclr8_relax(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldclr8_relax(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldclr8_relax(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldclr8_relax(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_relaxed);
 }
 
-uint64_t ghc___aarch64_ldclr8_acq(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldclr8_acq(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldclr8_acq(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldclr8_acq(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acquire);
 }
 
-uint64_t ghc___aarch64_ldclr8_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldclr8_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldclr8_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldclr8_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_release);
 }
 
-uint64_t ghc___aarch64_ldclr8_acq_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldclr8_acq_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldclr8_acq_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldclr8_acq_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_acq_rel);
 }
 
-uint64_t ghc___aarch64_ldclr8_sync(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldclr8_sync(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldclr8_sync(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldclr8_sync(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_and_explicit(p, v, memory_order_seq_cst);
 }
 
-uint8_t ghc___aarch64_ldeor1_relax(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldeor1_relax(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldeor1_relax(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldeor1_relax(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_relaxed);
 }
 
-uint8_t ghc___aarch64_ldeor1_acq(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldeor1_acq(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldeor1_acq(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldeor1_acq(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acquire);
 }
 
-uint8_t ghc___aarch64_ldeor1_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldeor1_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldeor1_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldeor1_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_release);
 }
 
-uint8_t ghc___aarch64_ldeor1_acq_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldeor1_acq_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldeor1_acq_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldeor1_acq_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acq_rel);
 }
 
-uint8_t ghc___aarch64_ldeor1_sync(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldeor1_sync(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldeor1_sync(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldeor1_sync(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_seq_cst);
 }
 
-uint16_t ghc___aarch64_ldeor2_relax(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldeor2_relax(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldeor2_relax(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldeor2_relax(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_relaxed);
 }
 
-uint16_t ghc___aarch64_ldeor2_acq(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldeor2_acq(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldeor2_acq(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldeor2_acq(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acquire);
 }
 
-uint16_t ghc___aarch64_ldeor2_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldeor2_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldeor2_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldeor2_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_release);
 }
 
-uint16_t ghc___aarch64_ldeor2_acq_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldeor2_acq_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldeor2_acq_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldeor2_acq_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acq_rel);
 }
 
-uint16_t ghc___aarch64_ldeor2_sync(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldeor2_sync(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldeor2_sync(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldeor2_sync(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_seq_cst);
 }
 
-uint32_t ghc___aarch64_ldeor4_relax(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldeor4_relax(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldeor4_relax(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldeor4_relax(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_relaxed);
 }
 
-uint32_t ghc___aarch64_ldeor4_acq(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldeor4_acq(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldeor4_acq(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldeor4_acq(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acquire);
 }
 
-uint32_t ghc___aarch64_ldeor4_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldeor4_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldeor4_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldeor4_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_release);
 }
 
-uint32_t ghc___aarch64_ldeor4_acq_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldeor4_acq_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldeor4_acq_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldeor4_acq_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acq_rel);
 }
 
-uint32_t ghc___aarch64_ldeor4_sync(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldeor4_sync(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldeor4_sync(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldeor4_sync(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_seq_cst);
 }
 
-uint64_t ghc___aarch64_ldeor8_relax(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldeor8_relax(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldeor8_relax(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldeor8_relax(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_relaxed);
 }
 
-uint64_t ghc___aarch64_ldeor8_acq(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldeor8_acq(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldeor8_acq(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldeor8_acq(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acquire);
 }
 
-uint64_t ghc___aarch64_ldeor8_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldeor8_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldeor8_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldeor8_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_release);
 }
 
-uint64_t ghc___aarch64_ldeor8_acq_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldeor8_acq_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldeor8_acq_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldeor8_acq_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_acq_rel);
 }
 
-uint64_t ghc___aarch64_ldeor8_sync(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldeor8_sync(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldeor8_sync(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldeor8_sync(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_xor_explicit(p, v, memory_order_seq_cst);
 }
 
-uint8_t ghc___aarch64_ldset1_relax(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldset1_relax(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldset1_relax(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldset1_relax(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_relaxed);
 }
 
-uint8_t ghc___aarch64_ldset1_acq(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldset1_acq(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldset1_acq(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldset1_acq(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acquire);
 }
 
-uint8_t ghc___aarch64_ldset1_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldset1_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldset1_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldset1_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_release);
 }
 
-uint8_t ghc___aarch64_ldset1_acq_rel(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldset1_acq_rel(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldset1_acq_rel(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldset1_acq_rel(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acq_rel);
 }
 
-uint8_t ghc___aarch64_ldset1_sync(uint8_t v, uint8_t* p);
-uint8_t ghc___aarch64_ldset1_sync(uint8_t v, uint8_t* p) {
+uint8_t ghc___aarch64_ldset1_sync(uint8_t v, _Atomic uint8_t* p);
+uint8_t ghc___aarch64_ldset1_sync(uint8_t v, _Atomic uint8_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_seq_cst);
 }
 
-uint16_t ghc___aarch64_ldset2_relax(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldset2_relax(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldset2_relax(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldset2_relax(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_relaxed);
 }
 
-uint16_t ghc___aarch64_ldset2_acq(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldset2_acq(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldset2_acq(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldset2_acq(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acquire);
 }
 
-uint16_t ghc___aarch64_ldset2_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldset2_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldset2_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldset2_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_release);
 }
 
-uint16_t ghc___aarch64_ldset2_acq_rel(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldset2_acq_rel(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldset2_acq_rel(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldset2_acq_rel(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acq_rel);
 }
 
-uint16_t ghc___aarch64_ldset2_sync(uint16_t v, uint16_t* p);
-uint16_t ghc___aarch64_ldset2_sync(uint16_t v, uint16_t* p) {
+uint16_t ghc___aarch64_ldset2_sync(uint16_t v, _Atomic uint16_t* p);
+uint16_t ghc___aarch64_ldset2_sync(uint16_t v, _Atomic uint16_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_seq_cst);
 }
 
-uint32_t ghc___aarch64_ldset4_relax(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldset4_relax(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldset4_relax(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldset4_relax(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_relaxed);
 }
 
-uint32_t ghc___aarch64_ldset4_acq(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldset4_acq(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldset4_acq(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldset4_acq(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acquire);
 }
 
-uint32_t ghc___aarch64_ldset4_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldset4_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldset4_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldset4_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_release);
 }
 
-uint32_t ghc___aarch64_ldset4_acq_rel(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldset4_acq_rel(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldset4_acq_rel(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldset4_acq_rel(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acq_rel);
 }
 
-uint32_t ghc___aarch64_ldset4_sync(uint32_t v, uint32_t* p);
-uint32_t ghc___aarch64_ldset4_sync(uint32_t v, uint32_t* p) {
+uint32_t ghc___aarch64_ldset4_sync(uint32_t v, _Atomic uint32_t* p);
+uint32_t ghc___aarch64_ldset4_sync(uint32_t v, _Atomic uint32_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_seq_cst);
 }
 
-uint64_t ghc___aarch64_ldset8_relax(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldset8_relax(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldset8_relax(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldset8_relax(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_relaxed);
 }
 
-uint64_t ghc___aarch64_ldset8_acq(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldset8_acq(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldset8_acq(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldset8_acq(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acquire);
 }
 
-uint64_t ghc___aarch64_ldset8_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldset8_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldset8_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldset8_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_release);
 }
 
-uint64_t ghc___aarch64_ldset8_acq_rel(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldset8_acq_rel(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldset8_acq_rel(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldset8_acq_rel(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_acq_rel);
 }
 
-uint64_t ghc___aarch64_ldset8_sync(uint64_t v, uint64_t* p);
-uint64_t ghc___aarch64_ldset8_sync(uint64_t v, uint64_t* p) {
+uint64_t ghc___aarch64_ldset8_sync(uint64_t v, _Atomic uint64_t* p);
+uint64_t ghc___aarch64_ldset8_sync(uint64_t v, _Atomic uint64_t* p) {
   return atomic_fetch_or_explicit(p, v, memory_order_seq_cst);
 }
 
