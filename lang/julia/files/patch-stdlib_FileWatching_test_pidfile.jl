--- stdlib/FileWatching/test/pidfile.jl.orig	2023-12-03 21:24:39 UTC
+++ stdlib/FileWatching/test/pidfile.jl
@@ -41,7 +41,8 @@ try
     @test isvalidpid("NOT" * gethostname(), 0 % Cuint)
     @test isvalidpid("NOT" * gethostname(), -1 % Cuint)
     if !iswindows()
-        @test isvalidpid("", 1 % Cuint)
+        # we cannot see pid 1 in a jail
+        # @test isvalidpid("", 1 % Cuint)
         @test !isvalidpid("", -1 % Cuint)
         @test !isvalidpid("", -mypid)
     end
