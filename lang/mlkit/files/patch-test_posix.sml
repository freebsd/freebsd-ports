--- test/posix.sml.orig	2023-04-26 17:24:37 UTC
+++ test/posix.sml
@@ -48,6 +48,6 @@ fun lookup s a =
 val _ = tst' "Posix.uname" (fn () =>
 			       let val a = Posix.ProcEnv.uname()
 			       in case lookup "sysname" a of
-				      SOME s => s = "Linux" orelse s = "Darwin"
+				      SOME s => s = "Linux" orelse s = "Darwin" orelse s = "FreeBSD"
 				    | NONE => false
 			       end)
