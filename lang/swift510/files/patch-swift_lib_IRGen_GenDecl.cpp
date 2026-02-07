--- swift/lib/IRGen/GenDecl.cpp.orig	2024-06-06 04:26:30 UTC
+++ swift/lib/IRGen/GenDecl.cpp
@@ -486,6 +486,8 @@ void IRGenModule::emitSourceFile(SourceFile &SF) {
       this->addLinkLibrary(LinkLibrary("c++", LibraryKind::Library));
     else if (target.isOSLinux())
       this->addLinkLibrary(LinkLibrary("stdc++", LibraryKind::Library));
+    else if (target.isOSFreeBSD())
+      this->addLinkLibrary(LinkLibrary("c++", LibraryKind::Library));
 
     // Do not try to link Cxx with itself.
     if (!getSwiftModule()->getName().is("Cxx")) {
@@ -509,6 +511,10 @@ void IRGenModule::emitSourceFile(SourceFile &SF) {
       case llvm::Triple::Linux:
         if (!target.isAndroid())
           this->addLinkLibrary(LinkLibrary("swiftCxxStdlib",
+                                           LibraryKind::Library));
+        break;
+      case llvm::Triple::FreeBSD:
+        this->addLinkLibrary(LinkLibrary("swiftCxxStdlib",
                                            LibraryKind::Library));
         break;
       case llvm::Triple::Win32: {
