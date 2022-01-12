--- src/misc.c.orig	2021-12-03 00:09:30 UTC
+++ src/misc.c
@@ -884,6 +884,8 @@ static const struct
     { RIG_LEVEL_SPECTRUM_AVG, "SPECTRUM_AVG" },
     { RIG_LEVEL_SPECTRUM_ATT, "SPECTRUM_ATT" },
     { RIG_LEVEL_TEMP_METER, "TEMP_METER" },
+    { RIG_FUNC_SEND_MORSE, "SEND_MORSE" },
+    { RIG_FUNC_SEND_VOICE_MEM, "SEND_VOICE_MEM" },
     { RIG_LEVEL_NONE, "" },
 };
 
@@ -2254,6 +2256,9 @@ void *HAMLIB_API rig_get_function_ptr(rig_model_t rig_
 
     case RIG_FUNCTION_WAIT_MORSE:
         return caps->wait_morse;
+
+    case RIG_FUNCTION_SEND_VOICE_MEM:
+        return caps->send_voice_mem;
 
     case RIG_FUNCTION_SET_BANK:
         return caps->set_bank;
