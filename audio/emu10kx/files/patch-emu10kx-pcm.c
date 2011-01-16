--- emu10kx-pcm.c.orig	2011-01-16 20:06:25.000000000 +0100
+++ emu10kx-pcm.c	2011-01-16 20:10:06.000000000 +0100
@@ -977,7 +977,7 @@
 		break;
 	}
 	sc->rnum++;
-	if (sndbuf_alloc(ch->buffer, sc->card->parent_dmat, sc->card->bufsz) != 0)
+	if (sndbuf_alloc(ch->buffer, sc->card->parent_dmat, NULL, sc->card->bufsz) != 0)
 		return NULL;
 	else {
 		snd_mtxlock(sc->lock);
