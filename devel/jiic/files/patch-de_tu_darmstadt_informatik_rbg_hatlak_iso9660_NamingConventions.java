--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/NamingConventions.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/NamingConventions.java	2010-06-29 10:12:14.000000000 +0200
@@ -178,7 +178,7 @@
 				// First try to append the number
 				ISO9660File copy = null;
 				try {
-					copy = new ISO9660File(file);
+					copy = new ISO9660File(file.getFile());
 				} catch (HandlerException e) {
 					e.printStackTrace();
 				}
