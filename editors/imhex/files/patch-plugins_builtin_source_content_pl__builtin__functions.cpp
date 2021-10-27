--- plugins/builtin/source/content/pl_builtin_functions.cpp.orig	2021-09-30 10:52:12 UTC
+++ plugins/builtin/source/content/pl_builtin_functions.cpp
@@ -192,7 +192,7 @@ namespace hex::plugin::builtin {
                 auto string = Token::literalToString(params[0], false);
                 auto index = Token::literalToSigned(params[1]);
 
-                if (std::abs(index) >= string.length())
+                if (std::abs((long)index) >= string.length())
                     LogConsole::abortEvaluation("character index out of range");
 
                 if (index >= 0)
