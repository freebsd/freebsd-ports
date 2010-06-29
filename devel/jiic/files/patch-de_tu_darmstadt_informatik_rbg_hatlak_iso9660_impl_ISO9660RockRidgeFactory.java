--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/ISO9660RockRidgeFactory.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/impl/ISO9660RockRidgeFactory.java	2010-06-29 10:11:23.000000000 +0200
@@ -160,7 +160,7 @@
 		rripFactory.doPXEntry(fileModes, 1, 0, 0, 1);
 		
 		// TF: Timestamp
-		ISO9660ShortDateDataReference date = new ISO9660ShortDateDataReference(file.lastModified());
+		ISO9660ShortDateDataReference date = new ISO9660ShortDateDataReference(file.getFile().lastModified());
 		rripFactory.doTFEntry(RRIPFactory.TF_MODIFY, date);
 
 		// Compute length up to here
