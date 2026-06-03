--- src/pcem/vid_voodoo_codegen_x86.h.orig	2026-04-25 16:24:20 UTC
+++ src/pcem/vid_voodoo_codegen_x86.h
@@ -5,7 +5,7 @@
   fbzColorPath
 */
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
@@ -16,6 +16,7 @@
 #endif
 
 #include <xmmintrin.h>
+#include <emmintrin.h>
 
 #define BLOCK_NUM 8
 #define BLOCK_MASK (BLOCK_NUM-1)
@@ -85,6 +86,23 @@ static uint32_t i_00_ff_w[2] = {0, 0xff};
 static __m128i xmm_00_ff_w[2];
 static uint32_t i_00_ff_w[2] = {0, 0xff};
 
+static inline __m128i voodoo_set_epi32_u32(uint32_t e3, uint32_t e2, uint32_t e1, uint32_t e0)
+{
+#if defined(__FreeBSD__) && defined(__i386__)
+        union {
+                __m128i v;
+                uint32_t u[4];
+        } value = {};
+        value.u[0] = e0;
+        value.u[1] = e1;
+        value.u[2] = e2;
+        value.u[3] = e3;
+        return value.v;
+#else
+        return _mm_set_epi32(static_cast<int>(e3), static_cast<int>(e2), static_cast<int>(e1), static_cast<int>(e0));
+#endif
+}
+
 static inline int codegen_texture_fetch(uint8_t *code_block, voodoo_t *voodoo, voodoo_params_t *params, voodoo_state_t *state, int block_pos, int tmu)
 {
         if (params->textureMode[tmu] & 1)
@@ -674,10 +692,10 @@ static inline void voodoo_generate(uint8_t *code_block
 //        xmm_01_w = (__m128i)0x0001000100010001ull;
 //        xmm_ff_w = (__m128i)0x00ff00ff00ff00ffull;
 //        xmm_ff_b = (__m128i)0x00000000ffffffffull;
-        xmm_01_w = _mm_set_epi32(0, 0, 0x00010001, 0x00010001);
-        xmm_ff_w = _mm_set_epi32(0, 0, 0x00ff00ff, 0x00ff00ff);
-        xmm_ff_b = _mm_set_epi32(0, 0, 0, 0x00ffffff);
-        minus_254 = _mm_set_epi32(0, 0, 0xff02ff02, 0xff02ff02);
+        xmm_01_w = voodoo_set_epi32_u32(0, 0, 0x00010001u, 0x00010001u);
+        xmm_ff_w = voodoo_set_epi32_u32(0, 0, 0x00ff00ffu, 0x00ff00ffu);
+        xmm_ff_b = voodoo_set_epi32_u32(0, 0, 0, 0x00ffffffu);
+        minus_254 = voodoo_set_epi32_u32(0, 0, 0xff02ff02u, 0xff02ff02u);
 //        *(uint64_t *)&const_1_48 = 0x45b0000000000000ull;
 //        block_pos = 0;
 //        voodoo_get_depth = &code_block[block_pos];
@@ -3386,20 +3404,20 @@ void voodoo_codegen_init(voodoo_t *voodoo)
                 int _ds = c & 0xf;
                 int dt = c >> 4;
                 
-                alookup[c] = _mm_set_epi32(0, 0, c | (c << 16), c | (c << 16));
-                aminuslookup[c] = _mm_set_epi32(0, 0, (255-c) | ((255-c) << 16), (255-c) | ((255-c) << 16));
+                alookup[c] = voodoo_set_epi32_u32(0, 0, static_cast<uint32_t>(c | (c << 16)), static_cast<uint32_t>(c | (c << 16)));
+                aminuslookup[c] = voodoo_set_epi32_u32(0, 0, static_cast<uint32_t>((255-c) | ((255-c) << 16)), static_cast<uint32_t>((255-c) | ((255-c) << 16)));
 
                 d[0] = (16 - _ds) * (16 - dt);
                 d[1] =  _ds * (16 - dt);
                 d[2] = (16 - _ds) * dt;
                 d[3] = _ds * dt;
 
-                bilinear_lookup[c*2]     = _mm_set_epi32(d[1] | (d[1] << 16), d[1] | (d[1] << 16), d[0] | (d[0] << 16), d[0] | (d[0] << 16));
-                bilinear_lookup[c*2 + 1] = _mm_set_epi32(d[3] | (d[3] << 16), d[3] | (d[3] << 16), d[2] | (d[2] << 16), d[2] | (d[2] << 16));
+                bilinear_lookup[c*2]     = voodoo_set_epi32_u32(static_cast<uint32_t>(d[1] | (d[1] << 16)), static_cast<uint32_t>(d[1] | (d[1] << 16)), static_cast<uint32_t>(d[0] | (d[0] << 16)), static_cast<uint32_t>(d[0] | (d[0] << 16)));
+                bilinear_lookup[c*2 + 1] = voodoo_set_epi32_u32(static_cast<uint32_t>(d[3] | (d[3] << 16)), static_cast<uint32_t>(d[3] | (d[3] << 16)), static_cast<uint32_t>(d[2] | (d[2] << 16)), static_cast<uint32_t>(d[2] | (d[2] << 16)));
         }
-        alookup[256] = _mm_set_epi32(0, 0, 256 | (256 << 16), 256 | (256 << 16));
-        xmm_00_ff_w[0] = _mm_set_epi32(0, 0, 0, 0);
-        xmm_00_ff_w[1] = _mm_set_epi32(0, 0, 0xff | (0xff << 16), 0xff | (0xff << 16));
+        alookup[256] = voodoo_set_epi32_u32(0, 0, 256u | (256u << 16), 256u | (256u << 16));
+        xmm_00_ff_w[0] = voodoo_set_epi32_u32(0, 0, 0, 0);
+        xmm_00_ff_w[1] = voodoo_set_epi32_u32(0, 0, 0xffu | (0xffu << 16), 0xffu | (0xffu << 16));
 }
 
 void voodoo_codegen_close(voodoo_t *voodoo)
