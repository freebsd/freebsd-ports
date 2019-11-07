--- setup.py.orig	2019-09-18 06:52:51 UTC
+++ setup.py
@@ -12,86 +12,20 @@ from setuptools import setup
 from setuptools.extension import Extension
 from setuptools.command.build_ext import _build_ext
 
-
-dependencies_dir_path = join(abspath(dirname(__file__)), "dependencies")
-
-onig_tarball_path = join(dependencies_dir_path, "onig-6.9.0.tar.gz")
-onig_install_path = join(dependencies_dir_path, "onig_install")
-onig_source_path = join(dependencies_dir_path, "onig-6.9.0")
-
-jq_tarball_path = join(dependencies_dir_path, "jq-1.5.tar.gz")
-jq_install_path = join(dependencies_dir_path, "jq_install")
-jq_source_path = join(dependencies_dir_path, "jq-jq-1.5")
-
-
 class build_ext(_build_ext):
     def run(self):
-        self._build_oniguruma()
-        self._build_libjq()
         _build_ext.run(self)
 
-    def _build_oniguruma(self):
-        self._safe_rmtree(onig_install_path)
-        self._safe_rmtree(onig_source_path)
-
-        self._extract_tarball(onig_tarball_path, dependencies_dir_path)
-        self._build_lib(
-            lib_dir=onig_source_path,
-            commands=[
-                ["./configure", "CFLAGS=-fPIC", "--disable-shared", "--prefix", onig_install_path],
-                ["make"],
-                ["make", "install"],
-            ]
-        )
-
-    def _build_libjq(self):
-        self._safe_rmtree(jq_install_path)
-        self._safe_rmtree(jq_source_path)
-
-        self._extract_tarball(jq_tarball_path, dependencies_dir_path)
-        self._build_lib(
-            lib_dir=jq_source_path,
-            commands=[
-                ["autoreconf", "-i"],
-                ["./configure", "CFLAGS=-fPIC", "--disable-maintainer-mode",
-                 "--enable-all-static", "--disable-shared",
-                 "--with-oniguruma=" + onig_install_path, "--prefix", jq_install_path],
-                ["make", "install-libLTLIBRARIES", "install-includeHEADERS"],
-            ]
-        )
-
-    def _build_lib(self, lib_dir, commands):
-        macosx_deployment_target = sysconfig.get_config_var("MACOSX_DEPLOYMENT_TARGET")
-        if macosx_deployment_target:
-            os.environ['MACOSX_DEPLOYMENT_TARGET'] = macosx_deployment_target
-
-        for command in commands:
-            subprocess.check_call(command, cwd=lib_dir)
-
-    def _extract_tarball(self, tarball_path, workdir_path):
-        tarfile.open(tarball_path, "r:gz").extractall(workdir_path)
-
-    def _safe_rmtree(self, d):
-        try:
-            shutil.rmtree(d)
-        except OSError:
-            pass
-
 libraries = ["jq", "onig"]
-if platform.architecture()[1] == 'WindowsPE':
-    libraries.append("shlwapi")
 
 pyjq = Extension(
     "_pyjq",
     sources=["_pyjq.c"],
-    include_dirs=["dependencies/jq_install/include"],
     libraries=libraries,
-    library_dirs=["dependencies/jq_install/lib", "dependencies/onig_install/lib"]
 )
 
 setup(
     test_suite='test_pyjq',
     ext_modules=[pyjq],
     cmdclass={"build_ext": build_ext},
-    package_data={'': [onig_tarball_path, jq_tarball_path]},
 )
