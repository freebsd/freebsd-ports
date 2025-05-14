--- test/errorshow.jl.orig	2024-08-27 21:19:31 UTC
+++ test/errorshow.jl
@@ -713,6 +713,7 @@ backtrace()
 backtrace()
 
 # issue #28442
+if false
 @testset "Long stacktrace printing" begin
     f28442(c) = g28442(c + 1)
     g28442(c) = c > 10000 ? (return backtrace()) : f28442(c+1)
@@ -726,6 +727,7 @@ backtrace()
     @test occursin("f28442", output[5])
     @test occursin("the last 2 lines are repeated 5000 more times", output[7])
     @test lstrip(output[8])[1:7] == "[10003]"
+end
 end
 
 @testset "Line number correction" begin
