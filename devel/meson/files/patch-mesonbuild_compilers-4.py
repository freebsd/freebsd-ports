From f144e50f5ca65ba67c23ff262a79c35a2c444006 Mon Sep 17 00:00:00 2001
From: Nirbheek Chauhan <nirbheek@centricular.com>
Date: Tue, 8 Nov 2016 16:22:40 +0530
Subject: [PATCH] has_function: Cast to void* instead of int

Clang++ doesn't allow that, but void* will always be allowed because
lots of projects depend on that.

error: cast from pointer to smaller type 'int' loses information
--- mesonbuild/compilers.py.orig	2016-11-09 17:42:03 UTC
+++ mesonbuild/compilers.py
@@ -935,7 +935,7 @@ int main(int argc, char **argv) {
         head = '#include <limits.h>\n{0}\n'
         # We don't know what the function takes or returns, so try to use it as
         # a function pointer
-        main = '\nint main() {{ int a = (int) &{1}; }}'
+        main = '\nint main() {{ void *a = (void*) &{1}; }}'
         return head, main
 
     def has_function(self, funcname, prefix, env, extra_args=None, dependencies=None):
