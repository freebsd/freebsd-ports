--- src/llvm-project/llvm/utils/llvm-build/llvmbuild/main.py.orig	2019-09-20 16:14:30 UTC
+++ src/llvm-project/llvm/utils/llvm-build/llvmbuild/main.py
@@ -657,6 +657,8 @@ def add_magic_target_components(parser, project, opts)
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
     native_target_name = { 'x86' : 'X86',
+                           'i386' : 'X86',
+                           'amd64' : 'X86',
                            'x86_64' : 'X86',
                            'Unknown' : None }.get(opts.native_target,
                                                   opts.native_target)
