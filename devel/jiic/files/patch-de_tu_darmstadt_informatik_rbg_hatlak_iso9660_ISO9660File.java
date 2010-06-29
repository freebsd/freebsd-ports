--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/ISO9660File.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/ISO9660File.java	2010-06-29 09:23:34.000000000 +0200
@@ -265,7 +265,7 @@
 		this.enforceDotDelimiter = force;
 	}
 
-	public int compareTo(Object object) throws ClassCastException, NullPointerException {
+	public int compareTo(File object) throws ClassCastException, NullPointerException {
 		// Alphanumerical case-insensitive sort (according to ISO9660 needs)
 		if (object==null) {
 			throw new NullPointerException();
@@ -292,10 +292,6 @@
 			} // else: Compare extensions
 			
 			return getExtension().toUpperCase().compareTo(file.getExtension().toUpperCase());
-		} else
-		if (object instanceof ISO9660Directory) {
-			ISO9660Directory dir = (ISO9660Directory) object;
-			return getFullName().toUpperCase().compareTo(dir.getName().toUpperCase());
 		} else {
 			throw new ClassCastException();			
 		}		
