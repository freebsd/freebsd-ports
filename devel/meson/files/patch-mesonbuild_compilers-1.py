From b8ef693a2af7463be0cfa3cc752decd4c4955587 Mon Sep 17 00:00:00 2001
From: Nirbheek Chauhan <nirbheek@centricular.com>
Date: Sat, 29 Oct 2016 12:38:36 +0530
Subject: [PATCH] Clang also supports gnu89/99/11, gnu++03/11/14/1z

The list of supported standards is identical for GCC and Clang.

We don't list duplicate standard names however, such as c++03 and c++09

https://github.com/llvm-mirror/clang/blob/master/include/clang/Frontend/LangStandards.def
--- mesonbuild/compilers.py.orig	2016-10-17 17:38:14 UTC
+++ mesonbuild/compilers.py
@@ -1968,7 +1968,8 @@ class GnuCCompiler(GnuCompiler, CCompile
 
     def get_options(self):
         opts = {'c_std' : coredata.UserComboOption('c_std', 'C language standard to use',
-                                                   ['none', 'c89', 'c99', 'c11', 'gnu89', 'gnu99', 'gnu11'],
+                                                   ['none', 'c89', 'c99', 'c11',
+                                                    'gnu89', 'gnu99', 'gnu11'],
                                                    'none')}
         if self.gcc_type == GCC_MINGW:
             opts.update({
@@ -2097,7 +2098,8 @@ class ClangCCompiler(ClangCompiler, CCom
 
     def get_options(self):
         return {'c_std' : coredata.UserComboOption('c_std', 'C language standard to use',
-                                                   ['none', 'c89', 'c99', 'c11'],
+                                                   ['none', 'c89', 'c99', 'c11',
+                                                    'gnu89', 'gnu99', 'gnu11',],
                                                    'none')}
 
     def get_option_compile_args(self, options):
@@ -2124,8 +2126,9 @@ class ClangCPPCompiler(ClangCompiler,   
 
     def get_options(self):
         return {'cpp_std' : coredata.UserComboOption('cpp_std', 'C++ language standard to use',
-                                                   ['none', 'c++03', 'c++11', 'c++14', 'c++1z'],
-                                                   'none')}
+                                                     ['none', 'c++03', 'c++11', 'c++14', 'c++1z',
+                                                      'gnu++03', 'gnu++11', 'gnu++14', 'gnu++1z'],
+                                                     'none')}
 
     def get_option_compile_args(self, options):
         args = []
