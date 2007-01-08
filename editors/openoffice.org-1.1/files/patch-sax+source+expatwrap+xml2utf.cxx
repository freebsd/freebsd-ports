diff -urN -x CVS -x unxlngi6.pro sax.orig/source/expatwrap/xml2utf.cxx sax/source/expatwrap/xml2utf.cxx
--- sax.orig/source/expatwrap/xml2utf.cxx	2005-09-08 14:05:22.000000000 +0200
+++ sax/source/expatwrap/xml2utf.cxx	2006-06-22 11:04:22.000000000 +0200
@@ -78,24 +78,26 @@
 				// ensure that enough data is available to parse encoding
 				if( seqStart.getLength() )
 				{
-					seq.realloc( seqStart.getLength() + seq.getLength() );
-					memcpy( (sal_Int8*)seq.getConstArray() + seqStart.getLength() ,
-							seq.getConstArray() ,
-							seq.getLength() );
-					memcpy( (sal_Int8*)seq.getConstArray() ,
-							seqStart.getConstArray(),
-							seqStart.getLength() );
+				  // prefix with what we had so far.
+				  sal_Int32 nLength = seq.getLength();
+				  seq.realloc( seqStart.getLength() + nLength );
+
+				  memmove (seq.getArray() + seqStart.getLength(),
+					   seq.getConstArray(),
+					   nLength);
+				  memcpy  (seq.getArray(),
+					   seqStart.getConstArray(),
+					   seqStart.getLength());
 				}
 
 				// autodetection with the first bytes
 				if( ! isEncodingRecognizable( seq ) )
 				{
-					seqStart.realloc( seqStart.getLength() + seq.getLength() );
-					memcpy( (sal_Int8*)seqStart.getConstArray() + seqStart.getLength(),
-							seq.getConstArray(),
-							seq.getLength());
-					// read more !
-					continue;
+				  // remember what we have so far.
+				  seqStart = seq;
+
+				  // read more !
+				  continue;
 				}
 				if( scanForEncoding( seq ) || m_sEncoding.getLength() ) {
 					// initialize decoding
@@ -291,7 +293,7 @@
 
 		// simply add the byte order mark !
 		seq.realloc( seq.getLength() + 2 );
-		memmove( &( seq.getArray()[2] ) , seq.getArray() , seq.getLength() );
+		memmove( &( seq.getArray()[2] ) , seq.getArray() , seq.getLength() - 2 );
 		((sal_uInt8*)seq.getArray())[0] = 0xFE;
 		((sal_uInt8*)seq.getArray())[1] = 0xFF;
 
@@ -302,7 +304,7 @@
 		// The byte order mark is simply added
 
 		seq.realloc( seq.getLength() + 2 );
-		memmove( &( seq.getArray()[2] ) , seq.getArray() , seq.getLength() );
+		memmove( &( seq.getArray()[2] ) , seq.getArray() , seq.getLength() - 2 );
 		((sal_uInt8*)seq.getArray())[0] = 0xFF;
 		((sal_uInt8*)seq.getArray())[1] = 0xFE;
 
@@ -511,9 +513,7 @@
 		// In general when surrogates are used, they should be rarely
 		// cut off between two convert()-calls. So this code is used
 		// rarely and the extra copy is acceptable.
-		nSourceSize += m_seqSource.getLength();
-
-		puTempMem = new sal_Unicode[ nSourceSize ];
+		puTempMem = new sal_Unicode[ nSourceSize + m_seqSource.getLength()];
 		memcpy( puTempMem ,
 				m_seqSource.getConstArray() ,
 				m_seqSource.getLength() * sizeof( sal_Unicode ) );
@@ -522,6 +522,7 @@
 			puSource ,
 			nSourceSize*sizeof( sal_Unicode ) );
 		puSource = puTempMem;
+		nSourceSize += m_seqSource.getLength();
 
 		m_seqSource = Sequence< sal_Unicode > ();
 	}

