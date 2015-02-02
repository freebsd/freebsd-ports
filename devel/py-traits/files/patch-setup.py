--- setup.py.orig	2014-05-07 10:39:42 UTC
+++ setup.py
@@ -11,7 +11,6 @@ exec(compile(open(traits_init).read(), t
 ctraits = Extension(
     'traits.ctraits',
     sources = ['traits/ctraits.c'],
-    extra_compile_args = ['-DNDEBUG=1', '-O3' ]#, '-DPy_LIMITED_API'],
     )
 
 
@@ -55,7 +54,8 @@ setup(
     license = 'BSD',
     maintainer = 'ETS Developers',
     maintainer_email = 'enthought-dev@enthought.com',
-    packages = find_packages(),
+    # remove 'traits.testing*' directories not compatible with Python 3
+    packages = find_packages(where='.', exclude=['traits.testing*']),
     platforms = ["Windows", "Linux", "Mac OS-X", "Unix", "Solaris"],
     zip_safe = False,
     use_2to3 = True,
