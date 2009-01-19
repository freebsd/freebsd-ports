--- glom/main.cc.orig	2008-08-22 16:36:46.000000000 +0200
+++ glom/main.cc	2008-09-13 21:23:46.000000000 +0200
@@ -89,18 +89,19 @@
 
 } //namespace Glom
 
-#ifndef G_OS_WIN32
+#ifdef __linux
 extern "C" void __libc_freeres(void);
 #endif
 
 int 
 main(int argc, char* argv[])
 {
-#ifndef G_OS_WIN32
+#ifdef __linux
   //Force some cleanup at exit,
   //to help valgrind to detect memory leaks:
   atexit(__libc_freeres);
 #else
+#  ifdef G_OS_WIN32
   WSADATA data;
   int errcode = WSAStartup(MAKEWORD(2, 0), &data);
   if(errcode != 0)
@@ -108,6 +109,7 @@
     std::cerr << "Failed to initialize WinSock: " << errcode << std::endl;
     return -1;
   }
+#  endif
 #endif
 
   // TODO: I am not sure why, but this does not work. PYTHONPATH is set
