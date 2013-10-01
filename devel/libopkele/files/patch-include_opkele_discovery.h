--- include/opkele/discovery.h.orig	2008-06-25 20:50:26.000000000 +0000
+++ include/opkele/discovery.h
@@ -21,7 +21,7 @@ namespace opkele {
 		public:
 
 		    inline _DT& add(long priority,const _DT& d) {
-			return insert(typename map_type::value_type(priority,d))->second;
+			return this->insert(typename map_type::value_type(priority,d))->second;
 		    }
 
 		    bool has_value(const _DT& d) const {
