--- src/text/ptbl/xp/pd_DocumentRDF.h.orig	2015-03-31 15:15:00 UTC
+++ src/text/ptbl/xp/pd_DocumentRDF.h
@@ -68,6 +68,7 @@ class ABI_EXPORT PD_URI
     bool isValid() const;
     bool operator==(const PD_URI& b) const;
     bool operator==(const std::string& b) const;
+    bool operator<(const PD_URI& b) const;
 
     virtual bool read( std::istream& ss );
     virtual bool write( std::ostream& ss ) const;
