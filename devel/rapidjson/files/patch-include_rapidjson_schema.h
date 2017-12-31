--- include/rapidjson/schema.h.orig	2016-08-25 07:59:05 UTC
+++ include/rapidjson/schema.h
@@ -379,7 +379,6 @@ class Schema { (public)
         exclusiveMinimum_(false),
         exclusiveMaximum_(false)
     {
-        typedef typename SchemaDocumentType::ValueType ValueType;
         typedef typename ValueType::ConstValueIterator ConstValueIterator;
         typedef typename ValueType::ConstMemberIterator ConstMemberIterator;
 
