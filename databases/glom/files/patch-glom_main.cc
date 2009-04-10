--- glom/main.cc.orig	2009-03-16 14:53:55.000000000 +0100
+++ glom/main.cc	2009-03-17 16:22:01.000000000 +0100
@@ -100,18 +100,19 @@ OptionGroup::OptionGroup()
 
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
@@ -123,6 +124,7 @@ main(int argc, char* argv[])
   gchar* installation_dir_c = g_win32_get_package_installation_directory_of_module(NULL);
   const std::string installation_dir(installation_dir_c);
   g_free(installation_dir_c);
+#  endif
 #endif
 
   // TODO: I am not sure why, but this does not work. PYTHONPATH is set
