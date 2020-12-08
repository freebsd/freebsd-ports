From https://github.com/frescobaldi/python-poppler-qt5/pull/41/commits/4ee58b6ee02772db915fdc5e70e336e0e5b2f34c

--- project.py.orig	2020-10-11 18:59:42 UTC
+++ project.py
@@ -0,0 +1,89 @@
+"""The build configuration file for Python-Poppler-Qt5, used by sip."""
+
+from os.path import join
+import re
+import subprocess
+from pyqtbuild import PyQtBindings, PyQtProject
+from sipbuild import Option
+import PyQt5
+
+
+class PythonPopplerQt5(PyQtProject):
+    """The Project class."""
+
+    def __init__(self):
+        super().__init__()
+        self.bindings_factories = [PopplerQt5Bindings]
+
+    def update(self, tool):
+        """Allows SIP to find PyQt5 .sip files."""
+        super().update(tool)
+        self.sip_include_dirs.append(join(PyQt5.__path__[0], 'bindings'))
+
+
+class PopplerQt5Bindings(PyQtBindings):
+    """The Poppler-Qt5 Bindings class."""
+
+    def __init__(self, project):
+        super().__init__(project, name='Poppler-Qt5',
+                         sip_file='poppler-qt5.sip',
+                         qmake_QT=['xml'])
+
+    def get_options(self):
+        """Our custom options that a user can pass to sip-build."""
+        options = super().get_options()
+        options.append(
+            Option('poppler_version',
+                   help='version of the poppler library',
+                   metavar='VERSION'))
+        return options
+
+    @staticmethod
+    def run_pkg_config(option):
+        output = subprocess.check_output(
+            ['pkg-config', option, 'poppler-qt5'],
+            text=True)
+        return output.rstrip()
+
+    def apply_user_defaults(self, tool):
+        # Set include_dirs, library_dirs and libraries based on pkg-config data
+        cflags = self.run_pkg_config('--cflags-only-I').split()
+        libs = self.run_pkg_config('--libs').split()
+        self.include_dirs.extend(
+            flag[2:] for flag in cflags if flag.startswith('-I'))
+        self.library_dirs.extend(
+            flag[2:] for flag in libs if flag.startswith('-L'))
+        self.libraries.extend(
+            flag[2:] for flag in libs if flag.startswith('-l'))
+
+        # Generate version.sip file
+        if self.poppler_version is not None:
+            poppler_qt5_version = self.poppler_version
+        else:
+            poppler_qt5_version = self.run_pkg_config('--modversion')
+        poppler_qt5_version = tuple(map(int, poppler_qt5_version.split('.')))
+        python_poppler_qt5_version = self.project.version_str.split('.')
+        format_dict = {
+            'vlen': 'i' * len(python_poppler_qt5_version),
+            'vargs': ', '.join(python_poppler_qt5_version),
+            'pvlen': 'i' * len(poppler_qt5_version),
+            'pvargs': ', '.join(map(str, poppler_qt5_version)),
+        }
+        with open('version.sip.in') as template_file:
+            version_sip_template = template_file.read()
+        with open('version.sip', 'w') as version_file:
+            version_file.write(version_sip_template.format(**format_dict))
+
+        # Add Poppler version tag
+        if poppler_qt5_version:
+            with open('timeline.sip') as timeline_file:
+                timeline = timeline_file.read()
+            for match in re.finditer(r'POPPLER_V(\d+)_(\d+)_(\d+)', timeline):
+                if poppler_qt5_version < tuple(map(int, match.group(1, 2, 3))):
+                    break
+                tag = match.group()
+        else:
+            tag = 'POPPLER_V0_20_0'
+        self.tags.append(tag)
+        self.tags.append("WS_X11")
+        super().apply_user_defaults(tool)
