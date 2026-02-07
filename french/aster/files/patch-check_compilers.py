--- check_compilers.py.orig	2019-10-01 12:45:34 UTC
+++ check_compilers.py
@@ -215,7 +215,7 @@ class CONFIGURE_COMPILER:
       opt_env.append('')
 
       self.cfg['OPT_ENV'] = os.linesep.join(opt_env)
-      self.AddToEnv(self.cfg['OPT_ENV'], verbose=False)
+      self.AddToEnv(self.cfg['OPT_ENV'], verbose=True)
 
    def after_compilers(self):
       """After searching compilers, this allows to add libs to search
@@ -419,8 +419,7 @@ class GNU_COMPILER(CONFIGURE_COMPILER):
    def after_compilers(self):
       """Define libs to search."""
       # prefer always libstdc++.so to the static one
-      self.libs.extend([('math', 'lapack'), ('math', 'blas'),
-                        ('cxx', ['libstdc++' + self._ext_shared, 'libstdc++' + self._ext_static]),])
+      self.libs.extend([('math', 'lapack'), ('math', 'blas'),])
 
    def add_on(self):
       """After searching compilers, libs... search again other bin or lib."""
@@ -813,7 +812,7 @@ class COMPILER_MANAGER:
       """Return config dict."""
       return self.config.get(product, self.config.get('__main__')).cfg
 
-   def switch_in_dep(self, dependency_object, product, system=None, verbose=False):
+   def switch_in_dep(self, dependency_object, product, system=None, verbose=True):
       """Change 'cfg' attribute of the dependency_object.
       """
       __dbgsw  = False
@@ -921,7 +920,7 @@ class COMPILER_MANAGER:
          cfg['OPT_ENV'] += compiler_cfg.get('OPT_ENV', '')
       cfg['OPT_ENV'] = cfg['OPT_ENV'].strip()
       if system:
-         system.AddToEnv(cfg['OPT_ENV'], verbose=False)
+         system.AddToEnv(cfg['OPT_ENV'], verbose=True)
       if __dbgsw:
          print('             new=%s' % cfg['OPT_ENV'])
 
