--- class/LKV/Bstream.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/Bstream.h	20 Feb 2006 10:55:38 -0000
@@ -10,7 +10,7 @@
 
 
 #ifndef OBSOLETE_LIBGXX
-class BOstream : public ostream {
+class BOstream : public std::ostream {
 #else
 class BOstream : public ofstream {
 #endif
@@ -34,13 +34,13 @@
 	BOstream & operator<< (const void * n)       { ewrite(&n, sizeof(n)); return *this; }
 	
 	int mem_dump(const void * p, int size) {
-		write ((const unsigned char *)p, size);
+		write ((const char *)p, size);
 		return fail();
 	}
 };
 
 #ifndef OBSOLETE_LIBGXX
-class BIstream : public istream {
+class BIstream : public std::istream {
 #else
 class BIstream : public ifstream {
 #endif
@@ -64,12 +64,12 @@
 	BIstream & operator>> (void * & n)             { eread(&n, sizeof(n)); return *this; }
 
 	int mem_undump(void * p, int size) {
-		read ((unsigned char *)p, size);
+		read ((char *)p, size);
 		return fail();
 	}
 };
 
 
 
-#endif Bstream_h
+#endif /* Bstream_h */
 
