--- llvm/clang/lib/Lex/Pragma.cpp.orig	2025-02-07 08:51:59 UTC
+++ llvm/clang/lib/Lex/Pragma.cpp
@@ -934,9 +934,11 @@ void Preprocessor::AddPragmaHandler(StringRef Namespac
   }
 
   // Check to make sure we don't already have a pragma for this identifier.
-  assert(!InsertNS->FindHandler(Handler->getName()) &&
-         "Pragma handler already exists for this identifier!");
-  InsertNS->AddPragma(Handler);
+  // assert(!InsertNS->FindHandler(Handler->getName()) &&
+  //        "Pragma handler already exists for this identifier!");
+
+  if (!InsertNS->FindHandler(Handler->getName()))
+     InsertNS->AddPragma(Handler);
 }
 
 /// RemovePragmaHandler - Remove the specific pragma handler from the
@@ -950,12 +952,15 @@ void Preprocessor::RemovePragmaHandler(StringRef Names
   // If this is specified to be in a namespace, step down into it.
   if (!Namespace.empty()) {
     PragmaHandler *Existing = PragmaHandlers->FindHandler(Namespace);
+    if (!Existing)
+      return;
     assert(Existing && "Namespace containing handler does not exist!");
 
     NS = Existing->getIfNamespace();
     assert(NS && "Invalid namespace, registered as a regular pragma handler!");
   }
 
+  if (NS->FindHandler(Handler->getName()))
   NS->RemovePragmaHandler(Handler);
 
   // If this is a non-default namespace and it is now empty, remove it.
