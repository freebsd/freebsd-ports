--- build/qt4.py.orig	2013-05-08 23:20:26 UTC
+++ build/qt4.py
@@ -246,8 +246,8 @@ def generate(env):
 	env.Replace(
 #		QTDIR  = _detect(env),
 		QT4_BINPATH = os.path.join('$QTDIR', 'bin'),
-		QT4_CPPPATH = os.path.join('$QTDIR', 'include'),
-		QT4_LIBPATH = os.path.join('$QTDIR', 'lib'),
+		QT4_CPPPATH = os.path.join('$QTDIR', 'include', 'qt4', 'Qt'),
+		QT4_LIBPATH = os.path.join('$QTDIR', 'lib', 'qt4'),
 		# TODO: This is not reliable to QTDIR value changes but needed in order to support '-qt4' variants
 		QT4_MOC = locateQt4Command(env,'moc', env['QTDIR']),
 		QT4_UIC = locateQt4Command(env,'uic', env['QTDIR']),
