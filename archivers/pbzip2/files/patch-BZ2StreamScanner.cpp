--- BZ2StreamScanner.cpp.orig	2024-11-03 23:01:39 UTC
+++ BZ2StreamScanner.cpp
@@ -49,8 +49,8 @@ int BZ2StreamScanner::init( int hInFile, size_t inBuff
 
 	_hInFile = hInFile;
 	_eof = false;
-	_bz2Header = bz2header;
-	_bz2HeaderZero = bz2ZeroHeader;
+	_bz2Header.assign(begin(bz2header), end(bz2header));
+	_bz2HeaderZero.assign(begin(bz2ZeroHeader), end(bz2ZeroHeader));
 	_bz2HeaderFound = false;
 	_inBuffCapacity = 0;
 	_errState = 0;
@@ -361,7 +361,7 @@ BZ2StreamScanner::CharType * BZ2StreamScanner::locateH
 			_errState |= ERR_INVALID_FILE_FORMAT;
 			_inBuffSearchPtr = getInBuffEnd();
 		}
-		else if ( _bz2Header.compare( 0, prefixLen, getInBuffSearchPtr(), prefixLen ) == 0 )
+		else if ( equal( _bz2Header.begin(), _bz2Header.begin() + prefixLen, getInBuffSearchPtr() ) )
 		{
 			// header prefix found
 		}
@@ -416,7 +416,7 @@ BZ2StreamScanner::CharType * BZ2StreamScanner::searchN
 	while ( !failed() && ( getUnsearchedCount() >= getHeaderSize() ) )
 	{
 		// _inBuffSearchPtr += prefixLen;
-		basic_string<CharType> * pHdr = NULL;
+		vector<CharType> * pHdr = NULL;
 
 		if ( getInBuffSearchPtr()[hsp] == _bz2Header[hsp] )
 		{
@@ -441,13 +441,14 @@ BZ2StreamScanner::CharType * BZ2StreamScanner::searchN
 				(*pHdr)[prefixLen] = bwtSizeChar;
 
 				// compare the remaining part of magic header
-				int cmpres = pHdr->compare( hsp, pHdr->size() - hsp,
-						getInBuffSearchPtr() + hsp, pHdr->size() - hsp );
+				bool cmpres = equal( pHdr->begin() + hsp, pHdr->begin() + pHdr->size() - hsp,
+						getInBuffSearchPtr() );
 
+
 				#ifdef PBZIP_DEBUG
 				fprintf( stderr, "   searchNextHeaderInBuff:cmpres=%d\n", cmpres );
 				#endif
-				if ( cmpres == 0 )
+				if ( cmpres )
 				{
 					_searchStatus = true;
 					#ifdef PBZIP_DEBUG
