--- test/file.jl.orig	2024-08-27 21:19:31 UTC
+++ test/file.jl
@@ -1628,7 +1628,7 @@ end
                 @test isempty(readdir(join=true))
                 rm(d, recursive=true)
                 @test !ispath(d)
-                @test isempty(readdir())
+                @test_throws Base._UVError("readdir(\".\")", Base.UV_ENOENT) readdir()
                 @test_throws Base._UVError("readdir($(repr(d)))", Base.UV_ENOENT) readdir(d)
                 @test_throws Base._UVError("pwd()", Base.UV_ENOENT) readdir(join=true)
             end
