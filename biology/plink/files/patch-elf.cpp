--- elf.cpp.orig	2013-11-16 17:09:56.000000000 +0100
+++ elf.cpp	2013-11-16 17:10:24.000000000 +0100
@@ -1175,10 +1175,10 @@
 	  << setw(8) << gcnt << " "
 	  << setw(8) << (double)cnt / (double)gcnt << "\n";
 
-      map<int,int>::iterator i = chr_cnt.begin();
-      while ( i != chr_cnt.end() )
+      map<int,int>::iterator ichr = chr_cnt.begin();
+      while ( ichr != chr_cnt.end() )
 	{
-	  int c = i->first;
+	  int c = ichr->first;
 	  int x = chr_cnt.find( c )->second;
 	  int y = chr_gcnt.find( c )->second;
 	  
@@ -1189,7 +1189,7 @@
 	      << setw(8) << y << " "
 	      << setw(8) << (double)x / (double)y << "\n";
 	  
-	  ++i;
+	  ++ichr;
 	}
       
     }
