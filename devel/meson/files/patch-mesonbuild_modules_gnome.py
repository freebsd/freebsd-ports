https://github.com/mesonbuild/meson/pull/4348

From ca946665fe824c2010a96f659cff3ae21cecd910 Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Mon, 8 Oct 2018 23:44:33 +0800
Subject: [PATCH] gnome: Quote arguments passed to gtkdoc-scangobj

It is possible for compiler flags to include special characters, such as
double quotes which are needed to define macros with -D options. Since
gtkdoc-scangobj uses shlex.split to split arguments passed to --cc,
--ld, --cflags, --ldflags into lists, we can safely use shlex.quote to
properly quote arguments for these options.
--- mesonbuild/modules/gnome.py.orig	2018-09-22 13:22:03 UTC
+++ mesonbuild/modules/gnome.py
@@ -17,6 +17,7 @@ functionality such as gobject-introspect
 
 import os
 import copy
+import shlex
 import subprocess
 
 from .. import build
@@ -1014,12 +1015,12 @@ This will become a hard error in the fut
             compiler = state.environment.coredata.compilers.get('c')
 
         if compiler:
-            args += ['--cc=%s' % ' '.join(compiler.get_exelist())]
-            args += ['--ld=%s' % ' '.join(compiler.get_linker_exelist())]
+            args += ['--cc=%s' % ' '.join([shlex.quote(x) for x in compiler.get_exelist()])]
+            args += ['--ld=%s' % ' '.join([shlex.quote(x) for x in compiler.get_linker_exelist()])]
         if cflags:
-            args += ['--cflags=%s' % ' '.join(cflags)]
+            args += ['--cflags=%s' % ' '.join([shlex.quote(x) for x in cflags])]
         if ldflags:
-            args += ['--ldflags=%s' % ' '.join(ldflags)]
+            args += ['--ldflags=%s' % ' '.join([shlex.quote(x) for x in ldflags])]
 
         return args
 
