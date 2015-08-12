--- src/bindings.cpp.orig	2015-07-05 02:18:34 UTC
+++ src/bindings.cpp
@@ -108,7 +108,7 @@ Actions::BaseAction *parseActionLine(con
 			// push single character into input queue
 			std::string arg = getEnclosedString(line, '"', '"', 0);
 			Key k = stringToSpecialKey(arg);
-			auto queue = std::vector<int>{ k.getChar() };
+			auto queue = std::vector<int>{ (int)k.getChar() };
 			if (k != Key::noOp)
 				result = new Actions::PushCharacters(&Global::wFooter, std::move(queue));
 			else
