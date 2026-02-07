--- dns-terror/BoolString.h.orig	2003-05-17 17:58:52 UTC
+++ dns-terror/BoolString.h
@@ -56,6 +56,7 @@ public:
   BoolString &operator=(const BoolString &other) {
     str = other.str;
     flag = other.flag;
+    return *this;
   }
   int operator<(const BoolString &other) const {
     return strcmp(str, other.str) < 0;
