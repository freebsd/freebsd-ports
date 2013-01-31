--- ./src/tools/moc/main.cpp.orig	2013-01-30 16:16:31.615488856 +0000
+++ ./src/tools/moc/main.cpp	2013-01-30 16:16:52.991681291 +0000
@@ -187,6 +187,7 @@
     Moc moc;
     pp.macros["Q_MOC_RUN"];
     pp.macros["__cplusplus"];
+    pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
     QByteArray filename;
     QByteArray output;
     FILE *in = 0;
