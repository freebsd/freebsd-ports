--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/ISO9660Factory.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/ISO9660Factory.java	2010-06-29 10:11:08.000000000 +0200
@@ -322,7 +322,7 @@
 		
 		// Write and close Length Fixup
 		Fixup dataLengthFixup = (Fixup) memory.get("drDataLengthFixup");
-		dataLengthFixup.data(new BothWordDataReference(file.length()));
+		dataLengthFixup.data(new BothWordDataReference(file.getFile().length()));
 		dataLengthFixup.close();
 		
 		return memory;
