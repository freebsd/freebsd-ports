--- src/ps/pdf.cc.orig	Wed Aug 18 23:42:10 2004
+++ src/ps/pdf.cc	Wed Aug 18 23:44:28 2004
@@ -199,10 +199,10 @@
     bytecount write(std::ostream *out, bool binary=true, bytecount offset=0) 
     {
       Part::write(out, binary, offset);
-      std::string str(str());
+      const std::string& s(str());
       if(out)
-	(*out) << str;
-      return offset+str.length();
+	(*out) << s;
+      return offset+s.length();
     }
 
   protected:
