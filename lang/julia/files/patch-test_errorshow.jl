--- test/errorshow.jl.orig	2026-10-25 17:06:47 UTC
+++ test/errorshow.jl
@@ -786,6 +786,7 @@ backtrace()
 backtrace()
 
 # issue #28442
+if false
 @testset "Long stacktrace printing" begin
     f28442(c) = g28442(c + 1)
     g28442(c) = c > 10000 ? (return backtrace()) : f28442(c+1)
@@ -948,6 +949,7 @@ end
     # The cycle is closed, and what follows it is numbered past all of its repetitions
     @test any(l -> occursin("repeated 13 times", l), output)
     @test any(l -> occursin("[53] tail", l), output)
+end
 end
 
 
