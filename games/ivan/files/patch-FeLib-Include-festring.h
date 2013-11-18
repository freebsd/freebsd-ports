--- FeLib/Include/festring.h.orig	2004-10-26 23:35:44.000000000 +0400
+++ FeLib/Include/festring.h	2013-11-08 16:54:09.080772415 +0400
@@ -142,7 +142,7 @@
 inline festring::festring(sizetype N)
 : Size(N), OwnsData(true), Reserved(N|FESTRING_PAGE)
 {
-  char* Ptr = 4 + new char[Reserved + 5];
+  char* Ptr = sizeof(ulong) + new char[Reserved + 5];
   REFS(Ptr) = 0;
   Data = Ptr;
 }
@@ -150,7 +150,7 @@
 inline festring::festring(sizetype N, char C)
 : Size(N), OwnsData(true), Reserved(N|FESTRING_PAGE)
 {
-  char* Ptr = 4 + new char[Reserved + 5];
+  char* Ptr = sizeof(ulong) + new char[Reserved + 5];
   REFS(Ptr) = 0;
   Data = Ptr;
   memset(Ptr, C, N);
