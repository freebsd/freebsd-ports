--- src/Utils/Tagging/MP4/PopularimeterFrame.cpp.orig	2024-04-01 19:55:44 UTC
+++ src/Utils/Tagging/MP4/PopularimeterFrame.cpp
@@ -28,7 +28,7 @@ namespace
 {
 	[[nodiscard]] int fourBytesToInteger(const int32_t fourBytes)
 	{
-		const auto chars = std::array {
+		const auto chars = std::array<int32_t,3> {
 			(fourBytes >> 16) & 0xFF,
 			(fourBytes >> 8) & 0xFF,
 			(fourBytes & 0xFF)
