--- ./table.h.orig	2007-07-14 11:43:40.000000000 +0200
+++ ./table.h	2007-07-14 11:43:59.000000000 +0200
@@ -121,10 +121,10 @@
 		const table& a_class
 		);
 
-	size_type table::col_width(const size_type a_x) const;
-	size_type table::row_width(void) const;
-	size_type table::col_height(void) const;
-	size_type table::row_height(const size_type a_y) const;
+	size_type col_width(const size_type a_x) const;
+	size_type row_width(void) const;
+	size_type col_height(void) const;
+	size_type row_height(const size_type a_y) const;
 
 	virtual size_type height(void) const;
 	virtual size_type width(void) const;
