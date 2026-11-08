--- src/nvtt/icbc.h.orig	2020-08-24 06:27:21 UTC
+++ src/nvtt/icbc.h
@@ -1195,7 +1195,7 @@ union VFloat {
 constexpr int VEC_SIZE = 4;
 
 union VFloat {
-    vectro float v;
+    vector float v;
     float e[4];
     VFloat() {}
     VFloat(vector float v) : v(v) {}
@@ -1221,7 +1221,11 @@ ICBC_FORCEINLINE VFloat vload(const float * ptr) {
 }
 
 ICBC_FORCEINLINE VFloat vload(const float * ptr) {
-    return vec_ld(ptr)
+#if defined(__VSX__)
+    return vec_xl(0, ptr);
+#else
+    return vec_ld(0, ptr);
+#endif
 }
 
 ICBC_FORCEINLINE VFloat operator+(VFloat a, VFloat b) {
@@ -1244,8 +1248,13 @@ ICBC_FORCEINLINE VFloat vrcp(VFloat a) {
     // one round of Newton-Rhaphson refinement
     vector float diff = vec_nmsub( estimate, v.vec, vec_splats( 1.0f ) );
     return vec_madd(diff, estimate, estimate );
+#elif defined(__VSX__)
+    return vec_div(vec_splats(1.0f), a);
 #else
-    return vec_div(vec_splats(1),a);
+    // AltiVec without VSX has no vector float division.
+    VFloat r;
+    for (int i = 0; i < VEC_SIZE; i++) r.e[i] = 1.0f / a.e[i];
+    return r;
 #endif
 }
 
@@ -1255,7 +1264,11 @@ ICBC_FORCEINLINE VFloat vmsub(VFloat a, VFloat b, VFlo
 }
 
 ICBC_FORCEINLINE VFloat vmsub(VFloat a, VFloat b, VFloat c) {
+#if defined(__VSX__)
     return vec_msub(a, b, c); // @@ Is this right?
+#else
+    return vec_madd(a, b, -c.v);
+#endif
 }
 
 ICBC_FORCEINLINE VFloat vm2sub(VFloat a, VFloat b, VFloat c, VFloat d) {
@@ -1276,7 +1289,7 @@ ICBC_FORCEINLINE VFloat lane_id() {
 }
 
 ICBC_FORCEINLINE VFloat lane_id() {
-    return (VFloat){ 0, 1, 2, 3 };
+    return (vector float){ 0, 1, 2, 3 };
 }
 
 ICBC_FORCEINLINE VMask operator> (VFloat A, VFloat B) { return { vec_cmpgt(A, B) }; }
@@ -1291,6 +1304,23 @@ ICBC_FORCEINLINE VFloat vselect(VMask mask, VFloat a, 
 // mask ? b : a
 ICBC_FORCEINLINE VFloat vselect(VMask mask, VFloat a, VFloat b) {
     return vec_sel(a, b, mask);
+}
+
+ICBC_FORCEINLINE bool all(VMask mask) {
+    return vec_all_ne(mask.v, vec_splats(0u));
+}
+
+ICBC_FORCEINLINE bool any(VMask mask) {
+    return vec_any_ne(mask.v, vec_splats(0u));
+}
+
+ICBC_FORCEINLINE uint mask(VMask mask) {
+    const vector unsigned int movemask = { 1, 2, 4, 8 };
+    const vector unsigned int highbit = { 0x80000000, 0x80000000, 0x80000000, 0x80000000 };
+
+    vector unsigned int bits = vec_and(vec_cmpeq(vec_and(mask.v, highbit), highbit), movemask);
+
+    return bits[0] | bits[1] | bits[2] | bits[3];
 }
 
 ICBC_FORCEINLINE int reduce_min_index(VFloat v) {
