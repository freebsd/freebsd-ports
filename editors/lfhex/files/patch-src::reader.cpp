--- src/reader.cpp.orig	Fri Jul  6 10:40:46 2001
+++ src/reader.cpp	Fri Jul  6 10:40:58 2001
@@ -283,7 +283,7 @@
 #ifdef __GNUC__
 ostream& operator<< (ostream&out, const ReadBuffer& buff)
 {
-  ios_base::fmtflags old_flags = out.flags();
+  ios::fmtflags old_flags = out.flags();
   out.flags(old_flags | ios::hex | ios::showbase);
   for(size_t i = 0; i < buff.size(); i++)
     out << buff[i];
