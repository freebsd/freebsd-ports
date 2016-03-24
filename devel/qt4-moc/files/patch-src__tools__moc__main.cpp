Workaround for Boost: Qt4's moc cannot parse macros in namespace declarations,
leading to errors such as:

    Parse error at "BOOST_JOIN"

This is fixed in Qt5 (the upstream bug is QTBUG-22829), but fixing it in Qt4
requires substantial changes that upstream has decided not to backport.

What we do to work around the issue is define some Boost include guards so that
they end up being skipped by moc when it is preprocessing a file.
--- src/tools/moc/main.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/tools/moc/main.cpp
@@ -190,6 +190,17 @@ int runMoc(int _argc, char **_argv)
 
     // Workaround a bug while parsing the boost/type_traits/has_operator.hpp header. See QTBUG-22829
     pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
+    // Additional workarounds for newer Boost versions. The version numbers
+    // below are the first versions in the ports tree to require them, not
+    // the first versions upstream to require them (ie. we might have skipped
+    // some Boost versions in the ports tree).
+    //
+    // For Boost >= 1.55.
+    pp.macros["BOOST_LEXICAL_CAST_INCLUDED"];
+    // For Boost >= 1.60.
+    pp.macros["BOOST_NEXT_PRIOR_HPP_INCLUDED"];
+    pp.macros["BOOST_TYPE_TRAITS_HPP"];
+    pp.macros["BOOST_TT_HAS_PRE_INCREMENT_HPP_INCLUDED"];
 
     QByteArray filename;
     QByteArray output;
