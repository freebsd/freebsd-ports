--- utils/llvm-build/llvmbuild/main.py.orig
+++ utils/llvm-build/llvmbuild/main.py
@@ -718,7 +718,18 @@
 
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
-    native_target_name = { 'x86' : 'X86',
+    native_target_name = { 'aarch64' : 'AArch64',
+			   'amd64' : 'X86',
+			   'arm' : 'ARM',
+			   'armeb' : 'ARM',
+			   'armv6' : 'ARM',
+			   'armv6hf' : 'ARM',
+			   'i386' : 'X86',
+			   'mips' : 'Mips',
+			   'powerpc' : 'PowerPC',
+			   'powerpc64' : 'PowerPC',
+			   'sparc64' : 'Sparc',
+                           'x86' : 'X86',
                            'x86_64' : 'X86',
                            'Unknown' : None }.get(opts.native_target,
                                                   opts.native_target)
