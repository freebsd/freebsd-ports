--- md5.h.orig	2008-05-06 13:24:40.000000000 +0200
+++ md5.h	2008-05-06 13:24:58.000000000 +0200
@@ -38,11 +38,8 @@
 class MD5Hash
 {
 public:
-  // removed this to stop GCC warnings about using the 'pack' attribute on
-  // non-POD members in classes such as PACKET_HEADER:
-
   // Constructor does not initialise the value
-  //MD5Hash(void) {};
+  MD5Hash(void) {};
 
   // Comparison operators
   bool operator==(const MD5Hash &other) const;
@@ -57,12 +54,9 @@
   friend ostream& operator<<(ostream &s, const MD5Hash &hash);
   string print(void) const;
 
-  // removed these to stop GCC warnings about using the 'pack' attribute on
-  // non-POD members in classes such as PACKET_HEADER:
-
   // Copy and assignment
-  //MD5Hash(const MD5Hash &other);
-  //MD5Hash& operator=(const MD5Hash &other);
+  MD5Hash(const MD5Hash &other);
+  MD5Hash& operator=(const MD5Hash &other);
 
 public:
   u8 hash[16]; // 16 byte MD5 Hash value
@@ -150,7 +144,7 @@
   return !other.operator<(*this);
 }
 
-/*inline MD5Hash::MD5Hash(const MD5Hash &other)
+inline MD5Hash::MD5Hash(const MD5Hash &other)
 {
   memcpy(&hash, &other.hash, sizeof(hash));
 }
@@ -160,6 +154,6 @@
   memcpy(&hash, &other.hash, sizeof(hash));
 
   return *this;
-}*/
+}
 
 #endif // __MD5_H__
