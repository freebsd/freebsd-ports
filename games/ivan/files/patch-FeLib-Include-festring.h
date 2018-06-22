--- FeLib/Include/festring.h.orig	2004-10-26 19:35:44 UTC
+++ FeLib/Include/festring.h
@@ -142,7 +142,7 @@ inline festring::festring(const festring
 inline festring::festring(sizetype N)
 : Size(N), OwnsData(true), Reserved(N|FESTRING_PAGE)
 {
-  char* Ptr = 4 + new char[Reserved + 5];
+  char* Ptr = sizeof(ulong) + new char[Reserved + 5];
   REFS(Ptr) = 0;
   Data = Ptr;
 }
@@ -150,7 +150,7 @@ inline festring::festring(sizetype N)
 inline festring::festring(sizetype N, char C)
 : Size(N), OwnsData(true), Reserved(N|FESTRING_PAGE)
 {
-  char* Ptr = 4 + new char[Reserved + 5];
+  char* Ptr = sizeof(ulong) + new char[Reserved + 5];
   REFS(Ptr) = 0;
   Data = Ptr;
   memset(Ptr, C, N);
