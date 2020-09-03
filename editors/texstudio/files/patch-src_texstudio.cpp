--- src/texstudio.cpp.orig	2020-09-03 02:38:42 UTC
+++ src/texstudio.cpp
@@ -3600,7 +3600,7 @@ void Texstudio::editEraseWordCmdEnv()
 
 	switch (tk.type) {
     case Token::commandUnknown:
-        [[gnu::fallthrough]]
+        [[gnu::fallthrough]];
 	case Token::command:
 		command = tk.getText();
 		if (command == "\\begin" || command == "\\end") {
