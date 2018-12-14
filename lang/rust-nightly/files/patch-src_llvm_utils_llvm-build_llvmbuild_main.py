--- src/llvm/utils/llvm-build/llvmbuild/main.py.orig	2018-04-04 08:39:57 UTC
+++ src/llvm/utils/llvm-build/llvmbuild/main.py
@@ -752,6 +752,8 @@ def add_magic_target_components(parser, project, opts)
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
     native_target_name = { 'x86' : 'X86',
+                           'i386' : 'X86',
+                           'amd64' : 'X86',
                            'x86_64' : 'X86',
                            'Unknown' : None }.get(opts.native_target,
                                                   opts.native_target)
