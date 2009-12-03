
$FreeBSD$

--- src/attribute/search-basket-column-record.h.orig
+++ src/attribute/search-basket-column-record.h
@@ -34,6 +34,8 @@
     public:
         SearchBasketColumnRecord() throw();
 
+        SearchBasketColumnRecord(const SearchBasketColumnRecord& rec) throw();
+
         virtual
         ~SearchBasketColumnRecord() throw();
 
