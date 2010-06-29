--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/FileHandler.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/FileHandler.java	2010-06-29 10:10:17.000000000 +0200
@@ -69,7 +69,7 @@
 	private void doFile(ISO9660File file) throws HandlerException {
 		super.startElement(new FileElement(file));
 
-		FileDataReference fdr = new FileDataReference(file);
+		FileDataReference fdr = new FileDataReference(file.getFile());
 		data(fdr);
 
 		super.endElement();
