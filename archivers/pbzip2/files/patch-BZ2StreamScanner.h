--- BZ2StreamScanner.h.orig	2015-12-17 23:32:49 UTC
+++ BZ2StreamScanner.h
@@ -44,7 +44,7 @@ class BZ2StreamScanner (public)
 
 	size_t getInBuffSize() const { return ( _inBuffEnd - _inBuff ); }
 	size_t getInBuffCapacity() const { return _inBuffCapacity; }
-	const basic_string<CharType> & getHeader() const { return _bz2Header; }
+	const vector<CharType> & getHeader() const { return _bz2Header; }
 	size_t getHeaderSize() const { return _bz2Header.size(); }
 	int getErrState() const { return _errState; }
 	bool failed() { return ( _errState != 0 ); }
@@ -125,8 +125,8 @@ class BZ2StreamScanner (public)
 	int _hInFile; // input file descriptor
 	bool _eof;
 
-	basic_string<CharType> _bz2Header;
-	basic_string<CharType> _bz2HeaderZero;
+	vector<CharType> _bz2Header;
+	vector<CharType> _bz2HeaderZero;
 	bool _bz2HeaderFound;
 	bool _searchStatus;
 
