--- rts/Rendering/Shaders/ShaderStates.h.orig	2013-12-06 06:06:48.795486079 +0400
+++ rts/Rendering/Shaders/ShaderStates.h	2013-12-06 06:30:20.577430223 +0400
@@ -227,7 +227,7 @@
 		{
 			std::map<std::string, std::string>::const_iterator it = flags.find(flag);
 			if (it != flags.end()) {
-				std::istringstream buf(*it);
+				std::istringstream buf(it->second);
 				T temp;
 				buf >> temp;
 				return temp;
