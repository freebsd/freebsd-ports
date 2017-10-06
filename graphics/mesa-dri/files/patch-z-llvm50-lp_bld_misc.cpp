From 0c67aa84568d4676017d0d309e5ba8832d3b9e1e Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Michel=20D=C3=A4nzer?= <michel.daenzer@amd.com>
Date: Wed, 10 May 2017 17:26:07 +0900
Subject: gallivm: Fix build against LLVM SVN >= r302589
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

deregisterEHFrames doesn't take any parameters anymore.

Reviewed-by: Vedran Miletić <vedran@miletic.net>
Reviewed-by: Marek Olšák <marek.olsak@amd.com>

diff --git a/src/gallium/auxiliary/gallivm/lp_bld_misc.cpp b/src/gallium/auxiliary/gallivm/lp_bld_misc.cpp
index 2a388cb..0e4a531 100644
--- src/gallium/auxiliary/gallivm/lp_bld_misc.cpp
+++ src/gallium/auxiliary/gallivm/lp_bld_misc.cpp
@@ -342,14 +342,20 @@ class DelegatingJITMemoryManager : public BaseMemoryManager {
       virtual void registerEHFrames(uint8_t *Addr, uint64_t LoadAddr, size_t Size) {
          mgr()->registerEHFrames(Addr, LoadAddr, Size);
       }
-      virtual void deregisterEHFrames(uint8_t *Addr, uint64_t LoadAddr, size_t Size) {
-         mgr()->deregisterEHFrames(Addr, LoadAddr, Size);
-      }
 #else
       virtual void registerEHFrames(llvm::StringRef SectionData) {
          mgr()->registerEHFrames(SectionData);
       }
 #endif
+#if HAVE_LLVM >= 0x0500
+      virtual void deregisterEHFrames() {
+         mgr()->deregisterEHFrames();
+      }
+#elif HAVE_LLVM >= 0x0304
+      virtual void deregisterEHFrames(uint8_t *Addr, uint64_t LoadAddr, size_t Size) {
+         mgr()->deregisterEHFrames(Addr, LoadAddr, Size);
+      }
+#endif
       virtual void *getPointerToNamedFunction(const std::string &Name,
                                               bool AbortOnFailure=true) {
          return mgr()->getPointerToNamedFunction(Name, AbortOnFailure);
-- 
cgit v0.10.2

