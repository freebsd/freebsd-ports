From 4be8e71fb380a0541b69992539a0695ea29b3205 Mon Sep 17 00:00:00 2001
From: Nirbheek Chauhan <nirbheek@centricular.com>
Date: Tue, 25 Oct 2016 08:01:21 +0530
Subject: [PATCH] has_function: Try to use the function being checked

Simply placing a reference to it isn't enough for the linker to try and
think it's being used and do a symbol availability check with
-Wl,-no_weak_imports on OS X ld.
--- mesonbuild/compilers.py.orig	2016-11-09 17:43:55 UTC
+++ mesonbuild/compilers.py
@@ -933,9 +933,9 @@ int main(int argc, char **argv) {
         """
         # Add the 'prefix', aka defines, includes, etc that the user provides
         head = '#include <limits.h>\n{0}\n'
-        # We don't know what the function takes or returns, so just add
-        # a useless reference to it
-        main = '\nint main() {{ {1}; }}'
+        # We don't know what the function takes or returns, so try to use it as
+        # a function pointer
+        main = '\nint main() {{ int a = (int) &{1}; }}'
         return head, main
 
     def has_function(self, funcname, prefix, env, extra_args=None, dependencies=None):
