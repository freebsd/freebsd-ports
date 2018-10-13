https://github.com/mesonbuild/meson/pull/4325

From 158d627c141859e28bbca2c2126b5306608aac6e Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Thu, 4 Oct 2018 23:30:28 +0800
Subject: [PATCH] PkgConfigDependency: Sort -L flags according to
 PKG_CONFIG_PATH

When there is more than one path in PKG_CONFIG_PATH. It is almost always
preferred to find things in the order specified by PKG_CONFIG_PATH
instead of assuming pkg-config returns flags in a meaningful order.

For example:

/usr/local/lib/libgtk-3.so.0
/usr/local/lib/pkgconfig/gtk+-3.0.pc
/usr/local/lib/libcanberra-gtk3.so
/usr/local/lib/pkgconfig/libcanberra-gtk3.pc
/home/mesonuser/.local/lib/libgtk-3.so.0
/home/mesonuser/.local/lib/pkgconfig/gtk+-3.0.pc

PKG_CONFIG_PATH="/home/mesonuser/.local/lib/pkgconfig:/usr/local/lib/pkgconfig"

libcanberra-gtk3 is a library which depends on gtk+-3.0. The dependency
is mentioned in the .pc file with 'Requires', so flags from gtk+-3.0 are
used in both dynamic and static linking.

Assume the user wants to compile an application which needs both
libcanberra-gtk3 and gtk+-3.0. The application depends on features added
in the latest version of gtk+-3.0, which can be found in the home
directory of the user but not in /usr/local. When meson asks pkg-config
for linker flags of libcanberra-gtk3, pkg-config picks
/usr/local/lib/pkgconfig/libcanberra-gtk3.pc and
/home/mesonuser/.local/lib/pkgconfig/gtk+-3.0.pc. Since these two
libraries come from different prefixes, there will be two -L arguments
in the output of pkg-config. If -L/usr/local/lib is put before
-L/home/mesonuser/.local/lib, meson will find both libraries in
/usr/local/lib instead of picking libgtk-3.so.0 from the home directory.

This can result in linking failure such as undefined references error
when meson decides to put linker arguments of libcanberra-gtk3 before
linker arguments of gtk+-3.0. When both /usr/local/lib/libgtk-3.so.0 and
/home/mesonuser/.local/lib/libgtk-3.so.0 are present on the command
line, the linker chooses the first one and ignores the second one. If
the application needs new symbols that are only available in the second
one, the linker will throw an error because of missing symbols.

To resolve the issue, we should reorder -L flags according to
PKG_CONFIG_PATH ourselves before using it to find the full path of
library files. This makes sure that we always follow the preferences of
users, without depending on the unreliable part of pkg-config output.

Fixes https://github.com/mesonbuild/meson/issues/4271.
--- mesonbuild/dependencies/base.py.orig	2018-09-22 13:22:03 UTC
+++ mesonbuild/dependencies/base.py
@@ -604,6 +604,21 @@ class PkgConfigDependency(ExternalDepend
                                       (self.name, out))
         self.compile_args = self._convert_mingw_paths(shlex.split(out))
 
+    def _sort_libpaths(self, libpaths, refpaths):
+        if len(refpaths) == 0:
+            return list(libpaths)
+
+        def key_func(libpath):
+            common_lengths = []
+            for refpath in refpaths:
+                common_path = os.path.commonpath([libpath, refpath])
+                common_lengths.append(len(common_path))
+            max_length = max(common_lengths)
+            max_index = common_lengths.index(max_length)
+            reversed_max_length = len(refpaths[max_index]) - max_length
+            return (max_index, reversed_max_length)
+        return sorted(libpaths, key=key_func)
+
     def _search_libs(self, out, out_raw):
         '''
         @out: PKG_CONFIG_ALLOW_SYSTEM_LIBS=1 pkg-config --libs
@@ -635,6 +650,22 @@ class PkgConfigDependency(ExternalDepend
         for arg in raw_link_args:
             if arg.startswith('-L') and not arg.startswith(('-L-l', '-L-L')):
                 prefix_libpaths.add(arg[2:])
+        # Library paths are not always ordered in a meaningful way
+        #
+        # Instead of relying on pkg-config or pkgconf to provide -L flags in a
+        # specific order, we reorder library paths ourselves, according to th
+        # order specified in PKG_CONFIG_PATH. See:
+        # https://github.com/mesonbuild/meson/issues/4271
+        #
+        # Only prefix_libpaths are reordered here because there should not be
+        # too many system_libpaths to cause library version issues.
+        pkg_config_path = os.environ.get('PKG_CONFIG_PATH')
+        if pkg_config_path:
+            pkg_config_path = pkg_config_path.split(os.pathsep)
+        else:
+            pkg_config_path = []
+        pkg_config_path = self._convert_mingw_paths(pkg_config_path)
+        prefix_libpaths = self._sort_libpaths(prefix_libpaths, pkg_config_path)
         system_libpaths = OrderedSet()
         full_args = self._convert_mingw_paths(shlex.split(out))
         for arg in full_args:
