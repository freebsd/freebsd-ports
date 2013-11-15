
$FreeBSD$

--- tools/clang/lib/Driver/ToolChains.h.orig
+++ tools/clang/lib/Driver/ToolChains.h
@@ -463,9 +463,14 @@
 public:
   FreeBSD(const Driver &D, const llvm::Triple& Triple, const ArgList &Args);
 
+  virtual CXXStdlibType GetCXXStdlibType(const ArgList &Args) const;
+
   virtual bool IsMathErrnoDefault() const { return false; }
   virtual bool IsObjCNonFragileABIDefault() const { return true; }
 
+  virtual void AddClangCXXStdlibIncludeArgs(const ArgList &DriverArgs,
+                                            ArgStringList &CC1Args) const;
+
   virtual Tool &SelectTool(const Compilation &C, const JobAction &JA,
                            const ActionList &Inputs) const;
 };
