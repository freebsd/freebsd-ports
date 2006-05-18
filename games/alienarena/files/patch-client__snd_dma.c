--- ./client/snd_dma.c.orig	Tue May 16 15:20:10 2006
+++ ./client/snd_dma.c	Tue May 16 15:20:10 2006
@@ -771,8 +771,17 @@
 		clear = 0;
 
 	SNDDMA_BeginPainting ();
-	if (dma.buffer)
-		memset(dma.buffer, clear, dma.samples * dma.samplebits/8);
+	if (dma.buffer) {
+		int i;
+		unsigned char *ptr = (unsigned char *)dma.buffer;
+		
+		/* clear it manually because the buffer might be writeonly (mmap) */
+		i = dma.samples * dma.samplebits/8;
+		while (i--) {
+			*ptr = clear;
+			ptr++;
+		}
+	}
 	SNDDMA_Submit ();
 }
 
@@ -892,8 +901,23 @@
 		ch->rightvol = right_total;
 		ch->autosound = true;	// remove next frame
 		ch->sfx = sfx;
-		ch->pos = paintedtime % sc->length;
-		ch->end = paintedtime + sc->length - ch->pos;
+		/*
+		 * PATCH: eliasm
+		 *
+		 * Sometimes, the sc->length argument can become 0,
+		 * and in that case we get a SIGFPE in the next
+		 * modulo operation. The workaround checks for this
+		 * situation and in that case, sets the pos and end
+		 * parameters to 0.
+		 */
+		if( sc->length == 0 ) {
+			ch->pos = 0;
+			ch->end = 0;
+		}
+		else {
+			ch->pos = paintedtime % sc->length;
+			ch->end = paintedtime + sc->length - ch->pos;
+		}
 	}
 }
 
