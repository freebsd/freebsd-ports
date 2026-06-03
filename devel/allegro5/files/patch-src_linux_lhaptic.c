--- src/linux/lhaptic.c.orig	2025-07-15 04:53:14 UTC
+++ src/linux/lhaptic.c
@@ -21,6 +21,7 @@
 #endif
 
 #include <math.h>
+#include <stdint.h>
 #include <stdio.h>
 #include <sys/time.h>
 
@@ -223,7 +224,7 @@ static void lhap_exit_haptic(void)
 }
 
 
-static bool lhap_type2lin(__u16 *res, int type)
+static bool lhap_type2lin(uint16_t *res, int type)
 {
    ASSERT(res);
 
@@ -259,7 +260,7 @@ static bool lhap_type2lin(__u16 *res, int type)
 }
 
 
-static bool lhap_wave2lin(__u16 *res, int type)
+static bool lhap_wave2lin(uint16_t *res, int type)
 {
    ASSERT(res);
 
@@ -292,13 +293,13 @@ static bool lhap_wave2lin(__u16 *res, int type)
 /* Converts the time in seconds to a Linux-compatible time.
  * Return false if out of bounds.
  */
-static bool lhap_time2lin(__u16 *res, double sec)
+static bool lhap_time2lin(uint16_t *res, double sec)
 {
    ASSERT(res);
 
    if (sec < 0.0 || sec > 32.767)
       return false;
-   (*res) = (__u16) round(sec * 1000.0);
+   (*res) = (uint16_t) round(sec * 1000.0);
    return true;
 }
 
@@ -306,13 +307,13 @@ static bool lhap_time2lin(__u16 *res, double sec)
 /* Converts the time in seconds to a Linux-compatible time.
  * Return false if out of bounds. This one allows negative times.
  */
-static bool lhap_stime2lin(__s16 *res, double sec)
+static bool lhap_stime2lin(int16_t *res, double sec)
 {
    ASSERT(res);
 
    if (sec < -32.767 || sec > 32.767)
       return false;
-   (*res) = (__s16) round(sec * 1000.0);
+   (*res) = (int16_t) round(sec * 1000.0);
    return true;
 }
 
@@ -329,13 +330,13 @@ static bool lhap_replay2lin(struct ff_replay *lin,
 /* Converts the level in range 0.0 to 1.0 to a Linux-compatible level.
  * Returns false if out of bounds.
  */
-static bool lhap_level2lin(__u16 *res, double level)
+static bool lhap_level2lin(uint16_t *res, double level)
 {
    ASSERT(res);
 
    if (level < 0.0 || level > 1.0)
       return false;
-   *res = (__u16) round(level * (double)0x7fff);
+   *res = (uint16_t) round(level * (double)0x7fff);
    return true;
 }
 
@@ -343,13 +344,13 @@ static bool lhap_level2lin(__u16 *res, double level)
 /* Converts the level in range -1.0 to 1.0 to a Linux-compatible level.
  * Returns false if out of bounds.
  */
-static bool lhap_slevel2lin(__s16 *res, double level)
+static bool lhap_slevel2lin(int16_t *res, double level)
 {
    ASSERT(res);
 
    if (level < -1.0 || level > 1.0)
       return false;
-   *res = (__s16) round(level * (double)0x7ffe);
+   *res = (int16_t) round(level * (double)0x7ffe);
    return true;
 }
 
@@ -433,7 +434,7 @@ static bool lhap_effect2lin(struct ff_effect *lin, ALL
    if (!lhap_type2lin(&lin->type, al->type))
       return false;
    /* lin_effect->replay = effect->re; */
-   lin->direction = (__u16)
+   lin->direction = (uint16_t)
       round(((double)0xC000 * al->direction.angle) / (2 * M_PI));
    lin->id = -1;
    if (!lhap_replay2lin(&lin->replay, &al->replay))
@@ -638,7 +639,7 @@ static bool lhap_set_gain(ALLEGRO_HAPTIC *dev, double 
    lhap_timerclear(&ie);
    ie.type = EV_FF;
    ie.code = FF_GAIN;
-   ie.value = (__s32) ((double)0xFFFF * gain);
+   ie.value = (int32_t) ((double)0xFFFF * gain);
    if (write(lhap->fd, &ie, sizeof(ie)) < 0) {
       return false;
    }
@@ -655,7 +656,7 @@ static bool lhap_set_autocenter(ALLEGRO_HAPTIC *dev, d
    lhap_timerclear(&ie);
    ie.type = EV_FF;
    ie.code = FF_AUTOCENTER;
-   ie.value = (__s32) ((double)0xFFFF * autocenter);
+   ie.value = (int32_t) ((double)0xFFFF * autocenter);
    if (write(lhap->fd, &ie, sizeof(ie)) < 0) {
       return false;
    }
