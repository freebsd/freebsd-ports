--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Idents.c	Tue Feb 15 14:26:53 1994
+++ ./reuse/m2c/Idents.c	Thu Aug  5 18:49:33 2004
@@ -47,7 +47,7 @@
 static struct S_3 {
     Idents_tIdent A[HashTableSize + 1];
 } HashTable;
-static HashIndex i;
+static HashIndex hi;
 
 Idents_tIdent Idents_MakeIdent
 # ifdef __STDC__
@@ -218,8 +218,8 @@
 {
   Strings_tString String;
 
-  for (i = 0; i <= HashTableSize; i += 1) {
-    HashTable.A[i] = cNoIdent;
+  for (hi = 0; hi <= HashTableSize; hi += 1) {
+    HashTable.A[hi] = cNoIdent;
   }
   IdentCount = 0;
   Strings_AssignEmpty(&String);
