
$FreeBSD$

--- src/symbol.cc.orig	Mon Aug 23 16:45:53 2004
+++ src/symbol.cc	Mon Aug 23 16:46:02 2004
@@ -140,7 +140,7 @@
 
   // Allocate mew symbol-table
 
-  if(size && (symtab = new (symbolTableEntry*)[size]))
+  if(size && (symtab = new symbolTableEntry*[size]))
   {
     // Clear hash-table
 
