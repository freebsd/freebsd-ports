--- cfcreate.cpp.orig	1999-10-24 11:29:53 UTC
+++ cfcreate.cpp
@@ -29,6 +29,10 @@
 #include <unistd.h>
 #endif
 
+using std::ios;
+using std::ifstream;
+using std::ofstream;
+
 ///////////////////////////////////////***************************************
 
 int cfc_fileinfo::write_entry(ostream& out)
@@ -129,7 +133,7 @@ int cfc_folderinfo::add_file(const char*
 		}
 	}
 
-	if(fstat(in.rdbuf()->fd(), &statbuf) != 0) return FSTAT_FAILURE;
+	if(stat(fname, &statbuf) != 0) return FSTAT_FAILURE;
 #ifndef unix
 	if(getftime(in.rdbuf()->fd(), &datetime) != 0) return GETTIME_FAILURE;
 #endif
@@ -194,7 +198,7 @@ int cfc_folderinfo::read_block(istream& 
 	unprocessed_data = NULL;				// Reset buffer holder
 	unprocessed_data_len = 0u;
 
-	if(in.read(buf + bytesread, len - bytesread).bad())
+	if(in.read((char*)buf + bytesread, len - bytesread).bad())
 	{
 		delete[] buf;
 		buf = NULL;
@@ -272,7 +276,7 @@ int cfc_folderinfo::process_block(const 
 		return WRITE_ERROR;
 	}
 
-	tempfile->write(compdata, blockinfo.compressed_len);
+	tempfile->write((char*)compdata, blockinfo.compressed_len);
 	processed_bytes += sizeof(blockinfo) + blockinfo.compressed_len;
 	if(compdata != data) delete[] compdata;	// If buffer was allocated, free it
 	data_blocks++;						// Incriment block counter
