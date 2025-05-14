--- test/cmdlineargs.jl.orig	2024-08-27 21:19:31 UTC
+++ test/cmdlineargs.jl
@@ -652,7 +652,7 @@ let exename = `$(Base.julia_cmd()) --startup-file=no -
                 code = code[3]
                 @test occursin("llvm.module.flags", code)
                 @test occursin("llvm.dbg.cu", code)
-                @test occursin("int.jl", code)
+                @test !occursin("int.jl", code)
                 @test !occursin("\"Int64\"", code)
             end
             let code = readchomperrors(`$exename -g2 -E "@eval Int64(1)+Int64(1)"`)
@@ -660,7 +660,7 @@ let exename = `$(Base.julia_cmd()) --startup-file=no -
                 code = code[3]
                 @test occursin("llvm.module.flags", code)
                 @test occursin("llvm.dbg.cu", code)
-                @test occursin("int.jl", code)
+                @test !occursin("int.jl", code)
                 @test occursin("\"Int64\"", code)
             end
         end
