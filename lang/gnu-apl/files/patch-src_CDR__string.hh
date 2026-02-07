--- src/CDR_string.hh.orig	2019-06-23 12:39:20 UTC
+++ src/CDR_string.hh
@@ -73,7 +73,7 @@ class CDR_string : public std::vector<uint8_t> (public
 
    /// return the bytes of this CDR
    const uint8_t * get_items() const
-      { return &front(); }
+      { return utf8P(&front()); }
 
    /// return the header of this CDR
    const CDR_header & header() const
@@ -92,7 +92,7 @@ class CDR_string : public std::vector<uint8_t> (public
 
    /// return the ravel of this CDR
    const uint8_t * ravel() const
-      { return &(*this)[0] + 16 + 4*get_rank(); }
+      { return utf8P(&(*this)[0] + 16 + 4*get_rank()); }
 
    /// return true if this CDR is bool or integer
    bool is_integer() const
@@ -131,7 +131,7 @@ class CDR_string : public std::vector<uint8_t> (public
 protected:
    /// return 4 bytes of the header (the header is always big endian)
    uint32_t get_4(unsigned int offset) const
-      { return CDR_header::get_be32(&(*this)[0] + offset); }
+      { return CDR_header::get_be32(utf8P(&(*this)[0] + offset)); }
 };
 
 #endif // __CDR_STRING_HH_DEFINED__
