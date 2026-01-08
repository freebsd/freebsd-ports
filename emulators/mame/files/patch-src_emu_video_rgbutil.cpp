--- src/emu/video/rgbutil.cpp.orig	2026-01-08 15:01:14 UTC
+++ src/emu/video/rgbutil.cpp
@@ -362,7 +362,7 @@ const VECS16 scale_table[256] =
 
 } // anonymous namespace
 
-u32 rgbaint_t::bilinear_filter(const u32 &rgb00, const u32 &rgb01, const u32 &rgb10, const u32 &rgb11, u8 u, u8 v)
+u32 rgbaint_t::bilinear_filter(u32 rgb00, u32 rgb01, u32 rgb10, u32 rgb11, u8 u, u8 v) noexcept
 {
 	const VECS32 zero = vec_splat_s32(0);
 
@@ -405,7 +405,7 @@ u32 rgbaint_t::bilinear_filter(const u32 &rgb00, const
 	return result;
 }
 
-void rgbaint_t::bilinear_filter_rgbaint(const u32 &rgb00, const u32 &rgb01, const u32 &rgb10, const u32 &rgb11, u8 u, u8 v)
+void rgbaint_t::bilinear_filter_rgbaint(u32 rgb00, u32 rgb01, u32 rgb10, u32 rgb11, u8 u, u8 v) noexcept
 {
 	const VECS32 zero = vec_splat_s32(0);
 
@@ -439,6 +439,7 @@ void rgbaint_t::bilinear_filter_rgbaint(const u32 &rgb
 	color11 = vec_sr(color11, vec_splat_u32(1));
 	color01 = VECS32(vec_max(VECS16(color01), VECS16(color11)));
 	color01 = vec_msum(VECS16(color01), scale_table[v], zero);
+	color01 = vec_sr(color01, vec_splat_u32(15));
 
 #ifdef __LITTLE_ENDIAN__
 	vec_ste(vec_splat(color01, 3), 0, &m_a);
