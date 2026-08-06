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
@@ -1245,7 +1249,7 @@ ICBC_FORCEINLINE VFloat vrcp(VFloat a) {
     vector float diff = vec_nmsub( estimate, v.vec, vec_splats( 1.0f ) );
     return vec_madd(diff, estimate, estimate );
 #else
-    return vec_div(vec_splats(1),a);
+    return vec_div(vec_splats(1.0f), a);
 #endif
 }
 
@@ -1276,7 +1280,7 @@ ICBC_FORCEINLINE VFloat lane_id() {
 }
 
 ICBC_FORCEINLINE VFloat lane_id() {
-    return (VFloat){ 0, 1, 2, 3 };
+    return (vector float){ 0, 1, 2, 3 };
 }
 
 ICBC_FORCEINLINE VMask operator> (VFloat A, VFloat B) { return { vec_cmpgt(A, B) }; }
@@ -1291,6 +1295,23 @@ ICBC_FORCEINLINE VFloat vselect(VMask mask, VFloat a, 
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
