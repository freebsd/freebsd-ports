--- include/hamlib/rig.h.orig	2021-12-03 00:09:30 UTC
+++ include/hamlib/rig.h
@@ -1124,8 +1124,8 @@ typedef uint64_t setting_t;
 #define RIG_FUNC_TRANSCEIVE CONSTANT_64BIT_FLAG (42)   /*!< \c TRANSCEIVE -- Send radio state changes automatically ON/OFF */
 #define RIG_FUNC_SPECTRUM   CONSTANT_64BIT_FLAG (43)   /*!< \c SPECTRUM -- Spectrum scope data output ON/OFF */
 #define RIG_FUNC_SPECTRUM_HOLD CONSTANT_64BIT_FLAG (44)   /*!< \c SPECTRUM_HOLD -- Pause spectrum scope updates ON/OFF */
-#define RIG_FUNC_BIT45      CONSTANT_64BIT_FLAG (45)   /*!< \c available for future RIG_FUNC items */
-#define RIG_FUNC_BIT46      CONSTANT_64BIT_FLAG (46)   /*!< \c available for future RIG_FUNC items */
+#define RIG_FUNC_SEND_MORSE CONSTANT_64BIT_FLAG (45)   /*!< \c SEND_MORSE -- Send specified characters using CW */
+#define RIG_FUNC_SEND_VOICE_MEM CONSTANT_64BIT_FLAG (46)   /*!< \c SEND_VOICE_MEM -- Transmit in SSB message stored in memory */
 #define RIG_FUNC_BIT47      CONSTANT_64BIT_FLAG (47)   /*!< \c available for future RIG_FUNC items */
 #define RIG_FUNC_BIT48      CONSTANT_64BIT_FLAG (48)   /*!< \c available for future RIG_FUNC items */
 #define RIG_FUNC_BIT49      CONSTANT_64BIT_FLAG (49)   /*!< \c available for future RIG_FUNC items */
@@ -2063,6 +2063,7 @@ enum rig_function_e {
     RIG_FUNCTION_SEND_MORSE,
     RIG_FUNCTION_STOP_MORSE,
     RIG_FUNCTION_WAIT_MORSE,
+    RIG_FUNCTION_SEND_VOICE_MEM,
     RIG_FUNCTION_SET_BANK,
     RIG_FUNCTION_SET_MEM,
     RIG_FUNCTION_GET_MEM,
