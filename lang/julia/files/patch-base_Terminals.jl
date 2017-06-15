--- base/Terminals.jl.orig	2017-02-19 14:49:03 UTC
+++ base/Terminals.jl
@@ -156,7 +156,7 @@ else
     function hascolor(t::TTYTerminal)
         startswith(t.term_type, "xterm") && return true
         try
-            return success(`tput setaf 0`)
+            return success(`tput AF 0`)
         catch
             return false
         end
