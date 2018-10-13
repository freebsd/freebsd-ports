https://github.com/mesonbuild/meson/pull/4324

From 068f0b3bc7becab6762ada45ecdd5dc601ee2473 Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Thu, 4 Oct 2018 23:03:30 +0800
Subject: [PATCH] backends: Use raw_link_args to check for the need of RPATH

Function rpaths_for_bundled_shared_libraries assumes it needs RPATH when
linking arguments of an external dependency has exactly one argument and
the only argument is an absolute path to a library file. This was mostly
fine because almost all .pc files use a -L -l pair instead of the full
path of the library, which means pkg-config dependencies almost always
have at least two arguments. However, there are patches landed in the
meson 0.47 cycle which convert -L -l pair returned by pkg-config to the
absolute path of library. If the output of pkg-config includes exactly
one -L argument and one -l argument, it will be converted to exactly one
absolute path by meson and rpaths_for_bundled_shared_libraries will
assume it needs RPATH. Since meson passes both -rpath and -rpath-link to
the linker and -rpath-link has precedence over LD_LIBRARY_PATH, it
changes the search order of dependent libraries in an unexpected way and
it causes a lot of linking troubles in JHBuild environments on FreeBSD.

To make the method behave like the old way of using -L -l pairs and
avoid library path order problems, we use raw_link_args instead of
link_args here. raw_link_args stores the unmodified output of pkg-config
and it is much less likely to accidentally match the rule currently used
by the method.

Works around https://github.com/mesonbuild/meson/issues/4270.
--- mesonbuild/backend/backends.py.orig	2018-09-22 13:22:03 UTC
+++ mesonbuild/backend/backends.py
@@ -371,7 +371,7 @@ class Backend:
         for dep in target.external_deps:
             if not isinstance(dep, (dependencies.ExternalLibrary, dependencies.PkgConfigDependency)):
                 continue
-            la = dep.link_args
+            la = dep.get_link_args(raw=True)
             if len(la) != 1 or not os.path.isabs(la[0]):
                 continue
             # The only link argument is an absolute path to a library file.
