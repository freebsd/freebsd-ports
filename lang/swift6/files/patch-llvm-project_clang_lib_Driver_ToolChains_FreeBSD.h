--- llvm-project/clang/lib/Driver/ToolChains/FreeBSD.h.orig	2025-12-02 17:06:04 UTC
+++ llvm-project/clang/lib/Driver/ToolChains/FreeBSD.h
@@ -86,6 +86,7 @@ class LLVM_LIBRARY_VISIBILITY FreeBSD : public Generic
   // Until dtrace (via CTF) and LLDB can deal with distributed debug info,
   // FreeBSD defaults to standalone/full debug info.
   bool GetDefaultStandaloneDebug() const override { return true; }
+  const char *getDefaultLinker() const override { return "lld"; }  
 
 protected:
   Tool *buildAssembler() const override;
