--- build/qt4.py.orig	2011-12-24 11:53:19.000000000 +0900
+++ build/qt4.py	2012-01-16 06:10:09.000000000 +0900
@@ -245,8 +245,8 @@
 	env.Replace(
 #		QTDIR  = _detect(env),
 		QT4_BINPATH = os.path.join('$QTDIR', 'bin'),
-		QT4_CPPPATH = os.path.join('$QTDIR', 'include'),
-		QT4_LIBPATH = os.path.join('$QTDIR', 'lib'),
+		QT4_CPPPATH = os.path.join('$QTDIR', 'include', 'qt4'),
+		QT4_LIBPATH = os.path.join('$QTDIR', 'lib', 'qt4'),
 		# TODO: This is not reliable to QTDIR value changes but needed in order to support '-qt4' variants
 		QT4_MOC = locateQt4Command(env,'moc', env['QTDIR']),
 		QT4_UIC = locateQt4Command(env,'uic', env['QTDIR']),
