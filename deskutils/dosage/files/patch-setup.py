--- ./setup.py.orig	2013-12-08 10:46:26.000000000 +0000
+++ ./setup.py	2013-12-09 18:15:42.000000000 +0000
@@ -188,7 +188,10 @@
     def get_outputs (self):
         """Add the generated config file to the list of outputs."""
         outs = super(MyInstallLib, self).get_outputs()
-        outs.append(self.get_conf_output())
+        conf_output = self.get_conf_output()
+        outs.append(conf_output)
+        if self.compile:
+            outs.extend(self._bytecode_filenames([conf_output]))
         return outs
 
 
