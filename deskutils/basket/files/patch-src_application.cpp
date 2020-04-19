--- src/application.cpp.orig	2018-12-05 17:27:24 UTC
+++ src/application.cpp
@@ -56,7 +56,7 @@ Application::Application(int &argc, char **argv)
 
 
     #ifdef WITH_LIBGIT2
-        #if LIBGIT2_SOVERSION >= 22
+        #if LIBGIT2_VER_MAJOR >= 1
             git_libgit2_init();
         #else
             git_threads_init();
@@ -67,7 +67,7 @@ Application::Application(int &argc, char **argv)
 Application::~Application()
 {
     #ifdef WITH_LIBGIT2
-        #if LIBGIT2_SOVERSION >= 22
+        #if LIBGIT2_VER_MAJOR >= 1
             git_libgit2_shutdown();
         #else
             git_threads_shutdown();
