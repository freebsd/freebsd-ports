--- gonzui/dbm.rb.orig	2005-03-25 17:07:50.000000000 +0900
+++ gonzui/dbm.rb	2009-07-22 11:39:59.000000000 +0900
@@ -453,7 +453,7 @@
     end
 
     def get_format_ids_from_package_id(package_id)
-      @pkgid_fmtids.duplicates(package_id)
+      @pkgid_fmtids.copies(package_id)
     end
 
     def get_format_name(format_id)
@@ -473,7 +473,7 @@
     end
 
     def get_license_ids_from_package_id(package_id)
-      @pkgid_lcsids.duplicates(package_id)
+      @pkgid_lcsids.copies(package_id)
     end
 
     def get_license_name(license_id)
@@ -502,7 +502,7 @@
 
     def get_ncontents_in_package(package_name)
       package_id = get_package_id(package_name)
-      @pkgid_pathids.duplicates(package_id).length
+      @pkgid_pathids.copies(package_id).length
     end
 
     def get_nformats
@@ -530,7 +530,7 @@
     end
 
     def get_package_ids(word_id)
-      @wordid_pkgids.duplicates(word_id)
+      @wordid_pkgids.copies(word_id)
     end
 
     def get_package_name(package_id)
@@ -543,7 +543,7 @@
 
     def get_package_options(package_id)
       options = {}
-      values = @pkgid_options.duplicates(package_id)
+      values = @pkgid_options.copies(package_id)
       values.each {|value|
         k, v = value.split(":", 2)
         k = k.intern
@@ -571,12 +571,12 @@
     end
 
     def get_path_ids(package_id)
-      @pkgid_pathids.duplicates(package_id)
+      @pkgid_pathids.copies(package_id)
     end
 
     def get_path_ids_from_package_and_word_id(package_id, word_id)
       package_word_id = AutoPack.pack_id2(package_id, word_id)
-      return @pkgwordid_pathids.duplicates(package_word_id)
+      return @pkgwordid_pathids.copies(package_word_id)
     end
 
     def get_source_uri(package_id)
