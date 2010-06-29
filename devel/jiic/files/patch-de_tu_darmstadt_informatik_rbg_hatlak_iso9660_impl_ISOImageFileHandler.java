--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/ISOImageFileHandler.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/ISOImageFileHandler.java	2010-06-28 17:26:15.000000000 +0200
@@ -93,10 +93,13 @@
 	}
 	
 	public Fixup fixup(DataReference reference) throws HandlerException {
-		Fixup fixup = null;
-		fixup = new FileFixup(file, position, reference.getLength());
-		data(reference);
-		return fixup;
+		try {
+			Fixup fixup = new FileFixup(new RandomAccessFile(file, "rw"), position, reference.getLength());
+			data(reference);
+			return fixup;
+		} catch (FileNotFoundException e) {
+			throw new HandlerException(e);
+		}
 	}
 	
 	public long mark() throws HandlerException {
