https://github.com/mesonbuild/meson/pull/3463

From 894457199672413466771da6fd9b6988c29c8557 Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Sun, 22 Apr 2018 22:38:18 +0800
Subject: [PATCH] gnome: Distinguish between internal and external linker flags

When an older version of the library being built is installed in the
same prefix as external dependencies, we have to be careful to construct
the linker or compiler command line. If a -L flag from external
dependencoes comes before a -L flag pointing to builddir, it is possible
for the linker to load older libraries from the installation prefix
instead of the newly built ones, which is likely to cause undefined
reference error.

Since the order of dependencies is not significant, we cannot expect
internal dependencies to appear before external dependencies when
recursively iterating the list of dependencies. To make it harder to
make mistakes, linker flags come from internal and external
dependencies are now stored in different order sets. Code using
_get_dependencies_flags are expected to follow the order when
constructing linker command line:

  1. Internal linker flags
  2. LDFLAGS set by users
  3. External linker flags

It is similar to what automake and libtool do for autotools projects.
---
 mesonbuild/modules/gnome.py | 61 +++++++++++++++++++++++++++------------------
 1 file changed, 37 insertions(+), 24 deletions(-)

diff --git a/mesonbuild/modules/gnome.py b/mesonbuild/modules/gnome.py
index abefe0579..5629ad169 100644
--- mesonbuild/modules/gnome.py
+++ mesonbuild/modules/gnome.py
@@ -316,7 +316,8 @@ def _get_link_args(self, state, lib, depends=None, include_rpath=False,
     def _get_dependencies_flags(self, deps, state, depends=None, include_rpath=False,
                                 use_gir_args=False):
         cflags = OrderedSet()
-        ldflags = OrderedSet()
+        internal_ldflags = OrderedSet()
+        external_ldflags = OrderedSet()
         gi_includes = OrderedSet()
         deps = mesonlib.listify(deps, unholder=True)
 
@@ -326,17 +327,19 @@ def _get_dependencies_flags(self, deps, state, depends=None, include_rpath=False
                 for lib in dep.libraries:
                     if hasattr(lib, 'held_object'):
                         lib = lib.held_object
-                    ldflags.update(self._get_link_args(state, lib, depends, include_rpath))
+                    internal_ldflags.update(self._get_link_args(state, lib, depends, include_rpath))
                     libdepflags = self._get_dependencies_flags(lib.get_external_deps(), state, depends, include_rpath,
                                                                use_gir_args)
                     cflags.update(libdepflags[0])
-                    ldflags.update(libdepflags[1])
-                    gi_includes.update(libdepflags[2])
+                    internal_ldflags.update(libdepflags[1])
+                    external_ldflags.update(libdepflags[2])
+                    gi_includes.update(libdepflags[3])
                 extdepflags = self._get_dependencies_flags(dep.ext_deps, state, depends, include_rpath,
                                                            use_gir_args)
                 cflags.update(extdepflags[0])
-                ldflags.update(extdepflags[1])
-                gi_includes.update(extdepflags[2])
+                internal_ldflags.update(extdepflags[1])
+                external_ldflags.update(extdepflags[2])
+                gi_includes.update(extdepflags[3])
                 for source in dep.sources:
                     if hasattr(source, 'held_object'):
                         source = source.held_object
@@ -351,9 +354,9 @@ def _get_dependencies_flags(self, deps, state, depends=None, include_rpath=False
                             # For PkgConfigDependency only:
                             getattr(dep, 'is_libtool', False)):
                         lib_dir = os.path.dirname(lib)
-                        ldflags.update(["-L%s" % lib_dir])
+                        external_ldflags.update(["-L%s" % lib_dir])
                         if include_rpath:
-                            ldflags.update(['-Wl,-rpath {}'.format(lib_dir)])
+                            external_ldflags.update(['-Wl,-rpath {}'.format(lib_dir)])
                         libname = os.path.basename(lib)
                         if libname.startswith("lib"):
                             libname = libname[3:]
@@ -362,7 +365,7 @@ def _get_dependencies_flags(self, deps, state, depends=None, include_rpath=False
                     # Hack to avoid passing some compiler options in
                     if lib.startswith("-W"):
                         continue
-                    ldflags.update([lib])
+                    external_ldflags.update([lib])
 
                 if isinstance(dep, PkgConfigDependency):
                     girdir = dep.get_pkgconfig_variable("girdir", {'default': ''})
@@ -375,14 +378,17 @@ def _get_dependencies_flags(self, deps, state, depends=None, include_rpath=False
                 continue
 
         if gir_has_extra_lib_arg(self.interpreter) and use_gir_args:
-            fixed_ldflags = OrderedSet()
-            for ldflag in ldflags:
-                if ldflag.startswith("-l"):
-                    fixed_ldflags.add(ldflag.replace('-l', '--extra-library=', 1))
-                else:
-                    fixed_ldflags.add(ldflag)
-            ldflags = fixed_ldflags
-        return cflags, ldflags, gi_includes
+            def fix_ldflags(ldflags):
+                fixed_ldflags = OrderedSet()
+                for ldflag in ldflags:
+                    if ldflag.startswith("-l"):
+                        fixed_ldflags.add(ldflag.replace('-l', '--extra-library=', 1))
+                    else:
+                        fixed_ldflags.add(ldflag)
+                return fixed_ldflags
+            internal_ldflags = fix_ldflags(internal_ldflags)
+            external_ldflags = fix_ldflags(external_ldflags)
+        return cflags, internal_ldflags, external_ldflags, gi_includes
 
     @permittedKwargs({'sources', 'nsversion', 'namespace', 'symbol_prefix', 'identifier_prefix',
                       'export_packages', 'includes', 'dependencies', 'link_with', 'include_directories',
@@ -484,7 +490,8 @@ def generate_gir(self, state, args, kwargs):
                         'Gir includes must be str, GirTarget, or list of them')
 
         cflags = []
-        ldflags = []
+        internal_ldflags = []
+        external_ldflags = []
         for lang, compiler in girtarget.compilers.items():
             # XXX: Can you use g-i with any other language?
             if lang in ('c', 'cpp', 'objc', 'objcpp', 'd'):
@@ -501,7 +508,7 @@ def generate_gir(self, state, args, kwargs):
                 sanitize = state.environment.coredata.base_options['b_sanitize'].value
                 cflags += compilers.sanitizer_compile_args(sanitize)
                 if 'address' in sanitize.split(','):
-                    ldflags += ['-lasan']
+                    external_ldflags += ['-lasan']
                 # FIXME: Linking directly to libasan is not recommended but g-ir-scanner
                 # does not understand -f LDFLAGS. https://bugzilla.gnome.org/show_bug.cgi?id=783892
                 # ldflags += compilers.sanitizer_link_args(sanitize)
@@ -562,10 +569,11 @@ def generate_gir(self, state, args, kwargs):
         # ldflags will be misinterpreted by gir scanner (showing
         # spurious dependencies) but building GStreamer fails if they
         # are not used here.
-        dep_cflags, dep_ldflags, gi_includes = self._get_dependencies_flags(deps, state, depends,
-                                                                            use_gir_args=True)
+        dep_cflags, dep_internal_ldflags, dep_external_ldflags, gi_includes = \
+            self._get_dependencies_flags(deps, state, depends, use_gir_args=True)
         cflags += list(dep_cflags)
-        ldflags += list(dep_ldflags)
+        internal_ldflags += list(dep_internal_ldflags)
+        external_ldflags += list(dep_external_ldflags)
         scan_command += ['--cflags-begin']
         scan_command += cflags
         scan_command += state.environment.coredata.external_args[lang]
@@ -575,7 +583,7 @@ def generate_gir(self, state, args, kwargs):
         # ones.
         if isinstance(girtarget, build.SharedLibrary):
             scan_command += ["-L@PRIVATE_OUTDIR_ABS_%s@" % girtarget.get_id()]
-        scan_command += list(ldflags)
+        scan_command += list(internal_ldflags)
         for i in gi_includes:
             scan_command += ['--add-include-path=%s' % i]
 
@@ -603,6 +611,7 @@ def generate_gir(self, state, args, kwargs):
         for link_arg in state.environment.coredata.external_link_args[lang]:
             if link_arg.startswith('-L'):
                 scan_command.append(link_arg)
+        scan_command += list(external_ldflags)
 
         scankwargs = {'output': girfile,
                       'command': scan_command,
@@ -825,7 +834,8 @@ def gtkdoc(self, state, args, kwargs):
     def _get_build_args(self, kwargs, state):
         args = []
         deps = extract_as_list(kwargs, 'dependencies', unholder=True)
-        cflags, ldflags, gi_includes = self._get_dependencies_flags(deps, state, include_rpath=True)
+        cflags, internal_ldflags, external_ldflags, gi_includes = \
+            self._get_dependencies_flags(deps, state, include_rpath=True)
         inc_dirs = mesonlib.extract_as_list(kwargs, 'include_directories')
         for incd in inc_dirs:
             if not isinstance(incd.held_object, (str, build.IncludeDirs)):
@@ -833,7 +843,10 @@ def _get_build_args(self, kwargs, state):
                     'Gir include dirs should be include_directories().')
         cflags.update(get_include_args(inc_dirs))
         cflags.update(state.environment.coredata.external_args['c'])
+        ldflags = OrderedSet()
+        ldflags.update(internal_ldflags)
         ldflags.update(state.environment.coredata.external_link_args['c'])
+        ldflags.update(external_ldflags)
         if cflags:
             args += ['--cflags=%s' % ' '.join(cflags)]
         if ldflags:
