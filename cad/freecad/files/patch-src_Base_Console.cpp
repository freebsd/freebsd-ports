--- src/Base/Console.cpp.orig	2017-06-16 13:04:23 UTC
+++ src/Base/Console.cpp
@@ -714,7 +714,7 @@ void ConsoleObserverFile::Log    (const 
 ConsoleObserverStd::ConsoleObserverStd() :
 #   if defined(FC_OS_WIN32)
     useColorStderr( true )
-#   elif defined(FC_OS_LINUX) || defined(FC_OS_MACOSX)
+#   else
     useColorStderr( isatty(STDERR_FILENO) )
 #   endif
 {
