--- common.gypi.orig	2020-05-09 05:51:01 UTC
+++ common.gypi
@@ -455,15 +455,6 @@
         'libraries': [ '-lelf' ],
       }],
       ['OS=="freebsd"', {
-        'conditions': [
-          ['"0" < llvm_version < "4.0"', {
-            # Use this flag because on FreeBSD std::pairs copy constructor is non-trivial.
-            # Doesn't apply to llvm 4.0 (FreeBSD 11.1) or later.
-            # Refs: https://lists.freebsd.org/pipermail/freebsd-toolchain/2016-March/002094.html
-            # Refs: https://svnweb.freebsd.org/ports/head/www/node/Makefile?revision=444555&view=markup
-            'cflags': [ '-D_LIBCPP_TRIVIAL_PAIR_COPY_CTOR=1' ],
-          }],
-        ],
         'ldflags': [
           '-Wl,--export-dynamic',
         ],
