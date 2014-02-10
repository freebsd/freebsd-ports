Work around additional moc + Boost bugs that showed up after the Boost
upgrade from 1.52 to 1.55. This should make science/avogadro buildable
again.

See the discussion in QTBUG-22829.

Obtained from:	Fedora Project
http://pkgs.fedoraproject.org/cgit/qt.git/tree/qt-everywhere-opensource-src-4.8.5-QTBUG-22829.patch
--- src/tools/moc/main.cpp	2013-06-09 17:04:02.762459323 -0500
+++ src/tools/moc/main.cpp	2013-06-09 17:08:20.409680813 -0500
@@ -188,8 +188,9 @@ int runMoc(int _argc, char **_argv)
     pp.macros["Q_MOC_RUN"];
     pp.macros["__cplusplus"];
 
-    // Workaround a bug while parsing the boost/type_traits/has_operator.hpp header. See QTBUG-22829
+    // Workaround bugs while parsing some boost headers. See QTBUG-22829
     pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
+    pp.macros["BOOST_LEXICAL_CAST_INCLUDED"];
 
     QByteArray filename;
     QByteArray output;
