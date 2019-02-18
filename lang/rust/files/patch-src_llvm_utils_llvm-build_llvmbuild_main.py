--- src/llvm/utils/llvm-build/llvmbuild/main.py.orig	2018-12-13 15:33:50 UTC
+++ src/llvm/utils/llvm-build/llvmbuild/main.py
@@ -659,6 +659,8 @@ def add_magic_target_components(parser, project, opts)
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
     native_target_name = { 'x86' : 'X86',
+                           'i386' : 'X86',
+                           'amd64' : 'X86',
                            'x86_64' : 'X86',
                            'Unknown' : None }.get(opts.native_target,
                                                   opts.native_target)
