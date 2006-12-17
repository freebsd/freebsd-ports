--- ./include/QF/sound.h.orig	Tue Jan 20 23:52:07 2004
+++ ./include/QF/sound.h	Sun Dec 17 15:50:06 2006
@@ -112,31 +112,14 @@
 // number of times S_Update() is called per second.
 //
 
-extern qboolean 		fakedma;
 extern int 			fakedma_updates;
 extern unsigned paintedtime;
-extern unsigned soundtime;
-extern vec3_t listener_origin;
-extern vec3_t listener_forward;
-extern vec3_t listener_right;
-extern vec3_t listener_up;
-extern vec_t sound_nominal_clip_dist;
 
 extern	struct cvar_s *snd_loadas8bit;
-extern	struct cvar_s *bgmvolume;
 extern	struct cvar_s *volume;
 
-extern	struct cvar_s *snd_mixahead;
-extern	struct cvar_s	*snd_device;
-extern	struct cvar_s	*snd_rate;
-extern	struct cvar_s	*snd_bits;
-extern	struct cvar_s	*snd_stereo;
 extern	struct cvar_s	*snd_interp;
 extern	struct cvar_s *snd_stereo_phase_separation;
-
-extern qboolean	snd_initialized;
-
-extern int		snd_blocked;
 
 void S_LocalSound (const char *s);
 
