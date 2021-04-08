From c24a0f852489124fa002bdc90b5753547899b1cb Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Krzysztof=20Ma=C5=82ysa?= <varqox@gmail.com>
Date: Tue, 16 Feb 2021 18:46:06 +0100
Subject: [PATCH] compilers: clang: Drop -Xclang before -fcolor-diagnostics
 flag

Using -Xclang -fcolor-diagnostics provides no advantage to using just -fcolor-diagnostics option and sometimes causes problems:
* uncolored diagnostics on Arch Linux: https://bugs.archlinux.org/task/69662
* simple problem with removing flag -fcolor-diagnostics:  https://github.com/clangd/clangd/issues/279
--- mesonbuild/compilers/mixins/clang.py.orig	2021-02-20 13:17:16 UTC
+++ mesonbuild/compilers/mixins/clang.py
@@ -29,9 +29,9 @@ if T.TYPE_CHECKING:
     from ...dependencies import Dependency  # noqa: F401
 
 clang_color_args = {
-    'auto': ['-Xclang', '-fcolor-diagnostics'],
-    'always': ['-Xclang', '-fcolor-diagnostics'],
-    'never': ['-Xclang', '-fno-color-diagnostics'],
+    'auto': ['-fcolor-diagnostics'],
+    'always': ['-fcolor-diagnostics'],
+    'never': ['-fno-color-diagnostics'],
 }  # type: T.Dict[str, T.List[str]]
 
 clang_optimization_args = {
