--- stdlib/LibGit2/src/types.jl.orig	2021-12-15 04:07:40 UTC
+++ stdlib/LibGit2/src/types.jl
@@ -230,6 +230,9 @@ Matches the [`git_remote_callbacks`](https://libgit2.o
     push_update_reference::Ptr{Cvoid}  = C_NULL
     push_negotiation::Ptr{Cvoid}       = C_NULL
     transport::Ptr{Cvoid}              = C_NULL
+    @static if LibGit2.VERSION >= v"1.2.0"
+        remote_ready::Ptr{Cvoid}       = C_NULL
+    end
     payload::Any                       = nothing
     @static if LibGit2.VERSION >= v"0.99.0"
         resolve_url::Ptr{Cvoid}        = C_NULL
