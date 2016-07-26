--- mixer.c.orig	2012-01-15 22:01:05 UTC
+++ mixer.c
@@ -1272,6 +1272,21 @@ int Mix_GroupOldest(int tag)
 	return(chan);
 }
 
+int Mix_GetMixerInfo(SDL_AudioSpec *m, char *namebuf, int maxlen)
+{
+    if (!audio_opened)
+        return -1;
+    if (m)
+        *m = mixer;             /* struct copy */
+    if (namebuf && maxlen > 0)
+    {
+        namebuf[0] = 0;
+        if (SDL_AudioDriverName(namebuf, maxlen) == NULL)
+            namebuf[0] = 0;
+    }
+    return 0;
+}
+
 /* Finds the "most recent" (i.e. last) sample playing in a group of channels */
 int Mix_GroupNewer(int tag)
 {
