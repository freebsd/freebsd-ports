--- cfcreate.cpp.orig	Sun Oct 24 13:29:53 1999
+++ cfcreate.cpp	Tue Aug 19 21:16:05 2003
@@ -29,6 +29,8 @@
 #include <unistd.h>
 #endif
 
+using std::ios;
+
 ///////////////////////////////////////***************************************
 
 int cfc_fileinfo::write_entry(ostream& out)
@@ -129,7 +131,7 @@
 		}
 	}
 
-	if(fstat(in.rdbuf()->fd(), &statbuf) != 0) return FSTAT_FAILURE;
+	if(stat(fname, &statbuf) != 0) return FSTAT_FAILURE;
 #ifndef unix
 	if(getftime(in.rdbuf()->fd(), &datetime) != 0) return GETTIME_FAILURE;
 #endif
@@ -194,7 +196,7 @@
 	unprocessed_data = NULL;				// Reset buffer holder
 	unprocessed_data_len = 0u;
 
-	if(in.read(buf + bytesread, len - bytesread).bad())
+	if(in.read((char*)buf + bytesread, len - bytesread).bad())
 	{
 		delete[] buf;
 		buf = NULL;
@@ -272,7 +274,7 @@
 		return WRITE_ERROR;
 	}
 
-	tempfile->write(compdata, blockinfo.compressed_len);
+	tempfile->write((char*)compdata, blockinfo.compressed_len);
 	processed_bytes += sizeof(blockinfo) + blockinfo.compressed_len;
 	if(compdata != data) delete[] compdata;	// If buffer was allocated, free it
 	data_blocks++;						// Incriment block counter
