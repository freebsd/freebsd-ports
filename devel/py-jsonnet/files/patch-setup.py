--- setup.py.orig	2025-05-07 12:28:56 UTC
+++ setup.py
@@ -21,18 +21,6 @@ LIB_SOURCES = [
 # NOTE: If you are editing the array below then you probably also need
 # to change MANIFEST.in.
 LIB_SOURCES = [
-    "core/desugarer.cpp",
-    "core/formatter.cpp",
-    "core/libjsonnet.cpp",
-    "core/lexer.cpp",
-    "core/parser.cpp",
-    "core/pass.cpp",
-    "core/path_utils.cpp",
-    "core/static_analysis.cpp",
-    "core/string_utils.cpp",
-    "core/vm.cpp",
-    "third_party/md5/md5.cpp",
-    "third_party/rapidyaml/rapidyaml.cpp",
     "python/_jsonnet.c",
 ]
 
@@ -54,50 +42,7 @@ def get_version():
     )
 
 
-class BuildJsonnetExt(BuildExt):
-    def _pack_std_jsonnet(self):
-        print("generating core/std.jsonnet.h from stdlib/std.jsonnet")
-        with open("stdlib/std.jsonnet", "rb") as f:
-            stdlib = f.read()
-        with open("core/std.jsonnet.h", "w", encoding="utf-8") as f:
-            f.write(",".join(str(x) for x in stdlib))
-            f.write(",0\n\n")
 
-    def build_extensions(self):
-        # At this point, the compiler has been chosen so we add compiler-specific flags.
-        # There is unfortunately no built in support for this in setuptools.
-        # Feature request: https://github.com/pypa/setuptools/issues/1819
-        print("Adjusting compiler for compiler type " + self.compiler.compiler_type)
-        # This is quite hacky as we're modifying the Extension object itself.
-        if self.compiler.compiler_type == "msvc":
-            for ext in self.extensions:
-                ext.extra_compile_args.append("/std:c++17")
-        else:
-            # -std=c++17 should only be applied to C++ build,
-            # not when compiling C source code. Unfortunately,
-            # the extra_compile_args applies to both. Instead,
-            # patch the CC/CXX commands in the compiler object.
-            #
-            # Note that older versions of distutils/setuptools do not
-            # have the necessary separation between C and C++ compilers.
-            # This requires setuptools 72.2.
-            for v in ("compiler_cxx", "compiler_so_cxx"):
-                if not hasattr(self.compiler, v):
-                    print(
-                        f"WARNING: cannot adjust flag {v}, "
-                        f"compiler type {self.compiler.compiler_type}, "
-                        f"compiler class {type(self.compiler).__name__}"
-                    )
-                    continue
-                current = getattr(self.compiler, v)
-                self.compiler.set_executable(v, current + ["-std=c++17"])
-        super().build_extensions()
-
-    def run(self):
-        self._pack_std_jsonnet()
-        super().run()
-
-
 setuptools.setup(
     name="jsonnet",
     url="https://jsonnet.org",
@@ -109,19 +54,11 @@ setuptools.setup(
     author="David Cunningham",
     author_email="dcunnin@google.com",
     version=get_version(),
-    cmdclass={
-        "build_ext": BuildJsonnetExt,
-    },
     ext_modules=[
         setuptools.Extension(
             "_jsonnet",
             sources=LIB_SOURCES,
-            include_dirs=[
-                "include",
-                "third_party/md5",
-                "third_party/json",
-                "third_party/rapidyaml",
-            ],
+            libraries = ['jsonnet'],
             language="c++",
         )
     ],
