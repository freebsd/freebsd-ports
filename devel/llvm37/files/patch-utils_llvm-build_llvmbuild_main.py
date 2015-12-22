--- utils/llvm-build/llvmbuild/main.py.orig	2014-11-19 04:34:20.000000000 +0100
+++ utils/llvm-build/llvmbuild/main.py	2015-12-21 11:15:34.356019000 +0100
@@ -393,6 +393,8 @@ subdirectories = %s
 //
 //===----------------------------------------------------------------------===//
 
+#include "llvm/Config/config.h"
+
 """)
         f.write('struct AvailableComponent {\n')
         f.write('  /// The name of the component.\n')
@@ -413,7 +415,7 @@ subdirectories = %s
             if library_name is None:
                 library_name_as_cstr = '0'
             else:
-                library_name_as_cstr = '"lib%s.a"' % library_name
+                library_name_as_cstr = '"lib%s" LTDL_SHLIB_EXT' % library_name
             f.write('  { "%s", %s, %d, { %s } },\n' % (
                 name, library_name_as_cstr, is_installed,
                 ', '.join('"%s"' % dep
@@ -718,7 +720,17 @@ def add_magic_target_components(parser, 
 
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
-    native_target_name = { 'x86' : 'X86',
+    native_target_name = { 'amd64' : 'X86',
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
