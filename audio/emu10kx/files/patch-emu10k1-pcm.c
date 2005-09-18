--- emu10k1-pcm.c	Sat Apr 23 05:47:26 2005
+++ ../../emu10k1-pcm.c	Sun Aug 14 17:54:02 2005
@@ -135,7 +135,6 @@
                (sc->card->mixer->mix.volume[MIXER_P_VOLUME_RIGHT] == 0)) mute = 1;
             left = V100_TOBIT6(sc->card->mixer->mix.volume[MIXER_P_VOLUME_LEFT]);
             right = V100_TOBIT6(sc->card->mixer->mix.volume[MIXER_P_VOLUME_RIGHT]);
-            if(mute == 1) left = right = 0;
             emulated = AC97ENCODE(mute, left, right);
 #ifdef EMU_AC97DEBUG
             device_printf(sc->dev, "get MIX_MASTER: vol  %d:%d ac97 m=%d l=%x r=%x e=%08x\n",
@@ -150,7 +149,6 @@
                (sc->card->mixer->fxbuses[0].volume[MIXER_P_VOLUME_RIGHT] == 0)) mute = 1;
             left = V100_TOBIT6(sc->card->mixer->fxbuses[0].volume[MIXER_P_VOLUME_LEFT]);
             right = V100_TOBIT6(sc->card->mixer->fxbuses[0].volume[MIXER_P_VOLUME_RIGHT]);
-            if(mute == 1) left = right = 0;
             emulated = AC97ENCODE(mute, left, right);
 #ifdef EMU_AC97DEBUG
             device_printf(sc->dev, "get MIX_PCM: vol  %d:%d ac97 m=%d l=%x r=%x e=%08x\n",
@@ -169,7 +167,6 @@
                (sc->card->mixer->mix.volume[MIXER_R_VOLUME_RIGHT] == 0)) mute = 1;
             left = 0x0f - V100_TOBIT4(sc->card->mixer->mix.volume[MIXER_R_VOLUME_LEFT]);
             right = 0x0f - V100_TOBIT4(sc->card->mixer->mix.volume[MIXER_R_VOLUME_RIGHT]);
-            if(mute == 1) left = right = 0;
             emulated = AC97ENCODE(mute, left, right);
 #ifdef EMU_AC97DEBUG
             device_printf(sc->dev, "get MIX_RGAIN: vol  %d:%d ac97 m=%d l=%x r=%x\n e=%08x",
