--- include/tv/fpbase.h.orig	Wed Oct 10 02:06:00 2001
+++ include/tv/fpbase.h	Fri Jun  7 04:35:14 2002
@@ -28,6 +33,23 @@
 #if defined( Uses_fpbase ) && !defined( __fpbase )
 #define __fpbase
 
+#ifdef CLY_DefineSpecialFileBuf
+class CLY_filebuf: public std::filebuf
+{
+public:
+ CLY_filebuf() : std::filebuf() {};
+ CLY_filebuf(FILE *f, std::ios_base::openmode mode)
+   { open(f,mode); };
+ CLY_filebuf(int h, std::ios_base::openmode mode)
+   { open(h,mode); };
+
+ CLY_filebuf *open(FILE *f, std::ios_base::openmode);
+ CLY_filebuf *open(int h, std::ios_base::openmode);
+ std::filebuf *open(const char *file, std::ios_base::openmode mode)
+   { return std::filebuf::open(file,mode); };
+};
+#endif
+
 class fpbase : virtual public pstream
 {
 
@@ -49,7 +71,7 @@
 
 private:
 
-    CLY_std(filebuf) *buf;
+    CLY_filebuf *buf;
 
 };
 
