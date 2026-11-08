--- src/linesimulator.c.orig	2026-09-24 18:08:25 UTC
+++ src/linesimulator.c
@@ -13,6 +13,7 @@
 
 #define _POSIX_C_SOURCE 200809L
 
+#include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -118,10 +119,10 @@ parse_ranges(const char *s, struct range_list *rl)
 /* RNG: xorshift64                                                    */
 /* ------------------------------------------------------------------ */
 
-static unsigned long
-xorshift64(unsigned long *state)
+static uint64_t
+xorshift64(uint64_t *state)
 {
-    unsigned long x = *state;
+    uint64_t x = *state;
     if (x == 0)
         x = 0x9E3779B97F4A7C15UL;
     x ^= x << 13;
@@ -313,8 +314,8 @@ struct error_state {
 };
 
 struct error_state {
-    unsigned long rng;
-    unsigned long seed;
+    uint64_t rng;
+    uint64_t seed;
     int flip_bits;      /* max bits to flip per event (0=disabled) */
     int drop_bytes;     /* max bytes to drop per event (0=disabled) */
     int garble_bytes;   /* max bytes to garble per event (0=disabled) */
@@ -336,7 +337,7 @@ static void
 }
 
 static void
-es_seed(struct error_state *es, unsigned long seed)
+es_seed(struct error_state *es, uint64_t seed)
 {
     es->seed = seed;
     es->rng = seed;
@@ -350,7 +351,7 @@ es_schedule(struct error_state *es, enum err_type t)
     if (es->deterministic) {
         es->next_error[t] = es->byte_count + es->error_freq;
     } else {
-        unsigned long r = xorshift64(&es->rng);
+        uint64_t r = xorshift64(&es->rng);
         es->next_error[t] = es->byte_count + 1
             + (size_t)(r % (2 * es->error_freq));
     }
@@ -373,8 +374,8 @@ do_garble(struct error_state *es, unsigned char *buf, 
           size_t pos)
 {
     int maxn = es->garble_bytes;
-    unsigned long r = xorshift64(&es->rng);
-    int n = 1 + (int)(r % (unsigned long)maxn);
+    uint64_t r = xorshift64(&es->rng);
+    int n = 1 + (int)(r % (uint64_t)maxn);
     for (int i = 0; i < n && pos + i < buflen; i++)
         buf[pos + i] ^= 0xFF;
 }
@@ -385,10 +386,10 @@ do_flip(struct error_state *es, unsigned char *buf, si
         size_t pos)
 {
     int maxn = es->flip_bits;
-    unsigned long r = xorshift64(&es->rng);
-    int n = 1 + (int)(r % (unsigned long)maxn);
+    uint64_t r = xorshift64(&es->rng);
+    int n = 1 + (int)(r % (uint64_t)maxn);
     for (int i = 0; i < n; i++) {
-        unsigned long r2 = xorshift64(&es->rng);
+        uint64_t r2 = xorshift64(&es->rng);
         size_t byte_off = r2 % 8; /* spread within 8 bytes */
         if (byte_off >= buflen - pos)
             byte_off = 0; /* clamp to current position if near end */
@@ -468,9 +469,9 @@ apply_transform(struct error_state *es, unsigned char 
         }
         if (es->drop_bytes > 0
             && es->byte_count >= es->next_error[ERR_DROP]) {
-            unsigned long r = xorshift64(&es->rng);
+            uint64_t r = xorshift64(&es->rng);
             int maxn = es->drop_bytes;
-            int n = 1 + (int)(r % (unsigned long)maxn);
+            int n = 1 + (int)(r % (uint64_t)maxn);
             if ((size_t)n > len - pos)
                 n = (int)(len - pos);
             memmove(buf + pos, buf + pos + n, len - pos - n);
@@ -589,7 +590,7 @@ main(int argc, char **argv)
     char **sub_argv;
     enum rl_mode mode = RL_NONE;
     long rl_bps = 0;
-    unsigned long actual_seed;
+    uint64_t actual_seed;
     struct direction dir[2];
     int has_errors;
     int sub_stdin[2], sub_stdout[2];
@@ -658,18 +659,22 @@ main(int argc, char **argv)
     /* Seed RNG */
     if (seed >= 0) {
         /* Reproducible Number Generator */
-        actual_seed = (unsigned long)seed;
+        actual_seed = (uint64_t)seed;
     } else {
         /* Random Number Generator */
         FILE *urand = fopen("/dev/urandom", "rb");
         if (urand) {
             if (fread(&actual_seed, sizeof(actual_seed), 1, urand) != 1)
-                actual_seed = (unsigned long)time(NULL);
+                actual_seed = (uint64_t)time(NULL);
             fclose(urand);
         } else {
-            actual_seed = (unsigned long)time(NULL);
+            actual_seed = (uint64_t)time(NULL);
         }
+#if SIZE_MAX == UINT32_MAX
+        fprintf(stderr, "linesimulator: seed=%llu\n", actual_seed);
+#else
         fprintf(stderr, "linesimulator: seed=%lu\n", actual_seed);
+#endif
     }
 
     /* Directions: 0=stdin->SUB (tx), 1=SUB->stdout (rx) */
@@ -706,7 +711,7 @@ main(int argc, char **argv)
                 dir[d].es.error_freq = error_freq;
                 dir[d].es.deterministic = deterministic;
                 dir[d].es.ranges = err_ranges;
-                es_seed(&dir[d].es, actual_seed + (unsigned long)d);
+                es_seed(&dir[d].es, actual_seed + (uint64_t)d);
                 es_setup(&dir[d].es);
             }
         }
