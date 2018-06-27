--- lib/hipe/llvm/hipe_llvm_main.erl.orig	2015-06-27 20:52:09 UTC
+++ lib/hipe/llvm/hipe_llvm_main.erl
@@ -474,7 +474,7 @@ unique_folder(FunName, Arity, Options) -
       true ->  %% Store folder in current directory
         DirName;
       false -> %% Temporarily store folder in tempfs (/dev/shm/)
-        "/dev/shm/" ++ DirName
+        "/tmp/" ++ DirName
     end,
   %% Make sure it does not exist
   case dir_exists(Dir) of
