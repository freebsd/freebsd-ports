--- kvutils/temporary_file_directory.cpp.orig	Thu Mar 22 15:08:28 2001
+++ kvutils/temporary_file_directory.cpp	Sat Nov 24 09:22:36 2001
@@ -64,7 +64,7 @@
     }
   }
   else {
-//      cerr << "(kvutils) " << "mkdir(" << tdir_rep << ") failed" << endl;
+      cerr << "(kvutils) " << "mkdir(" << tdir_rep << ") failed" << endl;
     valid_rep = false;
   }
 }
@@ -97,32 +97,32 @@
 
   if (statbuf.st_uid != geteuid()) {
     valid_rep = false;
-//      cerr << "(kvutils) " << "st_uid doesn't match." << endl;
+      cerr << "(kvutils) " << "st_uid doesn't match." << endl;
   }
 
-  if (statbuf.st_gid != getegid()) {
-    valid_rep = false;
-//      cerr << "(kvutils) " << "st_gid doesn't match." << endl;
-  }
+  //if (statbuf.st_gid != getegid()) {
+    //valid_rep = false;
+      //cerr << "(kvutils) " << "st_gid doesn't match." << endl;
+  //}
 
   if (!S_ISDIR(statbuf.st_mode)) {
     valid_rep = false;
-//      cerr << "(kvutils) " << "st_mode - not a directory." << endl;
+      cerr << "(kvutils) " << "st_mode - not a directory." << endl;
   }
 
   if (S_ISLNK(statbuf.st_mode)) {
     valid_rep = false;
-//      cerr << "(kvutils) " << "st_mode - a symbolic link." << endl;
+      cerr << "(kvutils) " << "st_mode - a symbolic link." << endl;
   }
 
   if ((statbuf.st_mode & S_IRWXG) > 0) {
     valid_rep = false;
-//      cerr << "(kvutils) " << "st_mode - group has access." << endl;
+      cerr << "(kvutils) " << "st_mode - group has access." << endl;
   }
 
   if ((statbuf.st_mode & S_IRWXO) > 0) {
     valid_rep = false;
-//      cerr << "(kvutils) " << "st_mode - others have access." << endl;
+      cerr << "(kvutils) " << "st_mode - others have access." << endl;
   }
 }
 
