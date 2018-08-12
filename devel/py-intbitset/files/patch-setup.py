# Respect CFLAGS, remove x86 specific -march tuning which fails on !x86 archs
# https://svnweb.freebsd.org/changeset/ports/476958

--- setup.py.orig	2018-08-12 04:50:38 UTC
+++ setup.py
@@ -48,7 +48,6 @@ setup(
     ext_modules=[
         Extension("intbitset",
                   ["intbitset/intbitset.c", "intbitset/intbitset_impl.c"],
-                  extra_compile_args=['-O3', '-march=core2', '-mtune=native']
                   # For debug -> '-ftree-vectorizer-verbose=2'
                   )
     ],
