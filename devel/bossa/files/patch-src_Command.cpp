--- src/Command.cpp.orig	2018-01-15 20:28:09 UTC
+++ src/Command.cpp
@@ -674,7 +674,7 @@ CommandMwb::invoke(char* argv[], int argc)
             char* input = readline("? ");
             if (!input)
                 return;
-            if (input == '\0' ||
+            if (*input == '\0' ||
                 !argUint32(input, &value))
             {
                 free(input);
@@ -777,7 +777,7 @@ CommandMww::invoke(char* argv[], int argc)
             char* input = readline("? ");
             if (!input)
                 return;
-            if (input == '\0' ||
+            if (*input == '\0' ||
                 !argUint32(input, &value))
             {
                 free(input);
