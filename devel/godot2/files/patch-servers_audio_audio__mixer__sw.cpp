--- servers/audio/audio_mixer_sw.cpp.orig	2018-01-10 15:33:12 UTC
+++ servers/audio/audio_mixer_sw.cpp
@@ -280,7 +280,7 @@ void AudioMixerSW::mix_channel(Channel &
 		//stereo pan
 		float pan = c.pan * 0.5 + 0.5;
 		float panv[2] = {
-			(1.0 - pan) * (1 << MIX_VOL_FRAC_BITS),
+			(1.0f - pan) * (1 << MIX_VOL_FRAC_BITS),
 			(pan) * (1 << MIX_VOL_FRAC_BITS)
 		};
 
@@ -297,9 +297,9 @@ void AudioMixerSW::mix_channel(Channel &
 		float pany = c.depth * 0.5 + 0.5;
 		// with this model every speaker plays at 0.25 energy at the center.. i'm not sure if it's correct but it seems to be balanced
 		float panv[4] = {
-			(1.0 - pany) * (1.0 - panx) * (1 << MIX_VOL_FRAC_BITS),
-			(1.0 - pany) * (panx) * (1 << MIX_VOL_FRAC_BITS),
-			(pany) * (1.0 - panx) * (1 << MIX_VOL_FRAC_BITS),
+			(1.0f - pany) * (1.0f - panx) * (1 << MIX_VOL_FRAC_BITS),
+			(1.0f - pany) * (panx) * (1 << MIX_VOL_FRAC_BITS),
+			(pany) * (1.0f - panx) * (1 << MIX_VOL_FRAC_BITS),
 			(pany) * (panx) * (1 << MIX_VOL_FRAC_BITS)
 		};
 
