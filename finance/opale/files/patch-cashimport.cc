--- opale/filters/cashimport.cc.orig	Mon Aug 23 14:15:41 2004
+++ opale/filters/cashimport.cc	Mon Aug 23 14:17:59 2004
@@ -37,7 +37,7 @@
         (((a) & 0x0000ff00U) <<  8) | \
         (((a) & 0x00ff0000U) >>  8))
 
-#define USE_SWAP(_x)	(((unsigned int)_x)=INT_SWAP(((unsigned int)_x)))
+#define USE_SWAP(_x)	((_x)=INT_SWAP(((unsigned int)_x)))
 
 
 /*
@@ -117,12 +117,7 @@
 	QDataStream stream(&in);
 
 	char magic[]="CASH_MAGICxxx";
-	stream >> (unsigned char)magic[0]; stream >> (unsigned char)magic[1];
-	stream >> (unsigned char)magic[2]; stream >> (unsigned char)magic[3];
-	stream >> (unsigned char)magic[4]; stream >> (unsigned char)magic[5];
-	stream >> (unsigned char)magic[6]; stream >> (unsigned char)magic[7];
-	stream >> (unsigned char)magic[8]; stream >> (unsigned char)magic[9];
-	stream >> (unsigned char)magic[10];
+	stream.readRawBytes(magic,11);
 
 	if ( magic[10]!=0 ||
 		magic[9]!='C' || magic[8]!='I' ||
@@ -144,9 +139,7 @@
 	emit sigProgress(2);
 
 	// read the number of record
-	stream >> (unsigned char)magic[0]; stream >> (unsigned char)magic[1];
-	stream >> (unsigned char)magic[2]; stream >> (unsigned char)magic[3];
-	stream >> (unsigned char)magic[4]; //stream >> (unsigned char)magic[5];
+	stream.readRawBytes(magic,5);
 	magic[5] = 0;
 
 	int n = atoi(magic);
@@ -160,8 +153,7 @@
 		QString	name;
 
 		// get the data
-		for (unsigned int li=0; li< sizeof(s_ope); li++)
-			stream >> (unsigned char) ope.c[li];
+		stream.readRawBytes(ope.c,sizeof(s_ope));
 
 		if (need_swap) {
 			USE_SWAP(ope.ope.how);
