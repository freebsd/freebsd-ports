--- IosVector.cpp.orig	2007-10-30 13:24:55.000000000 +0100
+++ IosVector.cpp	2007-10-30 13:25:29.000000000 +0100
@@ -102,6 +102,6 @@
 void IosVector::dumpVector() const {
 	fprintf(stderr, "Size: %d\n", getSize());
 	for (int i = 0, j = getSize() ; i < j ; i++)
-		fprintf(stderr, "elt[%d]=%d ", i, (int)getElementAt(i));
+		fprintf(stderr, "elt[%d]=%p ", i, getElementAt(i));
 	fprintf(stderr, "\n");
 }
