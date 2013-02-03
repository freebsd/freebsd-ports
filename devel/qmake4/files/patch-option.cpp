--- ./option.cpp.orig	2012-09-11 01:36:36.000000000 +0000
+++ ./option.cpp	2012-10-27 21:51:28.131151563 +0000
@@ -482,7 +482,7 @@
                     env_argc++;
                 }
             } else {
-                if(!env_argv || env_argc > env_size) {
+                if(!env_argv || env_argc >= env_size) {
                     env_argv = (char **)realloc(env_argv, sizeof(char *)*(env_size+=10));
                     for(int i2 = env_argc; i2 < env_size; i2++)
                         env_argv[i2] = NULL;
