--- sope-core/NGStreams/NGCTextStream.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGCTextStream.m
@@ -265,7 +265,7 @@ static void _flushAtExit(void) {
                  format:
                    @"called writeCharacter: with character code (0x%X)"
                    @" exceeding the maximum system character code (0x%X)",
-                   _character, ((sizeof(unsigned char) * 256) - 1)];
+                   _character, (int)((sizeof(unsigned char) * 256) - 1)];
   }
 
   c = _character;
