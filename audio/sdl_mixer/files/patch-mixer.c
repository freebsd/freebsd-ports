
$FreeBSD$

--- mixer.c	2001/05/08 07:44:26	1.1
+++ mixer.c	2001/05/08 07:47:09
@@ -865,3 +865,18 @@
 	}
 	return(chan);
 }
+
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
