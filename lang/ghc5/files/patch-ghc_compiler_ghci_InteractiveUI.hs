--- ghc/compiler/ghci/InteractiveUI.hs.orig	Tue May 24 23:10:08 2005
+++ ghc/compiler/ghci/InteractiveUI.hs	Tue May 24 23:11:37 2005
@@ -80,12 +80,12 @@ import GHC.Posix	( setNonBlockingFD )
 
 -----------------------------------------------------------------------------
 
-ghciWelcomeMsg = "\ 
-\   ___         ___ _\n\ 
-\  / _ \\ /\\  /\\/ __(_)\n\ 
-\ / /_\\// /_/ / /  | |      GHC Interactive, version " ++ cProjectVersion ++ ", for Haskell 98.\n\ 
-\/ /_\\\\/ __  / /___| |      http://www.haskell.org/ghc/\n\ 
-\\\____/\\/ /_/\\____/|_|      Type :? for help.\n"
+ghciWelcomeMsg = ""++
+ "   ___         ___ _\n"++
+ "  / _ \\ /\\  /\\/ __(_)\n"++
+ " / /_\\// /_/ / /  | |      GHC Interactive, version " ++ cProjectVersion ++ ", for Haskell 98.\n"++
+ "/ /_\\\\/ __  / /___| |      http://www.haskell.org/ghc/\n"++
+ "\\____/\\/ /_/\\____/|_|      Type :? for help.\n"
 
 GLOBAL_VAR(commands, builtin_commands, [(String, String -> GHCi Bool)])
 
@@ -118,41 +118,41 @@ keepGoingPaths a str = a (toArgs str) >>
 shortHelpText = "use :? for help.\n"
 
 -- NOTE: spaces at the end of each line to workaround CPP/string gap bug.
-helpText = "\ 
-\ Commands available from the prompt:\n\ 
-\\n\ 
-\   <stmt>		       evaluate/run <stmt>\n\ 
-\   :add <filename> ...        add module(s) to the current target set\n\ 
-\   :browse [*]<module>	       display the names defined by <module>\n\ 
-\   :cd <dir>		       change directory to <dir>\n\ 
-\   :def <cmd> <expr>          define a command :<cmd>\n\ 
-\   :help, :?		       display this list of commands\n\ 
-\   :info [<name> ...]         display information about the given names\n\ 
-\   :load <filename> ...       load module(s) and their dependents\n\ 
-\   :module [+/-] [*]<mod> ... set the context for expression evaluation\n\ 
-\   :reload		       reload the current module set\n\ 
-\\n\ 
-\   :set <option> ...	       set options\n\ 
-\   :set args <arg> ...	       set the arguments returned by System.getArgs\n\ 
-\   :set prog <progname>       set the value returned by System.getProgName\n\ 
-\\n\ 
-\   :show modules	       show the currently loaded modules\n\ 
-\   :show bindings	       show the current bindings made at the prompt\n\ 
-\\n\ 
-\   :type <expr>	       show the type of <expr>\n\ 
-\   :undef <cmd> 	       undefine user-defined command :<cmd>\n\ 
-\   :unset <option> ...	       unset options\n\ 
-\   :quit		       exit GHCi\n\ 
-\   :!<command>		       run the shell command <command>\n\ 
-\\n\ 
-\ Options for `:set' and `:unset':\n\ 
-\\n\ 
-\    +r			revert top-level expressions after each evaluation\n\ 
-\    +s                 print timing/memory stats after each evaluation\n\ 
-\    +t			print type after evaluation\n\ 
-\    -<flags>		most GHC command line flags can also be set here\n\ 
-\                         (eg. -v2, -fglasgow-exts, etc.)\n\ 
-\"
+helpText = ( ""++
+ " Commands available from the prompt:\n"++
+ "\n"++
+ "   <stmt>		       evaluate/run <stmt>\n"++
+ "   :add <filename> ...        add module(s) to the current target set\n"++
+ "   :browse [*]<module>	       display the names defined by <module>\n"++
+ "   :cd <dir>		       change directory to <dir>\n"++
+ "   :def <cmd> <expr>          define a command :<cmd>\n"++
+ "   :help, :?		       display this list of commands\n"++
+ "   :info [<name> ...]         display information about the given names\n"++
+ "   :load <filename> ...       load module(s) and their dependents\n"++
+ "   :module [+/-] [*]<mod> ... set the context for expression evaluation\n"++
+ "   :reload		       reload the current module set\n"++
+ "\n"++
+ "   :set <option> ...	       set options\n"++
+ "   :set args <arg> ...	       set the arguments returned by System.getArgs\n"++
+ "   :set prog <progname>       set the value returned by System.getProgName\n"++
+ "\n"++
+ "   :show modules	       show the currently loaded modules\n"++
+ "   :show bindings	       show the current bindings made at the prompt\n"++
+ "\n"++
+ "   :type <expr>	       show the type of <expr>\n"++
+ "   :undef <cmd> 	       undefine user-defined command :<cmd>\n"++
+ "   :unset <option> ...	       unset options\n"++
+ "   :quit		       exit GHCi\n"++
+ "   :!<command>		       run the shell command <command>\n"++
+ "\n"++
+ " Options for `:set' and `:unset':\n"++
+ "\n"++
+ "    +r			revert top-level expressions after each evaluation\n"++
+ "    +s                 print timing/memory stats after each evaluation\n"++
+ "    +t			print type after evaluation\n"++
+ "    -<flags>		most GHC command line flags can also be set here\n"++
+ "                         (eg. -v2, -fglasgow-exts, etc.)\n"++
+ "" )
 
 interactiveUI :: CmState -> [FilePath] -> [LibrarySpec] -> IO ()
 interactiveUI cmstate paths cmdline_libs = do
