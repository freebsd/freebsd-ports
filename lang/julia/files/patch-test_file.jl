--- test/file.jl.orig	2026-10-25 17:06:47 UTC
+++ test/file.jl
@@ -2040,7 +2040,7 @@ end
                 @test isempty(readdir(join=true))
                 rm(d, recursive=true)
                 @test !ispath(d)
-                @test isempty(readdir())
+                @test_throws Base._UVError("readdir(\".\")", Base.UV_ENOENT) readdir()
                 @test_throws Base._UVError("readdir($(repr(d)))", Base.UV_ENOENT) readdir(d)
                 @test_throws Base._UVError("pwd()", Base.UV_ENOENT) readdir(join=true)
             end
