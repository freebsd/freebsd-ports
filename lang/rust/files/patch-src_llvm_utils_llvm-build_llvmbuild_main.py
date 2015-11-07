--- src/llvm/utils/llvm-build/llvmbuild/main.py.orig	2015-10-28 01:10:50 UTC
+++ src/llvm/utils/llvm-build/llvmbuild/main.py
@@ -719,6 +719,8 @@ def add_magic_target_components(parser, 
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
     native_target_name = { 'x86' : 'X86',
+                           'i386' : 'X86',
+                           'amd64' : 'X86',
                            'x86_64' : 'X86',
                            'Unknown' : None }.get(opts.native_target,
                                                   opts.native_target)
