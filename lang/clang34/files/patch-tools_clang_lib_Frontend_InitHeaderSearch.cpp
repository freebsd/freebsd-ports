Look for the libc++ headers in base, and afterwards look if they might
have been installed in ports. This is only usefull on FreeBSD <= 9.x since
libc++ is shipped in 10 by default. No path to the library of libc++ is
provided. The port wanting to use libc++ need to provide its own LDFLAGS.

--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	2013-06-21 20:35:23.000000000 +0200
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp	2013-06-21 20:41:38.000000000 +0200
@@ -486,6 +486,7 @@ void InitHeaderSearch::AddDefaultInclude
         AddPath("/usr/include/c++/v1/support/solaris", CXXSystem, false);
       
       AddPath("/usr/include/c++/v1", CXXSystem, false);
+      AddPath("/usr/local/include/c++/v1", CXXSystem, false);
     } else {
       AddDefaultCPlusPlusIncludePaths(triple, HSOpts);
     }
