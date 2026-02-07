--- src/DoublePinyinTable.h.orig	2019-09-09 19:30:30 UTC
+++ src/DoublePinyinTable.h
@@ -26,7 +26,7 @@
 
 #define PINYIN_ID_AEO PINYIN_ID_ZERO
 
-static const char double_pinyin_mspy_sheng[] = {
+static const signed char double_pinyin_mspy_sheng[] = {
     PINYIN_ID_AEO,  // A
     PINYIN_ID_B,    // B
     PINYIN_ID_C,    // C
@@ -55,7 +55,7 @@ static const char double_pinyin_mspy_sheng[] = {
     PINYIN_ID_Z,    // Z
     PINYIN_ID_VOID, // ;
 };
-static const char double_pinyin_mspy_yun[][2] = {
+static const signed char double_pinyin_mspy_yun[][2] = {
     { PINYIN_ID_A,    PINYIN_ID_VOID }, // A
     { PINYIN_ID_OU,   PINYIN_ID_VOID }, // B
     { PINYIN_ID_IAO,  PINYIN_ID_VOID }, // C
@@ -84,7 +84,7 @@ static const char double_pinyin_mspy_yun[][2] = {
     { PINYIN_ID_EI,   PINYIN_ID_VOID }, // Z
     { PINYIN_ID_ING,  PINYIN_ID_VOID }, // ;
 };
-static const char double_pinyin_zrm_sheng[] = {
+static const signed char double_pinyin_zrm_sheng[] = {
     PINYIN_ID_AEO,  // A
     PINYIN_ID_B,    // B
     PINYIN_ID_C,    // C
@@ -113,7 +113,7 @@ static const char double_pinyin_zrm_sheng[] = {
     PINYIN_ID_Z,    // Z
     PINYIN_ID_VOID, // ;
 };
-static const char double_pinyin_zrm_yun[][2] = {
+static const signed char double_pinyin_zrm_yun[][2] = {
     { PINYIN_ID_A,    PINYIN_ID_VOID }, // A
     { PINYIN_ID_OU,   PINYIN_ID_VOID }, // B
     { PINYIN_ID_IAO,  PINYIN_ID_VOID }, // C
@@ -142,7 +142,7 @@ static const char double_pinyin_zrm_yun[][2] = {
     { PINYIN_ID_EI,   PINYIN_ID_VOID }, // Z
     { PINYIN_ID_VOID, PINYIN_ID_VOID }, // ;
 };
-static const char double_pinyin_abc_sheng[] = {
+static const signed char double_pinyin_abc_sheng[] = {
     PINYIN_ID_ZH,   // A
     PINYIN_ID_B,    // B
     PINYIN_ID_C,    // C
@@ -171,7 +171,7 @@ static const char double_pinyin_abc_sheng[] = {
     PINYIN_ID_Z,    // Z
     PINYIN_ID_VOID, // ;
 };
-static const char double_pinyin_abc_yun[][2] = {
+static const signed char double_pinyin_abc_yun[][2] = {
     { PINYIN_ID_A,    PINYIN_ID_VOID }, // A
     { PINYIN_ID_OU,   PINYIN_ID_VOID }, // B
     { PINYIN_ID_IN,   PINYIN_ID_UAI  }, // C
@@ -200,7 +200,7 @@ static const char double_pinyin_abc_yun[][2] = {
     { PINYIN_ID_IAO,  PINYIN_ID_VOID }, // Z
     { PINYIN_ID_VOID, PINYIN_ID_VOID }, // ;
 };
-static const char double_pinyin_zgpy_sheng[] = {
+static const signed char double_pinyin_zgpy_sheng[] = {
     PINYIN_ID_CH,   // A
     PINYIN_ID_B,    // B
     PINYIN_ID_C,    // C
@@ -229,7 +229,7 @@ static const char double_pinyin_zgpy_sheng[] = {
     PINYIN_ID_Z,    // Z
     PINYIN_ID_VOID, // ;
 };
-static const char double_pinyin_zgpy_yun[][2] = {
+static const signed char double_pinyin_zgpy_yun[][2] = {
     { PINYIN_ID_A,    PINYIN_ID_VOID }, // A
     { PINYIN_ID_IAO,  PINYIN_ID_VOID }, // B
     { PINYIN_ID_VOID, PINYIN_ID_VOID }, // C
@@ -258,7 +258,7 @@ static const char double_pinyin_zgpy_yun[][2] = {
     { PINYIN_ID_OU,   PINYIN_ID_VOID }, // Z
     { PINYIN_ID_ING,  PINYIN_ID_VOID }, // ;
 };
-static const char double_pinyin_pyjj_sheng[] = {
+static const signed char double_pinyin_pyjj_sheng[] = {
     PINYIN_ID_ZERO, // A
     PINYIN_ID_B,    // B
     PINYIN_ID_C,    // C
@@ -287,7 +287,7 @@ static const char double_pinyin_pyjj_sheng[] = {
     PINYIN_ID_Z,    // Z
     PINYIN_ID_VOID, // ;
 };
-static const char double_pinyin_pyjj_yun[][2] = {
+static const signed char double_pinyin_pyjj_yun[][2] = {
     { PINYIN_ID_A,    PINYIN_ID_VOID }, // A
     { PINYIN_ID_IA,   PINYIN_ID_UA   }, // B
     { PINYIN_ID_UAN,  PINYIN_ID_VOID }, // C
@@ -316,7 +316,7 @@ static const char double_pinyin_pyjj_yun[][2] = {
     { PINYIN_ID_UN,   PINYIN_ID_VOID }, // Z
     { PINYIN_ID_VOID, PINYIN_ID_VOID }, // ;
 };
-static const char double_pinyin_xhe_sheng[] = {
+static const signed char double_pinyin_xhe_sheng[] = {
     PINYIN_ID_AEO,  // A
     PINYIN_ID_B,    // B
     PINYIN_ID_C,    // C
@@ -345,7 +345,7 @@ static const char double_pinyin_xhe_sheng[] = {
     PINYIN_ID_Z,    // Z
     PINYIN_ID_VOID, // ;
 };
-static const char double_pinyin_xhe_yun[][2] = {
+static const signed char double_pinyin_xhe_yun[][2] = {
     { PINYIN_ID_A,    PINYIN_ID_VOID }, // A
     { PINYIN_ID_IN,   PINYIN_ID_VOID }, // B
     { PINYIN_ID_AO,   PINYIN_ID_VOID }, // C
@@ -376,8 +376,8 @@ static const char double_pinyin_xhe_yun[][2] = {
 };
 
 static const struct {
-    const char  (&sheng)[27];
-    const char  (&yun)[27][2];
+    const signed char  (&sheng)[27];
+    const signed char  (&yun)[27][2];
 } double_pinyin_map [] = {
     { double_pinyin_mspy_sheng, double_pinyin_mspy_yun },
     { double_pinyin_zrm_sheng,  double_pinyin_zrm_yun  },
