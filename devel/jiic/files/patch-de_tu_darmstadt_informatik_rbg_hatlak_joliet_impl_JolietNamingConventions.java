--- de/tu_darmstadt/informatik/rbg/hatlak/joliet/impl/JolietNamingConventions.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/joliet/impl/JolietNamingConventions.java	2010-06-29 09:23:15.000000000 +0200
@@ -82,10 +82,10 @@
 		if (filename.length() + extension.length() + (file.getVersion()+"").length() + 2 > 64) {
 			if (filename.length() >= extension.length()) {
 				// Shorten filename
-				filename = filename.substring(0, 64-extension.length());
+				filename = filename.substring(0, 64-extension.length()-(file.getVersion()+"").length()-2);
 			} else {
 				// Shorten extension
-				extension = extension.substring(0, 64-filename.length());				
+				extension = extension.substring(0, 64-filename.length()-(file.getVersion()+"").length()-2);				
 			}
 		}
 		
