--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Texts.c	Tue Feb 15 14:27:03 1994
+++ ./reuse/m2c/Texts.c	Thu Aug  5 18:49:34 2004
@@ -46,7 +46,7 @@
 Strings_tString *String;
 # endif
 {
-  Lists_Append(Text, (ADDRESS)StringMem_PutString(String));
+  Lists_Append(Text, (Lists_tElmt)StringMem_PutString(String));
 }
 
 void Texts_Insert
@@ -58,7 +58,7 @@
 Strings_tString *String;
 # endif
 {
-  Lists_Insert(Text, (ADDRESS)StringMem_PutString(String));
+  Lists_Insert(Text, (Lists_tElmt)StringMem_PutString(String));
 }
 
 BOOLEAN Texts_IsEmpty
@@ -84,7 +84,7 @@
   Strings_tString String;
 
   while (!Lists_IsEmpty(Text)) {
-    StringMem_GetString((StringMem_tStringRef)Lists_Head(Text), &String);
+    StringMem_GetString((StringMem_tStringRef)Lists_Head((Lists_tList)Text), &String);
     Strings_WriteL(f, &String);
     Lists_Tail(&Text);
   }
