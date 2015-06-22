--- src/text/ptbl/xp/pd_DocumentRDF.cpp.orig	2015-03-31 15:14:42 UTC
+++ src/text/ptbl/xp/pd_DocumentRDF.cpp
@@ -570,6 +570,11 @@ bool PD_URI::operator==(const std::strin
     return m_value == b;
 }
 
+bool PD_URI::operator<(const PD_URI& b) const
+{
+    return m_value < b.m_value;
+}
+
 PD_URI
 PD_URI::prefixedToURI( PD_RDFModelHandle model ) const
 {
@@ -611,11 +616,6 @@ bool PD_URI::write( std::ostream& ss ) c
     return true;
 }
 
-bool operator<( PD_URI a, PD_URI b)
-{
-    return a.toString() < b.toString();
-}
-
 bool operator<( std::pair< PD_URI, PD_URI > a, PD_URI b)
 {
     return a.first.toString() < b.toString();
