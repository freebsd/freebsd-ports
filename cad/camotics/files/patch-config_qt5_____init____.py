--- config/qt5/__init__.py.orig	2021-07-27 23:51:08 UTC
+++ config/qt5/__init__.py
@@ -710,6 +710,13 @@ def generate(env):
     Action = SCons.Action.Action
     Builder = SCons.Builder.Builder
 
+    version = tuple(map(int, SCons.__version__.split('.')))
+
+    QT5_MOCDEFINES = \
+        '${_defines(QT5_MOCDEFPREFIX, CPPDEFINES, QT5_MOCDEFSUFFIX, __env__'
+    if (4, 2, 0) <= version: QT5_MOCDEFINES += ', TARGET, SOURCE'
+    QT5_MOCDEFINES += ')}'
+
     env['QT5DIR'] = _detect(env)
     env.Replace(
         QT5DIR  = _detect(env),
@@ -762,8 +769,7 @@ def generate(env):
         QT5_QRCCXXPREFIX = 'qrc_',
         QT5_MOCDEFPREFIX = '-D',
         QT5_MOCDEFSUFFIX = '',
-        QT5_MOCDEFINES = '${_defines(QT5_MOCDEFPREFIX, CPPDEFINES, '
-        'QT5_MOCDEFSUFFIX, __env__)}',
+        QT5_MOCDEFINES = QT5_MOCDEFINES,
         QT5_MOCCPPPATH = [],
         QT5_MOCINCFLAGS = '$( ${_concat(QT5_MOCINCPREFIX, QT5_MOCCPPPATH, '
         'INCSUFFIX, __env__, RDirs)} $)',
