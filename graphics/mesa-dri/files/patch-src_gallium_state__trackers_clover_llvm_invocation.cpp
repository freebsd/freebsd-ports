# fix errors like the following
#
# llvm/invocation.cpp:(.text+0x1275): undefined reference to `std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::c_str()
 const'
# /usr/bin/ld: ../../../../src/gallium/state_trackers/clover/.libs/libclover.a(libclllvm_la-invocation.o): relocation R_X86_64_PC32 against `_ZNKSt3__112bas
ic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5c_strEv' can not be used when making a shared object; recompile with -fPIC
# /usr/bin/ld: final link failed: Bad value
#
--- src/gallium/state_trackers/clover/llvm/invocation.cpp.orig	2017-04-01 15:33:37 UTC
+++ src/gallium/state_trackers/clover/llvm/invocation.cpp
@@ -93,6 +93,8 @@ namespace {
       return ctx;
    }
 
+   const char* cstr(const std::string& str) { return str.c_str(); }
+
    std::unique_ptr<clang::CompilerInstance>
    create_compiler_instance(const target &target,
                             const std::vector<std::string> &opts,
@@ -105,8 +107,8 @@ namespace {
       // Parse the compiler options.  A file name should be present at the end
       // and must have the .cl extension in order for the CompilerInvocation
       // class to recognize it as an OpenCL source file.
-      const std::vector<const char *> copts =
-         map(std::mem_fn(&std::string::c_str), opts);
+      std::vector<const char *> copts(opts.size());
+      std::transform(opts.begin(), opts.end(), copts.begin(), cstr);
 
       if (!clang::CompilerInvocation::CreateFromArgs(
              c->getInvocation(), copts.data(), copts.data() + copts.size(), diag))
