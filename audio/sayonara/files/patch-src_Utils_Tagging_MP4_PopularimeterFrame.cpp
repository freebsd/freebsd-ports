--- src/Utils/Tagging/MP4/PopularimeterFrame.cpp.orig	2024-01-27 22:05:38 UTC
+++ src/Utils/Tagging/MP4/PopularimeterFrame.cpp
@@ -22,13 +22,14 @@
 #include <QString>
 #include "Tagging/TaggingUtils.h"
 
+#include <array>
 #include <optional>
 
 namespace
 {
 	[[nodiscard]] int fourBytesToInteger(const int32_t fourBytes)
 	{
-		const auto chars = std::array {
+		const auto chars = std::array<int32_t,3> {
 			(fourBytes >> 16) & 0xFF,
 			(fourBytes >> 8) & 0xFF,
 			(fourBytes & 0xFF)
