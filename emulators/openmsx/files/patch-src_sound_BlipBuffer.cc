--- src/sound/BlipBuffer.cc.orig	2025-09-10 16:08:17 UTC
+++ src/sound/BlipBuffer.cc
@@ -19,7 +19,7 @@ static constexpr int BLIP_RES = 1 << BlipBuffer::BLIP_
 
 
 // Precalculated impulse table.
-static constexpr auto impulses = [] {
+static const auto impulses = [] {
 	constexpr int HALF_SIZE = BLIP_RES / 2 * (BLIP_IMPULSE_WIDTH - 1);
 	std::array<double, BLIP_RES + HALF_SIZE + BLIP_RES> fImpulse = {};
 	std::span<double, HALF_SIZE> out = subspan<HALF_SIZE>(fImpulse, BLIP_RES);
