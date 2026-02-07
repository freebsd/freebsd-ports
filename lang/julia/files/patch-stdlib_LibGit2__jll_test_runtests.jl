--- stdlib/LibGit2_jll/test/runtests.jl.orig	2024-08-27 21:19:31 UTC
+++ stdlib/LibGit2_jll/test/runtests.jl
@@ -7,5 +7,6 @@ using Test, Libdl, LibGit2_jll
     minor = Ref{Cint}(0)
     patch = Ref{Cint}(0)
     @test ccall((:git_libgit2_version, libgit2), Cint, (Ref{Cint}, Ref{Cint}, Ref{Cint}), major, minor, patch) == 0
-    @test VersionNumber(major[], minor[], patch[]) == v"1.6.4"
+    # Do not check version number. It changes.
+    # @test VersionNumber(major[], minor[], patch[]) == v"1.6.4"
 end
