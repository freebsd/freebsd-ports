--- cipher.h.orig	Thu Dec 21 14:26:06 2006
+++ cipher.h	Thu Dec 21 14:26:26 2006
@@ -62,12 +62,12 @@
   MD5Digest dig;
   unsigned char key[32];
   string blah;
-  const char* cipher::error(int num);
+  const char* error(int num);
 
  public:
   cipher() {};
   ~cipher() {};
-  void cipher::init(const string & phrase);
+  void init(const string & phrase);
   string encrypt(const string& source);
   string decrypt(const string& source);
 };
